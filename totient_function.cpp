#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 20;

int pr[N];
vector<int> primes;
int tot[N];

void seive() {
	int i, j;
	for (i = 1; i < N; i++) {
		tot[i] = i;
	}
	for (i = 2; i < N; i++) {
		if (!pr[i]) {
			for (j = i; j < N; j += i) {
				tot[i] *= (i - 1);
				tot[i] /= i;
			}
		}
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