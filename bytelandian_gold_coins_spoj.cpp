#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 1000005;

int dp[N];

int solve(int n) {
	if (n == 0) {
		return 0;
	}
	if (n < N) {
		if (dp[n] != -1) return dp[n];
		return dp[n] = max(n, solve(n / 2) + solve(n / 4) + solve(n / 3));
	}
	else {
		return max(n, solve(n / 2) + solve(n / 4) + solve(n / 3));
	}
}



int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	memset(dp, -1, sizeof(dp));
	while (cin >> n) {
		cout << solve(n) << '\n';
	}
}