#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

vector<P> gr[N];
int dis[N];

void dfs(int cur, int par) {
	for (auto x : gr[cur]) if (x.F != par) {
			dis[x.F] = dis[cur] + x.S;
			dfs(x.F, cur);
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
			int x, y, w;
			cin >> x >> y >> w;
			gr[x].pb({y, w});
			gr[y].pb({x, w});
		}
		dfs(1, 0);
	}
}