#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

int pr[N];
vector<int> primes;

void seive() {
	int i, j;
	for (i = 2; i < N; i++) {
		if (!pr[i]) {
			primes.pb(i);
			for (j = i; j < N; j += i) {
				pr[j]++;
			}
		}
	}
}


int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	seive();
	int t; cin >> t; while (t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> m >> n;
		bool seg_pr[n - m + 1] = {};
		for (auto x : primes) {
			if (x * x > n) break;
			// check for prime x
			int st = (m / x) * x;
			if (x >= m && x <= n) st = x * 2;
			for (i = st; i <= n; i += x) {
				if (i >= m) {
					seg_pr[i - m] = 1;
				}
			}
		}
		for (i = m; i <= n; i++) {
			if (seg_pr[i - m] == 0 && i != 1) {
				cout << i << '\n';
			}
		}
		cout << '\n';
	}
}