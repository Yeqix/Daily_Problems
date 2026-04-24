#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    auto b = a;
    vector<int> cnt(m + 1);
    vector<i64> v(n + 1);
    for (int i = 1; i <= n; i++) {
        v[i] = 1LL * cnt[a[i]] * m + a[i];
        cnt[a[i]]++;
    }

    sort(v.begin() + 1, v.end());

    for (int i = 1; i <= n; i++) {
        v[i] -= i;
    }

    int q;
    cin >> q;
    while (q--) {
        i64 k;
        cin >> k;

        if (k <= n) {
            cout << a[k] << "\n";
        } else {
            k += (lower_bound(v.begin() + 1, v.end(), k - n) - v.begin() - 1) - n;
            cout << (k - 1) % m + 1 << "\n";
        }
    }
    return 0;
}
