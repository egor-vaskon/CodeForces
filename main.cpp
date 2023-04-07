#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

void solve() {
    int n;
    cin >> n;

    vector<vector<bool>> a(2, vector<bool>(n));
    auto b = a;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            int tmp;
            cin >> tmp;

            a[i][j] = tmp;
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) {
            int tmp;
            cin >> tmp;

            b[i][j] = tmp;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (a[0][i] == b[0][i] && a[1][i] == b[1][i])
            continue;
        else if (a[0][i] != a[1][i] && b[0][i] != b[1][i])
            ++ans;
        else {
            for (int t = 0; t < 2; ++t) {
                int d1 = INT_MAX, d2 = INT_MAX;
                int j = i+1, k = i+1;

                for (;j < n && a[t][j] != b[t][i]; ++j) {}
                if (j < n) d1 = j-i;

                assert(j == n || a[t][j] == b[t][i]);

                for (;k < n && a[!t][k] != b[t][i]; ++k) {}
                if (k < n) d2 = k-i+1;

                assert(k == n || a[!t][k] == b[t][i]);

                if (d1 == INT_MAX && d2 == INT_MAX) {
                    cout << "-1\n";
                    return;
                } else {
                    ans += min(d1, d2);

                    if (d1 <= d2) {
                        for (int l = j; l > i; l--)
                            swap(a[t][l], a[t][l-1]);
                    }
                    else {
                        swap(a[t][k], a[!t][k]);

                        for (int l = k; l > i; l--)
                            swap(a[t][l], a[t][l-1]);
                    }
                }
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    solve();
    /*int t;
    cin >> t;

    while (t--)
        solve();*/

    return 0;
}
