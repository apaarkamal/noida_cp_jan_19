#include<bits/stdc++.h>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

const int N = 100005;

typedef complex < double > base ;
#define PI 3.141592653589793l
void fft(vector<base> &a, bool invert) {
	int i, j, n = a.size();
	for (i = 1, j = 0; i < n; ++i) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1) {
			j -= bit;
		}
		j += bit;
		if (i < j) {
			swap(a[i], a[j]);
		}
	}
	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2 * PI / len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (i = 0; i < n; i += len) {
			base w(1);
			for (j = 0; j < len / 2; ++j) {
				base u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert) {
		for (i = 0; i < n; ++i) {
			a[i] /= n;
		}
	}
}
void multiply(const vector<int> &a, const vector<int> &b, vector <int> &res) {
	vector<base> fa(a.begin(), a.end()), fb(b.begin(), b.end());
	size_t n = 1;
	while (n < max((int)a.size(), (int)b.size())) n <<= 1;
	n <<= 1;
	fa.resize(n), fb.resize(n);
	fft(fa, false), fft(fb, false);
	for (size_t i = 0; i < n; ++i) {
		fa[i] *= fb[i];
	}
	fft(fa, true);
	res.resize(n);
	for (size_t i = 0; i < n; ++i) {
		res[i] = (int)(fa[i].real() + 0.5);
	}
}

void solve() {
	int i, j, k, nn, n, m, ans = 0, cnt = 0, sum = 0;
	string s, t;
	cin >> s >> t;
	n = s.size(), m = t.size();
	vector<int> a(n, 0), b(m, 0), res, final;
	//A
	for (i = 0; i < n; i++) {
		if (s[i] == 'A') a[i] = 1;
	}
	for (i = 0; i < m; i++) {
		if (t[i] == 'A') b[m - i - 1] = 1;
	}
	multiply(a, b, res);
	nn = res.size();
	final.resize(nn, 0ll);
	for (i = 0; i < res.size(); i++) {
		final[i] = res[i];
	}
	// C
	a.clear(); a.resize(n, 0);
	b.clear(); b.resize(m, 0);
	for (i = 0; i < n; i++) {
		if (s[i] == 'C') a[i] = 1;
	}
	for (i = 0; i < m; i++) {
		if (t[i] == 'C') b[m - i - 1] = 1;
	}
	multiply(a, b, res);
	for (i = 0; i < res.size(); i++) {
		final[i] += res[i];
	}
	//G
	a.clear(); a.resize(n, 0);
	b.clear(); b.resize(m, 0);
	for (i = 0; i < n; i++) {
		if (s[i] == 'G') a[i] = 1;
	}
	for (i = 0; i < m; i++) {
		if (t[i] == 'G') b[m - i - 1] = 1;
	}
	multiply(a, b, res);
	for (i = 0; i < res.size(); i++) {
		final[i] += res[i];
	}
	// T
	a.clear(); a.resize(n, 0);
	b.clear(); b.resize(m, 0);
	for (i = 0; i < n; i++) {
		if (s[i] == 'T') a[i] = 1;
	}
	for (i = 0; i < m; i++) {
		if (t[i] == 'T') b[m - i - 1] = 1;
	}
	multiply(a, b, res);
	for (i = m - 1; i < m - 1 + (n - m + 1); i++) {
		final[i] += res[i];
		ans = max(ans, final[i]);
	}
	cout << m - ans;
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