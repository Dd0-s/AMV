#pragma once

#include <string>
#include <vector>

std::vector <size_t> prefix_function(const std::string &str); // Префикс функция строки

size_t overlap(const std::string &s_1, const std::string &s_2);  // Overlap функций

std::vector <std::vector <size_t>> MinCycles(std::vector <size_t> &assigment); // Покрытие циклами

std::string prefix(std::string s1, int delta); // Обрезает входную строку на overlap(s1, s2)

std::vector <std::string> MinOverlap(std::vector <std::vector <size_t>> &cycles, Graph &matrix, std::vector<std::string> strings_vector); // Минимизация overlap первой и последней строки в цикле

std::string SplitString(const std::vector <std::string> &super_string); // Конкатенация всех надстрок из superstrings