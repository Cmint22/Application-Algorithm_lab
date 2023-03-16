#include <bits/stdc++.h>
using namespace std;

class DSU {
	int* parent;
	int* rank;
public:
	DSU(int n) {
		parent = new int[n];
		rank = new int[n];
		for (int i = 0; i < n; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}
	int find(int i) {
		if (parent[i] == -1)
			return i;
		return parent[i] = find(parent[i]);
	}
	void unite(int x, int y) {
		int s1 = find(x);
		int s2 = find(y);
		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
			} else if (rank[s1] > rank[s2]) {
				parent[s2] = s1;
			} else {
				parent[s2] = s1;
				rank[s1] += 1;
			}
		}
	}
};

class Graph {
	vector<vector<int> > edgelist;
	int V;
public:
	Graph(int V) { this->V = V; }
	void addEdge(int i, int j, int w) {
		cin >> i >> j >> w;
		edgelist.push_back({ w, i, j });
	}
	void kruskals_mst(int K) {
		sort(edgelist.begin(), edgelist.end());
		DSU s(V);
		int ans = 0;
		cout << "Following are the edges" << endl;
		for (auto edge : edgelist) {
			int w = edge[0];
			int i = edge[1];
			int j = edge[2];
			if (s.find(i) != s.find(j) && i <= K && j <= K) {
				s.unite(i, j);
				ans += w;
				cout << i << " -- " << j << " == " << w << endl;
			}
		}
		cout << "Minimum Cost:" << ans;
	}
};

int main() {
	int n, m, K, i, j, w;
	cin >> n >> m;
	Graph g(m);
	for(int t = 0; t < m; t++)
		g.addEdge(i, j, w);
	cin >> K;
	string a[K];
	for(int t = 0; t < K; t++) {
		cin >> a[t];
	}
	g.kruskals_mst(K);
	return 0;
}
