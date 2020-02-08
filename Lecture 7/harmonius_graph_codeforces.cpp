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
	vector<int> p, sz, mx;
	int comp;
	void init(int NN) {
		sz.clear(); p.clear(); mx.clear();
		p.resize(NN); sz.resize(NN, 1); mx.resize(NN);
		iota(p.begin(), p.end(), 0);
		iota(mx.begin(), mx.end(), 0);
		comp = NN;
	}
	int get(int x) {
		return (x == p[x] ? x : (p[x] = get(p[x])));
	}
	void unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x != y) {
			p[x] = y;
			sz[y] += sz[x];
			mx[y] = max(mx[y], mx[x]);
			sz[x] = 0;
			comp--;
		}
	}
} G;

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n >> m;
		G.init(n);
		for (i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			x--; y--;
			G.unite(x, y);
		}
		for (i = 0; i < n; ) {
			j = i;
			while (j <= G.mx[G.get(i)]) {
				if (G.get(j) != G.get(i)) {
					G.unite(i, j);
					ans++;
				}
				j++;
			}
			i = j;
		}
		cout << ans;
	}
}