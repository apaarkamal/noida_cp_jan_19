#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

struct dsu {
	vector<int> par, sz;
	int comp;
	void init(int n) {
		par.resize(n);
		sz.resize(n, 1);
		for (int i = 0; i < n; i++) par[i] = i;
		comp = n;
	}

	int get_par(int x) {
		if (par[x] == x) return x;
		return par[x] = get_par(par[x]);
	}

	// int get_par(int x) return x == par[x] ? x : par[x] = get_par(par[x]);

	bool unite(int x, int y) {
		int super_x = get_par(x);
		int super_y = get_par(y);
		if (super_x != super_y) {// not in same component
			par[super_x] = super_y;
			sz[super_y] += sz[super_x];
			sz[super_x] = 0;
			comp--;
			return true;
		}
		return false;
	}
};

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n >> m;
		dsu G;
		G.init(n);
		for (i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			G.unite(x, y);
		}
		for (i = 0; i < n; i++) {
			ans += (n - G.sz[G.get_par(i)]);
		}
		cout << ans / 2;
	}
}