// C++ implementation to find the
// maximum weighted edge in the simple
// path between two nodes in N-ary Tree

#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

// Depths of Nodes
vector<int> level(N);
const int LG = 20;

// Parent at every 2^i level
vector<vector<int> > dp(LG, vector<int>(N));

// Maximum node at every 2^i level
vector<vector<int> > mx(LG, vector<int>(N));

// Graph that stores destinations
// and its weight
vector<vector<pair<int, int> > > v(N);
int n;

// Function to traverse the nodes
// using the Depth-First Search Traversal
void dfs_lca(int a, int par, int lev)
{
	dp[0][a] = par;
	level[a] = lev;
	for (auto i : v[a]) {

		// Condition to check if its
		// equal to its parent then skip
		if (i.first == par)
			continue;
		mx[0][i.first] = i.second;

		// DFS Recursive Call
		dfs_lca(i.first, a, lev + 1);
	}
}

// Function to find the ancestor
void find_ancestor()
{

	// Loop to set every 2^i distance
	for (int i = 1; i < LG; i++) {
		// Loop to calculate for
		// each node in the N-ary tree
		for (int j = 1; j <= n; j++) {
			dp[i][j]
				= dp[i - 1][dp[i - 1][j]];

			// Storing maximum edge
			mx[i][j]
				= min(mx[i - 1][j],
					mx[i - 1][dp[i - 1][j]]);
		}
	}
}

int getMax(int a, int b)
{

	if (level[b] < level[a])
		swap(a, b);

	int ans = 1e9;

	int diff = level[b] - level[a];
	while (diff > 0) {
		int log = log2(diff);
		ans = min(ans, mx[log][b]);
		b = dp[log][b];
		diff -= (1 << log);
	}

	// Take both a, b to its
	// lca and find maximum
	while (a != b) {
		int i = log2(level[a]);

		// Loop to find the 2^ith
		// parent that is different
		// for both a and b i.e below the lca
		while (i > 0
			&& dp[i][a] == dp[i][b])
			i--;

		// Updating ans
		ans = min(ans, mx[i][a]);
		ans = min(ans, mx[i][b]);

		// Changing value to its parent
		a = dp[i][a];
		b = dp[i][b];
	}
	return ans;
}

// Function to compute the Least
// common Ancestor
void compute_lca()
{
		for (int i = 1; i < LG; i++)
			for (int j = 1; j <= n; j++)
				mx[i][j]=1e9;
	dfs_lca(1, 0, 0);
	find_ancestor();
}

// Driver Code
int main()
{
	// Undirected tree
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u,v1,c;
		cin>>u>>v1>>c;
		v[u].push_back({v1,c});
		v[v1].push_back({u,c});
	}
	// Computing LCA
	compute_lca();

	int q;
	cin>>q;
	for (int i = 0; i < q; i++) {
		int x,y;
		cin>>x>>y;
		int max_edge = getMax(x,
							y);
		cout << max_edge << endl;
	}
	return 0;
}
