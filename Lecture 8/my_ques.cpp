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
        int a[n], b[n], c[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
            c[i] = a[i];
        }
        sort(b, b + n);
        m = unique(b, b + n) - b;
        for (i = 0; i < n; i++) {
            a[i] = lower_bound(b, b + m, a[i]) - b + 1;
            // cout << a[i] << " ";
        }
        fenwick tree;
        tree.init(m + 1);
        for (i = 0; i < n; i++) {
            cout << tree.query(m) - tree.query(a[i]) << " ";
            tree.add(a[i], c[i]);
        }
    }
}