//
// Created by Blake Gebhardt on 25.10.22.
//

#ifndef UALGOSPROGRAM2TAKE1_MYGRAPH_H
#define UALGOSPROGRAM2TAKE1_MYGRAPH_H
#include "vector"

class MyGraph{
public:

    int** graphMatrix;
    int graphSize;

    MyGraph(int n) {
        graphSize = n;
        graphMatrix = new int*[n];
        for (int i = 0; i < n; i++) {
            graphMatrix[i] = new int[n];
        }
    };

    MyGraph(const MyGraph& g){
        this->graphMatrix = g.graphMatrix;
    };




};
#endif //UALGOSPROGRAM2TAKE1_MYGRAPH_H