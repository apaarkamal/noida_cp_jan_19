#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back

const int N = 100005;

int vis[N];
bool cycle;

void dfs(int cur, int par) {
    vis[cur] = 1;
    for (auto x : gr[cur]) {
        if (vis[x] == 0) {
            dfs(x, cur);
        }
        else if (vis[x] == 1 && x != par) {
            cycle = 1;
        }
    }
    vis[cur] = 2;
}

int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;


    }
}