#pragma once

#include <string>
#include "vector"
#include "Graph.h"

std::vector <size_t> prefix_function(const std::string &str){ // Префикс функция строки
    std::vector<size_t> prefix (str.size(), 0);
    for (size_t i = 1; i < str.size(); i++) {
        int j = prefix[i - 1];
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

size_t overlap(const std::string &s_1, const std::string &s_2) { // Overlap функций
    std::string general_string = s_2 + s_1;
    std::vector <size_t> prefix = prefix_function(general_string);
    return prefix[prefix.size() - 1];
}

std::vector <std::vector <size_t>> MinCycles(std::vector <size_t> &assigment){ // Покрытие циклами
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

std::string prefix(std::string s1, int delta) // Обрезает входную строку на overlap(s1, s2)
{
    return s1.substr(0, s1.length() - delta);
}

std::vector <std::string> MinOverlap(std::vector <std::vector <size_t>> &cycles, Graph &matrix, std::vector<std::string> strings_vector) { // Минимизация overlap первой и последней строки в цикле
    std::vector<std::string> super_strings(cycles.size());
    for (auto j: cycles) {
        std::string str = "";
        std::vector<size_t> ovs(j.size() - 1);
        for (int i = 0; i < j.size() - 1; i++) {
            ovs.push_back(matrix.GetEdgesFrom(j[i])[j[i + 1]]);
        }
        int min = matrix.GetEdgesFrom(j[j.size() - 1])[j[0]];
        int shift = 0;
        for (int i = 0; i < ovs.size(); i++)
            if (ovs[i] < min) {
                min = ovs[i];
                shift = i + 1;
            }
        std::vector<size_t> help(j.size());
        for (int i = 0; i < j.size(); i++) {
            help[(i + shift) % j.size()] = j[i];
        }
        j = help;
        for (int i = 0; i < j.size() - 1; i++) {
            str += prefix(strings_vector[j[i]], matrix.GetEdgesFrom(j[i])[j[i + 1]]);
        }
        str += strings_vector[j[j.size() - 1]];
        super_strings.push_back(str);
    }
    return super_strings;
}

std::string SplitString(const std::vector <std::string> &super_string){ // Конкатенация всех надстрок из superstrings
    std::string answer = "";
    for (auto str : super_string){
        answer += str;
    }
    return answer;
}

