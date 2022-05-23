#pragma once

#include <vector>
#include <cstdint>

class Graph {
private:
    size_t size; // Количество вершин
    std::vector <std::vector <size_t>> madjacencies_matrix; // Матрица смежности
public:
    explicit Graph(size_t size); // Конструктор
    void AddEdge(size_t from, size_t to, size_t length); // Добавление ребра
    size_t Size() const; // Размер матрицы смежности
    std::vector<size_t> GetEdgesFrom(size_t from) const; // Возвращение списка смежности вершины
};