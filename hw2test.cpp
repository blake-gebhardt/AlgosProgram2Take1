#include <iostream>
#include <fstream>
#include <vector>
#include "MyGraph.h"

using namespace std;

int main() {
    ifstream ifile("prog2test.txt");
    if (ifile.is_open()) {
        cout << "Worked\n";
    }
    int n, e, c;

    ifile >> n >> e >> c;
    MyGraph g(n);

    for (int i = 0; i < e; i++) {
        int s, t;
        float w;
        ifile >> s >> t >> w;
        g.AddEdge(s, t, w);
    }


    vector<int> p, q;
    for (int i = 0; i < c; i++) {
        int s, t;
        ifile >> s >> t;
        p.push_back(s);
        q.push_back(t);
    }

    ifile.close();

    vector<pair<vector<int>, float> > resarray;

    // tht timer will time this for loop

//    for (int i = 0; i < p.size(); i++)
//    {
//      pair<vector<int>, float> res = g.HW2Prog(p[i], q[i]);
//      resarray.push_back(res);
//    }
//
//    for (int i = 0; i < p.size(); i++)
//    {
//	cout << p[i] << " -> " << q[i] << " : Path : ";
//	for (int j =0; j < resarray[i].first.size(); j++)
//		cout << resarray[i].first[j] << "  ";
//	cout << "  annoying-ness : " << resarray[i].second << endl;
//    }

    g.Output(cout);
    cout << "____________\n";
    g.kruskal();

    g.OutputMST(cout);

    if (g.validPath(n, p[0], q[0])) {
        cout << "\nThere is a path from " << p[0] << " to " << q[0];
    } else {
        cout << "\nThere is no path from " << p[0] << " to " << q[0];
    }


    return 0;

}
