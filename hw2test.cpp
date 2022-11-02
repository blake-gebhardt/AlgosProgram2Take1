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

    for (int i = 0; i < p.size(); i++)
    {
      pair<vector<int>, float> res = g.HW2Prog(p[i], q[i]);
        g.HW2Prog(p[i], q[i]);
      resarray.push_back(res);
    }

    for (int i = 0; i < p.size(); i++)
    {
	cout << p[i] << " -> " << q[i] << " : Path : ";
	for (int j =0; j < resarray[i].first.size(); j++)
		cout << resarray[i].first[j] << "  ";
	cout << "  annoying-ness : " << resarray[i].second << endl;
    }

//
//cout << "\n\n\n\n\n\n\n\n\n";
//    int size = 15;
//
//    MyGraph newfraph(size);
//    newfraph.AddEdge(7, 6, 1);
//    newfraph.AddEdge(8, 2, 2);
//    newfraph.AddEdge(6, 5, 2);
//    newfraph.AddEdge(0, 1, 4);
//    newfraph.AddEdge(2, 5, 4);
//    newfraph.AddEdge(8, 6, 6);
//    newfraph.AddEdge(2, 3, 7);
//    newfraph.AddEdge(7, 8, 7);
//    newfraph.AddEdge(0, 7, 8);
//    newfraph.AddEdge(1, 2, 8);
//    newfraph.AddEdge(3, 4, 9);
//    newfraph.AddEdge(5, 4, 10);
//    newfraph.AddEdge(1, 7, 11);
//    newfraph.AddEdge(3, 5, 14);
//
//    newfraph.HW2Prog(5,3);

    return 0;

}
