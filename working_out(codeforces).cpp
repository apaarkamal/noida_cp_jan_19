#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 1005;

int a[N][N], dp_top_left[N][N], dp_bottom_left[N][N];
int  dp_top_right[N][N], dp_bottom_right[N][N];

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n >> m;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        // top left
        dp_top_left[0][0] = a[0][0];
        for (i = 1; i < n; i++) {
            dp_top_left[i][0] = dp_top_left[i - 1][0] + a[i][0];
        }
        for (j = 1; j < m; j++) {
            dp_top_left[0][j] = dp_top_left[0][j - 1] + a[0][j];
        }
        for (i = 1; i < n; i++) {
            for (j = 1; j < m; j++) {
                dp_top_left[i][j] = max(dp_top_left[i - 1][j], dp_top_left[i][j - 1]) + a[i][j];
            }
        }

        // bottom left
        dp_bottom_left[n - 1][0] = a[n - 1][0];
        for (i = n - 2; i >= 0; i--) {
            dp_bottom_left[i][0] = dp_bottom_left[i + 1][0] + a[i][0];
        }
        for (j = 1; j < m; j++) {
            dp_bottom_left[n - 1][j] = dp_bottom_left[n - 1][j - 1] + a[n - 1][j];
        }
        for (i = n - 2; i >= 0; i--) {
            for (j = 1; j < m; j++) {
                dp_bottom_left[i][j] = max(dp_bottom_left[i + 1][j], dp_bottom_left[i][j - 1]) + a[i][j];
            }
        }

        // top right
        dp_top_right[0][m - 1] = a[0][m - 1];
        for (i = 1; i < n; i++) {
            dp_top_right[i][m - 1] = dp_top_right[i - 1][m - 1] + a[i][m - 1];
        }
        for (j = m - 2; j >= 0; j--) {
            dp_top_right[0][j] = dp_top_right[0][j + 1] + a[0][j];
        }
        for (i = 1; i < n; i++) {
            for (j = m - 2; j >= 0; j--) {
                dp_top_right[i][j] = max(dp_top_right[i - 1][j], dp_top_right[i][j + 1]) + a[i][j];
            }
        }

        // bottom right
        dp_bottom_right[n - 1][m - 1] = a[n - 1][m - 1];
        for (i = n - 2; i >= 0; i--) {
            dp_bottom_right[i][m - 1] = dp_bottom_right[i + 1][m - 1] + a[i][m - 1];
        }
        for (j = m - 2; j >= 0; j--) {
            dp_bottom_right[n - 1][j] = dp_bottom_right[n - 1][j + 1] + a[n - 1][j];
        }
        for (i = n - 2; i >= 0; i--) {
            for (j = m - 2; j >= 0; j--) {
                dp_bottom_right[i][j] = max(dp_bottom_right[i + 1][j], dp_bottom_right[i][j + 1]) + a[i][j];
            }
        }

        //////////////////////////////////////////////
        for (i = 1; i < n - 1; i++) {
            for (j = 1; j < m - 1; j++) {
                ans = max(ans, dp_top_left[i - 1][j] + dp_bottom_right[i + 1][j] + dp_bottom_left[i][j - 1] + dp_top_right[i][j + 1]);
                ans = max(ans, dp_top_left[i][j - 1] + dp_bottom_right[i][j + 1] + dp_bottom_left[i + 1][j] + dp_top_right[i - 1][j]);
            }
        }
        cout << ans;
    }
}