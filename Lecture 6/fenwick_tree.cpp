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
	vector<int> f;
	int n;
	void init(int _n) {
		n = _n;
		f.resize(n + 1, 0);
	}
	void add(int index, int val) {
		index++;// 1 - based indexing
		while (index <= n) {
			f[index] += val;
			index += (index & -index);
		}
	}
	int query(int index) {
		index++;// 1 - based indexing
		int ans = 0;
		while (index) {
			ans += f[index];
			index -= (index & -index);
		}
		return ans;
	}
};

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		fenwick tree;
		tree.init(n);
		int a[n];
		for (i = 0; i < n; i++) {
			cin >> a[i];
			tree.add(i, a[i]);
		}
		cout << tree.query(3) << '\n';
		// 1 5
		tree.add(1, 3);
		cout << tree.query(3) << '\n';

	}
}