#pragma once
#include "Graph.h"
#include <iostream>
Graph::Graph(size_t size_){ // Конструктор
    size = size_;
    madjacencies_matrix = std::vector <std::vector <std::size_t>> (size_, std::vector <std::size_t> (size_, 0));
}

size_t Graph::Size() const{
    return size;
}

void Graph::AddEdge(size_t from, size_t to, size_t length){ // Добавление ребра
    madjacencies_matrix[from][to] = length;
}

std::vector<size_t> Graph::GetEdgesFrom(size_t from) const{ // Возвращение списка смежности вершины
    return madjacencies_matrix[from];
}

std::vector <size_t> GreedyAssignment(const Graph &matrix){ // Вычисления полного назначения
    size_t size_graph = matrix.Size();
    std::vector <std::vector <bool>> not_allow (size_graph, std::vector <bool> (size_graph, false)) ;
    std::vector <size_t> assignment (size_graph,0);
    while (true)
    {
        int max = -1;
        size_t max_i = 0, max_j = 0;
        bool flag = false;
        for (size_t i = 0; i < size_graph; i++)
        {
            for (size_t j = 0; j < size_graph; j++)
            {
                if (not_allow[i][j]){
                    continue;
                }
                if (static_cast <int>(matrix.GetEdgesFrom(i)[j]) >= max)
                {
                    if (!flag){
                        max = matrix.GetEdgesFrom(i)[j];
                        max_i = i;
                        max_j = j;
                    }
                    if(assignment[j] == 0){
                        max = matrix.GetEdgesFrom(i)[j];
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
        for (size_t i = 0; i < size_graph; i++)
        {
            not_allow[max_i][i] = true;
            not_allow[i][max_j] = true;
        }
    }
    return assignment;
}