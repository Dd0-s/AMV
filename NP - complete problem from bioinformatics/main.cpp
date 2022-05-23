#include <iostream>
#include "Graph.h"
#include "Functions.h"

int main() { // cde abc eab fgh ghf hed

    // Считываем входные строки
    int number;
    std::cin >> number;
    std::vector<std::string> strings_vector(number);
    for (size_t i = 0; i < number; ++i) {
        std::cin >> strings_vector[i];
    }

    // Заполняем матрицу смежности
    Graph adjacencies(number);
    for (size_t i = 0; i < number; i++) {
        for (size_t j = 0; j < number; j++) {
            if (i == j) {
                adjacencies.AddEdge(i, j, 0);
            } else {
                adjacencies.AddEdge(i, j, overlap(strings_vector[i], strings_vector[j]));
            }
        }
    }

    // Вычисляем полное назначение
    std::vector <size_t> assigment = GreedyAssignment(adjacencies);

    // Покрытие циклами
    std::vector <std::vector <size_t>> cycles = MinCycles(assigment);

    // Минимизация overlap первой и последней строки в цикле
    std::vector <std::string> super_strings = MinOverlap(cycles, adjacencies, strings_vector);

    // Конкатенация всех подстрок
    std::cout << SplitString(super_strings) << std::endl;
}