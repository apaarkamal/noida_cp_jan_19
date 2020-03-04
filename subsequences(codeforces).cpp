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
		cin >> n >> k;
		int a[n];
		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		int dp[k + 2][n];
		for (i = 0; i < n; i++) {
			dp[1][i] = 1;
		}
		for (int kk = 2; kk <= k + 1; kk++) {
			bit.init(n + 10);
			for (i = 0; i < n; i++) {
				dp[kk][i] = bit.sum(a[i] - 1);
				bit.add(a[i], dp[kk - 1][i]);
			}
		}
		// for (i = 1; i <= k + 1; i++) {
		// 	for (j = 0; j < n; j++) {
		// 		cout << dp[i][j] << " ";
		// 	}
		// 	cout << '\n';
		// }
		for (i = 0; i < n; i++) {
			ans += dp[k + 1][i];
		}
		cout << ans;
	}
}