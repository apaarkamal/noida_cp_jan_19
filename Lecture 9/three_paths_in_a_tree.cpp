#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 200005;

vector<int> gr[N];
int dis[N], disa[N], disb[N], in_path[N], vis[N];

void dfs(int cur, int par) {
	for (auto x : gr[cur]) {
		if (x != par) {
			dis[x] = dis[cur] + 1;
			dfs(x, cur);
		}
	}
}

void dfs1(int cur, int par) {
	for (auto x : gr[cur]) {
		if (x != par) {
			disa[x] = disa[cur] + 1;
			dfs1(x, cur);
		}
	}
}

void dfs2(int cur, int par) {
	for (auto x : gr[cur]) {
		if (x != par) {
			disb[x] = disb[cur] + 1;
			dfs2(x, cur);
		}
	}
}

void dfs3(int cur, int par) {
	for (auto x : gr[cur]) {
		if (x != par && !in_path[x]) {
			dis[x] = dis[cur] + 1;
			dfs3(x, cur);
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
		dfs(1, 0);
		int a = 0, b = 0;
		for (i = 1; i <= n; i++) {
			if (dis[i] > dis[a]) {
				a = i;
			}
		}
		dis[a] = 0;
		dfs(a, 0);
		for (i = 1; i <= n; i++) {
			if (dis[i] > dis[b]) {
				b = i;
			}
		}
		dfs1(a, 0);
		dfs2(b, 0);
		for (i = 1; i <= n; i++) {
			if (disa[i] + disb[i] == disa[b]) {
				in_path[i] = 1;
			}
		}
		memset(dis, 0, sizeof(dis));
		for (i = 1; i <= n; i++) {
			if (!vis[i] && in_path[i]) {
				dfs3(i, 0);
			}
		}
		ans = 0;
		for (i = 1; i <= n; i++) {
			if (dis[i] > dis[ans]) {
				ans = i;
			}
		}
		if (ans == 0) {
			if (a != 1 && b != 1) {
				ans = 1;
			}
			else if (a != 2 && b != 2) {
				ans = 2;
			}
			else {
				ans = 3;
			}
		}
		cout << disa[b] + dis[ans] << '\n';
		cout << a << " " << b << " " << ans;
	}
}