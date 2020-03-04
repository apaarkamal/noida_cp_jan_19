#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

struct node {
	node* nxt[26];
	bool end;
	int cnt;
	node() {
		for (int i = 0; i < 26; i++) {
			nxt[i] = NULL;
		}
		end = false; cnt = 0;
	}
};

node *root;

void insert(string s) {
	node* cur = root;
	cur->cnt++;
	for (int i = 0; i < s.size(); i++) {
		if (cur->nxt[s[i] - 'a'] == NULL) {
			cur -> nxt[s[i] - 'a'] = new node();
		}
		cur = cur->nxt[s[i] - 'a'];
		cur->cnt++;
	}
	cur->end = true;
}

bool find_name(string s) {
	node* cur = root;
	for (int i = 0; i < s.size(); i++) {
		if (cur->nxt[s[i] - 'a'] == NULL) {
			return false;
		}
		cur = cur->nxt[s[i] - 'a'];
	}
	return cur->end;
}

int find_prefix(string s) {
	node* cur = root;
	for (int i = 0; i < s.size(); i++) {
		if (cur->nxt[s[i] - 'a'] == NULL) {
			return 0;
		}
		cur = cur->nxt[s[i] - 'a'];
	}
	return cur->cnt;
}

void solve() {
	int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
	root = new node();
	cin >> n;
	for (i = 0; i < n; i++) {
		string s;
		cin >> s;
		insert(s);
	}
	cin >> m;
	while (m--) {
		string s;
		cin >> s;
		// if (find_name(s)) {
		// 	cout << "YES\n";
		// }
		// else {
		// 	cout << "NO\n";
		// }
		cout << find_prefix(s) << '\n';
	}
	return ;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t; cin >> t; while (t--)
	solve();
	return 0;
}