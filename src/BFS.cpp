#include "BFS.h"

std::vector<int> BFS::breadth_first_search(BFS::graph &Graph, uint start, uint finish)
{
    std::vector<int> shortest_distance;
    std::queue <int> Q;
    std::vector<int> distance(Graph.size(), -1); //distance[i] - расстояние от i-ой вершины до стартовой
    std::vector<int> prevTop(Graph.size(), -1);  //prevTop[i] - предок i-ой вершины в кратчайшем пути
    if (start > Graph.size() || finish > Graph.size()) {
        shortest_distance.push_back(-1);
        return shortest_distance;
    }
    distance[start] = 0;
    Q.push(start);
    while (Q.size()) {
        uint QFront = Q.front();
        Q.pop();
        for (uint j = 0; j < Graph[QFront].size(); j++) {
            uint v = Graph[QFront][j];
            if (distance[v] == -1) {
                distance[v] = distance[QFront] + 1;
                prevTop[v] = QFront;
                Q.push(v);
            }
        }
    }
    shortest_distance.push_back(finish);
    shortest_distance.push_back(prevTop[finish]);
    int x = prevTop[finish];
    while (x != -1) {
        if (-1 == prevTop[x]) break;
        shortest_distance.push_back(prevTop[x]);
        x = prevTop[x];
    }
    return shortest_distance;
}
