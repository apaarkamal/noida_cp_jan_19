#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

struct segmenttree {
	vector<int> st;
	void init(int _n) {
		st.clear();
		st.resize(4 * _n, INT_MIN);
	}
	void update(int l, int r, int indup, int val, int node) {
		if (l == r) {
			st[node] = val;
			return;
		}
		else {
			int mid = (l + r) / 2;
			if (indup >= l && indup <= mid) {
				update(l, mid, indup, val, node * 2 + 1);
			}
			else {
				update(mid + 1, r, indup, val, node * 2 + 2);
			}
			st[node] = max(st[2 * node + 1], st[2 * node + 2]);
		}
	}

	int query(int si, int se, int l, int r, int node) {
		if (se < l || si > r || l > r) {
			return INT_MIN;
		}
		if (si >= l && se <= r) {
			return st[node];
		}
		int mid = (si + se) / 2;
		int q1 = query(si, mid, l, r, node * 2 + 1);
		int q2 = query(mid + 1, se, l, r, node * 2 + 2);
		return max(q1, q2);
	}
} tree;

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		P a[n];
		for (i = 0; i < n; i++) {
			cin >> a[i].F;
			a[i].S = i;
		}
		tree.init(n);
		sort(a, a + n);
		int res[n];
		for (i = 0; i < n; i++) {
			ans = tree.query(0, n - 1, a[i].S, n - 1, 0);
			if (ans == INT_MIN) {
				res[a[i].S] = -1;
			}
			else {
				res[a[i].S] = ans - a[i].S - 1;
			}
			tree.update(0, n - 1, a[i].S, a[i].S, 0);
		}
		for (i = 0; i < n; i++) {
			cout << res[i] << " ";
		}
	}
}