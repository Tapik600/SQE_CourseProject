#ifndef SQE_COURSEPROJECT_2018_BFS_H
#define SQE_COURSEPROJECT_2018_BFS_H

#include <iostream>
#include <queue>

class BFS {
public:
    typedef std::vector<std::vector<int>> graph;
    std::vector<int> breadth_first_search(graph &Graph, uint start, uint finish );
};

#endif //SQE_COURSEPROJECT_2018_BFS_H
