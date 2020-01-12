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
int grid[N][N];

void print_grid() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << (grid[i][j] == 1 ? "Q " : ". ");
        }
        cout << '\n';
    }
    cout << '\n';
}

bool can_be_placced(int row, int col) {
    int i, j;
    i = row; j = col;
    // col check
    while (i >= 0) {
        if (grid[i][j] == 1) return false;
        i--;
    }
    i = row; j = col;
    // left_diagonal check
    while (i >= 0 && j >= 0) {
        if (grid[i][j] == 1) return false;
        i--; j--;
    }
    i = row; j = col;
    // right_diagonal check
    while (i >= 0 && j < n) {
        if (grid[i][j] == 1) return false;
        i--; j++;
    }
    return true;
}

void nqueen(int row) {
    if (row == n) {
        print_grid();
        exit(0);
        return ;
    }
    for (int col = 0; col < n; col++) {
        if (can_be_placced(row, col)) {
            grid[row][col] = 1;
            nqueen(row + 1);
            grid[row][col] = 0;
        }
    }
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        nqueen(0);
    }
}