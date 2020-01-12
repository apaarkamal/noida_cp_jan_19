#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 9;

int grid[N][N];

void print_grid() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}
}

bool check(int digit, int row, int col) {
	int i, j;
	// row check
	i = row; j = 0;
	while (j < N) {
		if (grid[i][j] == digit) return false;
		j++;
	}
	// col check
	i = 0; j = col;
	while (i < N) {
		if (grid[i][j] == digit) return false;
		i++;
	}
	// 3 x 3 check
	int startx = (row / 3) * 3, starty = (col / 3) * 3;
	for (i = startx; i < startx + 3; i++) {
		for (j = starty; j < starty + 3; j++) {
			if (grid[i][j] == digit) return false;
		}
	}
	return true;
}

void sudoku_solver(int row, int col) {
	if (row == N && col == 0) {
		print_grid();
		return;
	}
	if (col == N) {
		// solve for next row
		// because we are at the end of the row
		sudoku_solver(row + 1, 0);
		return ;
	}
	if (grid[row][col] == 0) {
		for (int digit = 1; digit <= 9; digit++) {
			if (check(digit, row, col)) {
				grid[row][col] = digit;
				sudoku_solver(row , col + 1);
				grid[row][col] = 0;
			}
		}
	}
	else {
		sudoku_solver(row, col + 1);
	}
}

int32_t main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	// int t;cin>>t;while(t--)
	{
		int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
		cin >> n;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				cin >> grid[i][j];
			}
		}
		sudoku_solver(0, 0);
	}
}