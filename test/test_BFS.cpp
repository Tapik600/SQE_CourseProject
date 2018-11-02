#include <iostream>
#include "gtest/gtest.h"
#include "BFS.h"

BFS test_BFS;
BFS::graph TestG = {
        {6,9},      //0
        {2},        //1
        {5,7},      //2
        {},         //3
        {5,6},      //4
        {2,4,7,8},  //5
        {0,4,8},    //6
        {2,5,9},    //7
        {5,6},      //8
        {0,7}       //9
};

TEST(test_BFS, WayFound) {
    std::vector<int> result1 = {4,5,2,1};
    std::vector<int> result2 = {0,9,7,2,1};
    std::vector<int> result3 = {8,5,4};

    EXPECT_EQ(test_BFS.breadth_first_search(TestG, 1, 4), result1);
    EXPECT_EQ(test_BFS.breadth_first_search(TestG, 1, 0), result2);
    EXPECT_EQ(test_BFS.breadth_first_search(TestG, 4, 8), result3);
}

TEST(test_BFS, WayNotFound) {
    std::vector<int> result1 = {3,-1};
    std::vector<int> result2 = {9,-1};
    std::vector<int> result3 = {5,-1};

    EXPECT_EQ(test_BFS.breadth_first_search(TestG, 6, 3), result1);
    EXPECT_EQ(test_BFS.breadth_first_search(TestG, 3, 9), result2);
    EXPECT_EQ(test_BFS.breadth_first_search(TestG, 5, 5), result3);
}

TEST(test_BFS, Node_more_GraphSize) {
    std::vector<int> result = {-1};

    EXPECT_EQ(test_BFS.breadth_first_search(TestG, 50, 4), result);
    EXPECT_EQ(test_BFS.breadth_first_search(TestG, 1, 40), result);
}

TEST(test_BFS, GraphSize_0) {
    BFS::graph TestG0;
    std::vector<int> result = {-1};

    EXPECT_EQ(test_BFS.breadth_first_search(TestG0, 4, 8), result);
}