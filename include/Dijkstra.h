
#ifndef SQE_COURSEPROJECT_DIJKSTRA_H
#define SQE_COURSEPROJECT_DIJKSTRA_H

#include <iostream>
#include <queue>

#define SIZE 6

class Dijkstra {
public:
    typedef int graph[SIZE][SIZE];
    std::vector<int> Dijkstra_search(int &Graph, uint start, uint finish );
};

#endif //SQE_COURSEPROJECT_DIJKSTRA_H
