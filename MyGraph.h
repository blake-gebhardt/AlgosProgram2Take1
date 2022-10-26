//
// Created by Blake Gebhardt on 25.10.22.
//

#ifndef UALGOSPROGRAM2TAKE1_MYGRAPH_H
#define UALGOSPROGRAM2TAKE1_MYGRAPH_H

#include "vector"
#include "iostream"
#include "vector"

using namespace std;

#define edge pair<int, int>

class MyGraph {
public:


    //array of <start, end, weight> values
    vector<pair<int, edge>> edgeList; //graph body
    vector<pair<int, edge>> mst; //mst
    int *parent;
    int graphSize;

    MyGraph(int n) {
        graphSize = n;
    };

    MyGraph(const MyGraph &g) {
        for (int i = 0; i < this->edgeList.size(); i++) {
            this->edgeList[i] = g.edgeList[i];
        }
        this->graphSize = g.graphSize;
    };

    bool inline AddEdge(int a, int b, float w) {
        if ((a > graphSize) || (b > graphSize)) {
            return false;
        } else {
            edge toAdd = {a, b};
            edgeList.push_back(make_pair(w, toAdd));
            return true;
        }
    }

    int find_set(int i) {
        // If i is the parent of itself
        if (i == parent[i])
            return i;
        else
            // Else if i is not the parent of itself
            // Then i is not the representative of thihis set
            return find_set(parent[i]);
    }

    void inline Output(ostream &os) {
        os << "Vertices: " << graphSize << "\n";
        for (auto x: edgeList) {
            if (x.second.first < x.second.second) {
                os << x.second.first << " " << x.second.second << " " << x.first << "\n";
            } else {
                os << x.second.second << " " << x.second.first << " " << x.first << "\n";
            }

        }
    }

    void union_set(int u, int v) const {
        parent[u] = parent[v];
    }

    pair<vector<int>, float> HW2Prog(int s, int t) {

    }


};

#endif //UALGOSPROGRAM2TAKE1_MYGRAPH_H