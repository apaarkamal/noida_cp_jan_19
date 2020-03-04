#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;



int knapsack(int weight[], int value[], int pos, int n, int capacity, vector<vector<int>>& memo) {
	if (pos == n) {
		return 0;
	}

	if (dp[pos][capacity] != -1) return dp[pos][capacity];

	int include = INT_MIN;
	int exclude = INT_MIN;
	if (capacity - weight[pos] >= 0) {

		include = value[pos] + knapsack(weight, value, pos + 1, n, capacity - weight[pos], memo);
	}
	exclude = knapsack(weight, value, pos + 1, n, capacity, memo);
	return dp[pos][capacity] = max(include, exclude);
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		int weight[] = {5, 4, 6, 3};
		int value[] = {50, 40, 70, 40};
		n = 4;
		int capacity = 8;
		vector<vector<int>> memo(n, vector<int>(capacity + 1, -1));
		cout << knapsack(weight, value, 0, n, capacity, memo);
	}
}