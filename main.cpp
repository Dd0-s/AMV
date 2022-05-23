#include <iostream>
#include "Graph.h"
#include "Functions.h"

int main() {

    // Считываем входные строки
    size_t number;
    std::cin >> number;
    std::vector <std::string> strings_vector(number);
    for (size_t i = 0; i < number; ++i) {
        std::cin >> strings_vector[i];
    }

    // Отсчет времени
    auto start = std::chrono::steady_clock::now();

    // Заполняем матрицу смежности
    Graph graph_adjacencies(number);
    for (size_t i = 0; i < number; i++) {
        for (size_t j = 0; j < number; j++) {
            if (i == j) {
                graph_adjacencies.AddEdge(i, j, 0);
            } else {
                graph_adjacencies.AddEdge(i, j, Overlap(strings_vector[i], strings_vector[j]));
            }
        }
    }

    // Вычисляем полное назначение жадным методом
    std::vector <size_t> assigment = GreedyAssignment(graph_adjacencies);

    // Покрытие циклами минимальной длины
    std::vector <std::vector <size_t>> cycles = MinCycles(assigment);

    // Минимизация overlap первой и последней строки в цикле
    std::vector <std::string> vector_string_cycle = MinOverlap(cycles, graph_adjacencies, strings_vector);

    // Конкатенация всех подстрок
    std::cout << SplitString(vector_string_cycle) << std::endl;

    // Время работы
    auto finish = std::chrono::steady_clock::now();
    auto time = finish - start;
    std::cout << std::chrono::duration_cast <std::chrono::milliseconds>(time).count() << std::endl;
}