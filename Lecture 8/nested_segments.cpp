#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

struct fenwick {
	vector<int> fn;
	int n;
	void init(int _n) {
		n = _n + 10;
		fn.clear(); fn.resize(n, 0);
	}
	void add(int x, int val) {
		x++;// 1 based indexing
		while (x <= n) {
			fn[x] += val;
			x += (x & (-x));
		}
	}
	int sum(int x) {
		x++;//1 basaed indexing
		int ans = 0;
		while (x) {
			ans += fn[x];
			x -= (x & (-x));
		}
		return ans;
	}
} bit;

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		P a[n];
		vector<int> order;
		for (i = 0; i < n; i++) {
			cin >> a[i].F >> a[i].S;
			order.pb(a[i].F);
			order.pb(a[i].S);
		}
		sort(order.begin(), order.end());
		int pos[2 * n + 1];
		memset(pos, -1, sizeof(pos));
		for (i = 0; i < n; i++) {
			a[i].F = lower_bound(order.begin(), order.end(), a[i].F) - order.begin() + 1;
			a[i].S = lower_bound(order.begin(), order.end(), a[i].S) - order.begin() + 1;
			// cout << a[i].F << " " << a[i].S << '\n';
			pos[a[i].S] = i;
		}
		bit.init(2 * n + 1);
		int res[n];
		for (i = 1; i <= 2 * n; i++) {
			if (pos[i] != -1) {
				int l = a[pos[i]].F, r = a[pos[i]].S;
				res[pos[i]] = bit.sum(r) - bit.sum(l);
				bit.add(l, 1);
			}
		}
		for (i = 0; i < n; i++) {
			cout << res[i] << '\n';
		}
	}
}