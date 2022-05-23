#include "Graph.h"
#include "Functions.h"
#include "gtest/gtest.h"

TEST(graph, AddEdge){
    Graph test_graph(4);
    for (size_t i = 0; i < 4; i++){
        test_graph.AddEdge((i + 1) % 4, i, 2 * i + 1);
        ASSERT_EQ(test_graph.GetEdgesFrom((i + 1) % 4)[i], 2 * i + 1);
    }
}

TEST(graph, Size){
    Graph test_graph(4);
    ASSERT_EQ(test_graph.Size(), 4);

    test_graph =  Graph(0);
    ASSERT_EQ(test_graph.Size(), 0);

    test_graph = Graph(1001);
    ASSERT_EQ(test_graph.Size(), 1001);
}

TEST(graph, GetEdgesFrom){
    Graph test_graph(4);
    test_graph.AddEdge(0,1,1);
    test_graph.AddEdge(0,3,1);
    test_graph.AddEdge(0,3,3);
    test_graph.AddEdge(3,1,2);
    ASSERT_EQ(test_graph.GetEdgesFrom(0), std::vector <size_t>({0,1,0,3}));
}

TEST(Functions, PrefixFunction){
    std::string s_1 = "abcabcd", s_2 = "aabaaab";
    ASSERT_EQ(PrefixFunction(s_1), std::vector<size_t>({0,0,0,1,2,3,0}));
    ASSERT_EQ(PrefixFunction(s_2), std::vector<size_t>({0,1,0,1,2,2,3}));
}

TEST(Functions, Overlap){
    std::string s_0 = "cde", s_1 = "abc", s_2 = "eab";
    ASSERT_EQ(Overlap(s_0,s_1), 0);
    ASSERT_EQ(Overlap(s_0,s_2), 1);
    ASSERT_EQ(Overlap(s_1,s_0), 1);
    ASSERT_EQ(Overlap(s_1,s_2), 0);
    ASSERT_EQ(Overlap(s_2,s_0), 0);
    ASSERT_EQ(Overlap(s_2,s_1), 2);
}

TEST(Functions, GreedyAssignment){
    Graph test_graph (6);
    test_graph.AddEdge(0,2,1);
    test_graph.AddEdge(1,0,1);
    test_graph.AddEdge(2,1,2);
    test_graph.AddEdge(3,4,2);
    test_graph.AddEdge(3,5,1);
    test_graph.AddEdge(4,3,1);
    ASSERT_EQ(GreedyAssignment(test_graph), std::vector <size_t> ({2, 0, 1, 4, 3, 5}));
}

TEST(Functions, MinCycles){
    std::vector <size_t> test_vector = {2, 0, 1, 4, 3, 5};
    ASSERT_EQ(MinCycles(test_vector)[0], std::vector <size_t> ({0, 2, 1}));
    ASSERT_EQ(MinCycles(test_vector)[1], std::vector <size_t> ({3, 4}));
    ASSERT_EQ(MinCycles(test_vector)[2], std::vector <size_t> ({5}));
}

TEST(Functions, Prefix){
    std::string s_1 = "googletest", s_2 = "mipt";
    ASSERT_EQ(Prefix(s_1, 4), "google");
    ASSERT_EQ(Prefix(s_2, 0), "mipt");
}

TEST(Functions, MinOverlap){
    std::vector <std::vector <size_t>> test_vector;
    std::vector <size_t> test_vector1 = {0, 2, 1};
    test_vector.push_back(test_vector1);
    std::vector <size_t> test_vector2 = {3, 4};
    test_vector.push_back(test_vector2);
    std::vector <size_t> test_vector3 = {5};
    test_vector.push_back(test_vector3);
    Graph test_graph (6);
    test_graph.AddEdge(0,2,1);
    test_graph.AddEdge(1,0,1);
    test_graph.AddEdge(2,1,2);
    test_graph.AddEdge(3,4,2);
    test_graph.AddEdge(3,5,1);
    test_graph.AddEdge(4,3,1);
    std::vector <std::string> test_string = {"cde", "abc", "eab", "fgh", "ghf", "hed"};
    ASSERT_EQ(MinOverlap(test_vector, test_graph, test_string),std::vector <std::string> ( {"cdeabc", "fghf", "hed"}));
}

TEST(Functions, SplitString){
    std::vector <std::string> str = {"abc", "dfg", "gfh"};
    ASSERT_EQ(SplitString(str), "abcdfggfh");
}