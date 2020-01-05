#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 20;

bool pr[N];
vector<int> primes;

void seive() {
	int i, j;
	for (i = 2; i < N; i++) {
		if (pr[i] == 0) {
			// i is  a  prime
			// cancel mutiples of prime
			primes.pb(i);
			for (j = i * i; j < N; j += i) {
				pr[j] = 1;
			}
		}
	}
	// print primes
	for (auto x : primes) {
		cout << x << " ";
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