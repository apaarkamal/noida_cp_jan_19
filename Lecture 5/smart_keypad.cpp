#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

string table[10] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
string num;

void solve(int pos, string res) {
	if (pos == num.size() ) {
		cout << res << '\n';
		return ;
	}
	for (int i = 0; i < table[num[pos] - '0'].size(); i++) {
		solve(pos + 1, res + table[num[pos] - '0'][i]);
	}
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> num;
		solve(0, "");
	}
}