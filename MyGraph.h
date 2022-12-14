//
// Created by Blake Gebhardt on 25.10.22.
//
//Output functions are commented out. If you want to see them, just uncomment

#ifndef UALGOSPROGRAM2TAKE1_MYGRAPH_H
#define UALGOSPROGRAM2TAKE1_MYGRAPH_H

#include "vector"
#include "iostream"
#include "algorithm"

using namespace std;

#define edge pair<int, int>

class MyGraph {


private:
    //array of <start, end, weight> values
    vector<pair<int, edge>> edgeList; //graph body
    vector<pair<int, edge>> mst; //mst
    vector<int> finalPath;

    float maxWeight;
    int *parent = nullptr;
    int graphSize;

public:

    MyGraph(int &n) {
        graphSize = n;
        parent = new int[n + 1];
        for (int i = 0; i < n; i++) {
            *(parent + i) = i;
        }
        edgeList.clear();
        mst.clear();
    };

    MyGraph(const MyGraph &g) {
        for (int i = 0; i < this->edgeList.size(); i++) {
            this->edgeList[i] = g.edgeList[i];
        }
        this->graphSize = g.graphSize;
    };

    ~MyGraph() {
        delete parent;
    }

    bool inline AddEdge(int a, int b, float w) {
        if ((a > graphSize) || (b > graphSize)) {
            return false;
        } else {
            edge toAdd = {a, b};
            edgeList.push_back(make_pair(w, toAdd));
            return true;
        }
    }

    int inline find_set(int &i) {
        // If i is the parent of itself
        //int parental = *(parent + i);
        if (i == *(parent + i)) {
            return i;
        } else {
            // Else if i is not the parent of itself
            // Then i is not the representative of thihis set
            return find_set(*(parent + i));
        }
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

    void inline OutputMST(ostream &os) {
        os << "MST Vertices: " << mst.size() << "\n";
        for (auto x: mst) {
            if (x.second.first < x.second.second) {
                os << x.second.first << " " << x.second.second << " " << x.first << "\n";
            } else {
                os << x.second.second << " " << x.second.first << " " << x.first << "\n";
            }

        }
    }


    void inline union_set(int &u, int &v) const {
        *(parent + u) = *(parent + v);
    }


    void inline kruskal() {
        int i = 0;
        int uRep = 0;
        int vRep = 0;
        sort(edgeList.begin(), edgeList.end());  // increasing weight
        for (i = 0; i < edgeList.size(); i++) {
            uRep = find_set(edgeList[i].second.first);
            vRep = find_set(edgeList[i].second.second);
            if (uRep != vRep) {
                mst.push_back(edgeList[i]);  // add to tree
                union_set(uRep, vRep);
            }
        }
    }

    bool inline
    dfs(vector<int> adj[], vector<int> &path, vector<int> &vis, int &start, int &end, float &max, float &prev) {

        if (end == start) {
            if (path.back() != end) {
                path.push_back(end);
            }
            finalPath = path;
            this->maxWeight = max;
            return true;
        }
        vis[start] = 1;
        for (auto it: *(adj + start)) {
            if (vis[it] == 0) {
                path.push_back(it);
                if (mst[it - 1].first > max) {
                    prev = max;
                    max = mst[it - 1].first;
                }
                if (dfs(adj, path, vis, it, end, max, prev)) {
                    return true;
                } else {
                    max = prev;
                    path.pop_back();
                }
            }
        }
        return false;
    }

    bool inline validPath(int &n, int &start, int &end) {
        vector<int> adj[n + 1];
        vector<int> vertices;
        vertices.push_back(start);
        for (int i = 0; i < mst.size(); i++) {
            int u = mst[i].second.first;
            int v = mst[i].second.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        vector<int> vis(n + 1, 0);
        float max = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                float prev = 0;
                if (dfs(adj, vertices, vis, start, end, max, prev)) {
                    //couts for debugging
                    maxWeight = max;
                    cout << "Path: ";
                    for (auto x: vertices) {
                        cout << x << " ";
                    }
                    cout << "\nMax Annoyance: " << this->maxWeight << "\n";
                    return true;
                }
            }
        }
        return false;
    }


    pair<vector<int>, float> HW2Prog(int s, int t) {

        cout << "NEW GRAPH\n";
        cout << "------------\n";
        this->Output(cout);
        cout << "____________\n";
        this->kruskal();
        this->OutputMST(cout);
        this->validPath(graphSize, s, t);
        //cout << "____________\n";
        return make_pair(finalPath, maxWeight);


    }


};

#endif //UALGOSPROGRAM2TAKE1_MYGRAPH_H