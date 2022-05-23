#pragma once

#include "Graph.h"

Graph::Graph(size_t size_){ // Конструктор
    size = size_;
    madjacencies_matrix = std::vector <std::vector <std::size_t>> (size_, std::vector <std::size_t> (size_, 0));
}

size_t Graph::Size() const{ // Размер матрицы смежности
    return size;
}

void Graph::AddEdge(size_t from, size_t to, size_t length){ // Добавление ребра
    madjacencies_matrix[from][to] = length;
}

std::vector<size_t> Graph::GetEdgesFrom(size_t from) const{ // Возвращение списка смежности вершины
    return madjacencies_matrix[from];
}