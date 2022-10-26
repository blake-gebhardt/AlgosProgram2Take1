//
// Created by Blake Gebhardt on 25.10.22.
//

#ifndef UALGOSPROGRAM2TAKE1_MYGRAPH_H
#define UALGOSPROGRAM2TAKE1_MYGRAPH_H
#include "vector"
#include "iostream"
#include "vector"

class MyGraph{
public:

    struct edge{
        int point1;
        int point2;
        float weight;
        friend bool operator< (const edge& first, const edge& second){
            return first.weight < second.weight;
        };
    };

    //array of <start, end, weight> values
    std::vector<edge> edgeList;
    int graphSize;

    MyGraph(int n) {
        graphSize = n;
    };

    MyGraph(const MyGraph& g){
        for (int i = 0; i < this->edgeList.size(); i++){
            this->edgeList[i] = g.edgeList[i];
        }
    };

    bool inline AddEdge(int a, int b, float w){
        if ((a > graphSize) || (b > graphSize) ){
            return false;
        }
        else {
            edge toAdd = {a, b, w};
            edgeList.push_back(toAdd);
            return true;
        }
    }

    void inline Output(std::ostream &os) {
        std::cout << "Vertices: " << graphSize << "\n";
        for (auto x : edgeList){
            if (x.point1 < x.point2){
            os << x.point1 << " " << x.point2 << " " << x.weight << "\n";
            }
            else {
                os << x.point2 << " " << x.point1 << " " << x.weight << "\n";
            }
        }
    }

    std::pair<std::vector<int>, float> HW2Prog(int s, int t){

    }


};

#endif //UALGOSPROGRAM2TAKE1_MYGRAPH_H