#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

int a[N];

struct segmenttree_with_lazy_propagation {
	vector<int> st, lz;
	void init(int n) {
		st.resize(4 * n);
		lz.resize(4 * n, 0);
	}
	void build(int start, int end, int node) {
		if (start == end) {
			st[node] = a[start];
			return;
		}
		int mid = (start + end) / 2;
		build(start, mid, 2 * node + 1);
		build(mid + 1, end, 2 * node + 2);
		st[node] = st[2 * node + 1] + st[2 * node + 2];
	}
	int query(int start, int end, int l, int r, int node) {
		if (lz[node] != 0) {
			// segment tree update
			st[node] += lz[node] * (end - start + 1);
			// leaf update
			if (start != end) {
				lz[2 * node + 1] += lz[node];
				lz[2 * node + 2] += lz[node];
			}
			lz[node] = 0;
		}
		if (start > r || end < l) {
			return 0;
		}
		if (start >= l && end <= r) {
			return st[node];
		}
		int mid = (start + end) / 2;
		int q1 = query(start, mid, l, r, 2 * node + 1);
		int q2 = query(mid + 1, end, l, r, 2 * node + 2);
		return q1 + q2;
	}
	void update(int start, int end, int l, int r, int val, int node) {
		if (lz[node] != 0) {
			// segment tree update
			st[node] += lz[node] * (end - start + 1);
			// leaf update
			if (start != end) {
				lz[2 * node + 1] += lz[node];
				lz[2 * node + 2] += lz[node];
			}
			lz[node] = 0;
		}
		if (start > r || end < l) {
			return ;
		}
		// complete overlap;
		if (start >= l && end <= r) {
			st[node] += val * (end - start + 1);
			if (start != end) {
				lz[2 * node + 1] += val;
				lz[2 * node + 2] += val;
			}
			return ;
		}
		int mid = (start + end) / 2;
		update(start, mid, l, r, val, 2 * node + 1);
		update(mid + 1, end, l, r, val, 2 * node + 2);
		st[node] = st[2 * node + 1] + st[2 * node + 2];
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
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		tree.init(n);
		tree.build(0, n - 1, 0);
		cout << tree.query(0, n - 1, 1, 4, 0) << '\n';
		tree.update(0, n - 1, 0, 2, 3, 0);
		cout << tree.query(0, n - 1, 0, 0, 0) << '\n';
	}
}