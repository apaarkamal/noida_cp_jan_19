#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

vector<int> gr[N];

int vis[N], sub_size[N], dis[N];

void dfs(int cur) {
	vis[cur] = 1;
	// cout << cur << " ";
	for (auto x : gr[cur]) {
		if (!vis[x]) dfs(x);
	}
}

void dfs(int cur, int par) {
	cout << cur << " ";
	sub_size[cur] = 1;
	for (auto x : gr[cur]) {
		if (x != par) {
			dis[x] = dis[cur] + 1;
			dfs(x, cur);
			sub_size[cur] += sub_size[x];
		}
	}
}

void bfs(int root) {
	memset(vis, 0, sizeof(vis));
	queue<int> Q;
	Q.push(root);
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		cout << cur << " ";
		vis[cur] = 1;
		for (auto x : gr[cur]) {
			if (!vis[x]) {
				Q.push(x);
			}
		}
	}
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		for (i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			gr[x].pb(y);
			gr[y].pb(x);
		}
		// dfs(1);
		dfs(1, 0);
		// bfs(2);
	}
}