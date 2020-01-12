#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 20;

int divisors[N];

void seive() {
	int i, j;
	for (i = 1; i < N; i++) {
		for (j = i; j < N; j += i) {
			divisors[j]++;
		}
	}
	for (i = 1; i < N; i++) {
		cout << i << " -> " << divisors[i] << "\n";
	}
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		seive();

	}
}