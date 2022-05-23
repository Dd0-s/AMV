#pragma once

#include <string>
#include <vector>

std::vector <size_t> PrefixFunction(const std::string &str); // Префикс функция строки

size_t Overlap(const std::string &s1, const std::string &s2);  // Overlap двух строк

std::vector <size_t> GreedyAssignment(const Graph &graph_adjacencies); // Вычисления полного назначения жадным методом

std::vector <std::vector <size_t>> MinCycles(std::vector <size_t> &assigment); // Покрытие циклами минимальной длины

std::string Prefix(std::string &s1, size_t delta); // Обрезает входную строку на delta = overlap(s1, s2)

std::vector <std::string> MinOverlap(std::vector <std::vector <size_t>> &cycles, Graph &graph_adjacencies, std::vector<std::string> &strings_vector); // Минимизация overlap первой и последней строки в цикле

std::string SplitString(const std::vector <std::string> &vector_string_cycle); // Конкатенация строк вектор