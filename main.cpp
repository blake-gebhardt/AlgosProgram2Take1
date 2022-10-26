#include <iostream>
#include <chrono>
#include "MyGraph.h"

using namespace std;
int main() {


    MyGraph graph(5);
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 100000; i ++){
    graph.AddEdge(0,1, 5);
    graph.AddEdge(0,4, 3);
    graph.AddEdge(1,4, 3);
    graph.AddEdge(1,3, 3);
    graph.AddEdge(1,2, 3);
    graph.AddEdge(2,3, 3);
    graph.AddEdge(4,3, 3);
    }

    auto stop = std::chrono::high_resolution_clock::now();

    graph.Output(std::cout);
    auto duration = duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time: " << duration.count();

    cout << "\nCompare: \n";
    bool yeet = graph.edgeList[1] < graph.edgeList[0];
    cout << yeet << "\n";
    return 0;
}
