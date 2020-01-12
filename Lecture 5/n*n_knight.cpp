#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 105;

int n;
int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1, -2, 2, -2, 2, 1, -1};
int grid[N][N];

bool check(int row, int col) {
	if (row >= 0 && row < n && col >= 0 && col < n && grid[row][col] == 0) return true;
	return false;
}

void print_grid() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void k_knight(int row, int col, int cnt ) {
	// cout << row << " " << col << " " << cnt << '\n';

	grid[row][col] = cnt;
	if (cnt == n * n) {
		print_grid();
		return;
	}
	for (int i = 0; i < 8; i++) {
		int new_row = row + dx[i];
		int new_col = col + dy[i];
		if (check(new_row, new_col)) {
			k_knight(new_row, new_col, cnt + 1);
		}
	}
	grid[row][col] = 0;
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		k_knight(0, 0, 1);
	}
}