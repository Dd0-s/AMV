#pragma once

#include <string>
#include "vector"
#include "Graph.h"

std::vector <size_t> PrefixFunction(const std::string &str){ // Префикс функция строки
    std::vector<size_t> prefix (str.size(), 0);
    for (size_t i = 1; i < str.size(); i++) {
        size_t j = prefix[i - 1];
        while (j > 0 && str[i] != str[j]){
            j = prefix[j - 1];
        }
        if (str[i] == str[j]){
            j++;
        }
        prefix[i] = j;
    }
    return prefix;
}

size_t Overlap(const std::string &s1, const std::string &s2) { // Overlap двух строк
    std::string general_string = s2 + s1;
    std::vector <size_t> prefix = PrefixFunction(general_string);
    return prefix[prefix.size() - 1];
}

std::vector <size_t> GreedyAssignment(const Graph &graph_adjacencies){ // Вычисления полного назначения жадным методом
    size_t size_matrix = graph_adjacencies.Size();
    std::vector <std::vector <bool>> not_allow (size_matrix, std::vector <bool> (size_matrix, false)) ;
    std::vector <size_t> assignment (size_matrix,0);
    while (true)
    {
        int max = -1;
        size_t max_i = 0, max_j = 0;
        bool flag = false;
        for (size_t i = 0; i < size_matrix; i++)
        {
            for (size_t j = 0; j < size_matrix; j++)
            {
                if (not_allow[i][j]){
                    continue;
                }
                if (static_cast <int>(graph_adjacencies.GetEdgesFrom(i)[j]) >= max)
                {
                    if (!flag){
                        max = static_cast <int> (graph_adjacencies.GetEdgesFrom(i)[j]);
                        max_i = i;
                        max_j = j;
                    }
                    if(assignment[j] == 0){
                        max = static_cast <int> (graph_adjacencies.GetEdgesFrom(i)[j]);
                        max_i = i;
                        max_j = j;
                        flag = true;
                    }
                }
            }
        }
        if (max == -1){
            break;
        }
        assignment[max_i] = max_j;
        for (size_t i = 0; i < size_matrix; i++)
        {
            not_allow[max_i][i] = true;
            not_allow[i][max_j] = true;
        }
    }
    return assignment;
}

std::vector <std::vector <size_t>> MinCycles(std::vector <size_t> &assigment){ // Покрытие циклами минимальной длины
    std::vector <std::vector <size_t>> cycles;
    std::vector <size_t> cycle;
    std::vector <bool> mark (assigment.size(), false);
    for (size_t i = 0; i < assigment.size(); i++)
    {
        if (mark[i]) {
            continue;
        }
        cycle.push_back(i);
        mark[i] = true;
        if (assigment[i] == cycle[0])
        {
            cycles.push_back(cycle);
            cycle.clear();
            i = 0;
        }else{
            i = assigment[i] - 1;
        }
    }
    return cycles;
}

std::string Prefix(std::string &s1, size_t delta) // Обрезает входную строку на delta = overlap(s1, s2)
{
    return s1.substr(0, s1.length() - delta);
}

std::vector <std::string> MinOverlap(std::vector <std::vector <size_t>> &cycles, Graph &graph_adjacencies, std::vector<std::string> &strings_vector) { // Минимизация overlap первой и последней строки в цикле
    std::vector <std::string> vector_string_cycle;
    for (auto j: cycles) {
        std::string string_cycle;
        std::vector <size_t> cycle_overlap;
        for (size_t i = 0; i < j.size() - 1; i++) {
            cycle_overlap.push_back(graph_adjacencies.GetEdgesFrom(j[i])[j[i + 1]]);
        }
        size_t min = graph_adjacencies.GetEdgesFrom(j[j.size() - 1])[j[0]];
        size_t shift = 0;
        for (size_t i = 0; i < cycle_overlap.size(); i++)
            if (cycle_overlap[i] < min) {
                min = cycle_overlap[i];
                shift = i + 1;
            }
        std::vector <size_t> vector_shift(j.size());
        for (size_t i = 0; i < j.size(); i++) {
            vector_shift[(i + shift) % j.size()] = j[i];
        }
        j = vector_shift;
        for (size_t i = 0; i < j.size() - 1; i++) {
            string_cycle += Prefix(strings_vector[j[i]], graph_adjacencies.GetEdgesFrom(j[i])[j[i + 1]]);
        }
        string_cycle += strings_vector[j[j.size() - 1]];
        vector_string_cycle.push_back(string_cycle);
    }
    return vector_string_cycle;
}

std::string SplitString(const std::vector <std::string> &vector_string_cycle){ // Конкатенация строк вектор
    std::string result;
    for (const auto& str : vector_string_cycle){
        result += str;
    }
    return result;
}

