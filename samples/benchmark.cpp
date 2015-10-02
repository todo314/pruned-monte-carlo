#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include "../src/pmc.hpp"

using namespace std;

int main(int argc, char **argv) {
	if (argc < 4) {
		cerr << "./pmc graph k R" << endl;
		exit(1);
	}

	string file = argv[1];
	int k = atoi(argv[2]);
	int R = atoi(argv[3]);

	ifstream is(file.c_str());
	vector<pair<pair<int, int>, double> > es;
	int u, v;
	double p;
	for (; is >> u >> v >> p;) {
		if (u == v) {
			continue;
		}
		es.push_back(make_pair(make_pair(u, v), p));
	}
	is.close();

	InfluenceMaximizer im;
	vector<int> seeds = im.run(es, k, R);
	for (int i = 0; i < k; i++) {
		cout << i << "-th seed =\t" << seeds[i] << endl;
	}

	return 0;
}
