#include <iostream>
#include "../include/BFS.h"

int main() {
    BFS T;
    BFS::graph TestG;
    TestG = {
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
    srand( time(0) );
    for (int i=0; i<5; i++) {
        int start = rand() % 9;
        int finish = rand() % 9;
        std::cout << finish << " to " << start << ": ";
        for (auto i: T.breadth_first_search(TestG, start, finish)) {
            if (i == -1) {
                std::cout << " - way not found";
            } else {
                std::cout << i << " ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}