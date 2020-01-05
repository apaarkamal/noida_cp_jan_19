#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;
const int mod = 1e9;
const int sz = 10;

struct Mat
{
	int m[sz][sz];
	Mat()
	{
		memset(m, 0, sizeof m);
	}
	void eye()
	{
		for (int i = 0; i < sz; i++)
			m[i][i] = 1;
	}
	Mat operator* (const Mat &a) const
	{
		Mat r;
		for (int i = 0; i < sz; i++)
			for (int j = 0; j < sz; j++)
				for (int k = 0; k < sz; k++)
					r.m[i][j] = (r.m[i][j] + m[i][k] * 1ll * a.m[k][j]) % mod;
		return r;
	}
};


int c[sz], b[sz];

int solve(int n, int k) {
	n -= k;
	Mat res;
	res.eye();
	Mat T;
	for (int i = 0; i < k; i++) {
		T.m[0][i] = c[i];
	}
	for (int i = 1; i < k; i++) {
		T.m[i][i - 1] = 1;
	}
	while (n) {
		if (n & 1) {
			res = res * T;
		}
		T = T * T;
		n /= 2;
	}
	int ans = 0;
	for (int i = 0; i < k; i++) {
		ans += res.m[0][i] * b[k - i - 1];
		ans %= mod;
	}
	return ans;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> k ;
		for (i = 0; i < k; i++) {
			cin >> b[i];
		}
		for (i = 0; i < k; i++) {
			cin >> c[i];
		}
		cin >> n;
		if (n <= k) {
			cout << b[n - 1] << '\n';
		}
		else {
			cout << solve(n, k) << '\n';
		}
	}
}