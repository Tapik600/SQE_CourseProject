#include <iostream>
#include "gtest/gtest.h"
#include "Dijkstra.h"

Dijkstra test_Dijkstra;
Dijkstra::graph TestG = {
        [0][0] = 0, [0][1] = 0, [0][2] = 0, [0][3] = 1, [0][4] = 1, [0][5] = 1,
        [1][0] = 0, [1][1] = 0, [1][2] = 0, [1][3] = 1, [1][4] = 1, [1][5] = 0,
        [2][0] = 0, [2][1] = 1, [2][2] = 0, [2][3] = 0, [2][4] = 1, [2][5] = 0,
        [3][0] = 0, [3][1] = 0, [3][2] = 0, [3][3] = 0, [3][4] = 1, [3][5] = 0,
        [4][0] = 0, [4][1] = 0, [4][2] = 1, [4][3] = 0, [4][4] = 0, [4][5] = 1,
        [5][0] = 0, [5][1] = 0, [5][2] = 0, [5][3] = 1, [5][4] = 0, [5][5] = 0,
};

TEST(test_Dijkstra, WayFound) {
    std::vector<int> result1 = {0,3,4,2};
    std::vector<int> result2 = {5,3,4,2,1};
    std::vector<int> result3 = {0,3};

    EXPECT_EQ(test_Dijkstra.Dijkstra_search(TestG, 0, 2), result1);
    EXPECT_EQ(test_Dijkstra.Dijkstra_search(TestG, 5, 1), result2);
    EXPECT_EQ(test_Dijkstra.Dijkstra_search(TestG, 0, 3), result3);
}

TEST(test_Dijkstra, WayNotFound) {
    std::vector<int> result1 = {-1};
    std::vector<int> result2 = {-1};
    std::vector<int> result3 = {-1};

    EXPECT_EQ(test_Dijkstra.Dijkstra_search(TestG, 2, 0), result1);
    EXPECT_EQ(test_Dijkstra.Dijkstra_search(TestG, 3, 0), result2);
    EXPECT_EQ(test_Dijkstra.Dijkstra_search(TestG, 5, 0), result3);
}

TEST(test_Dijkstra, Node_more_GraphSize) {
    std::vector<int> result = {-1};

    EXPECT_EQ(test_Dijkstra.Dijkstra_search(TestG, 50, 4), result);
    EXPECT_EQ(test_Dijkstra.Dijkstra_search(TestG, 1, 40), result);
}

TEST(test_Dijkstra, GraphSize_0) {
    Dijkstra::graph TestG0;
    std::vector<int> result = {-1};

    EXPECT_EQ(test_Dijkstra.Dijkstra_search(TestG0, 4, 5), result);
}