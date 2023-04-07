#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

#define MAX_PERM_SIZE 10

void solve() {
    int n, m;
    cin >> n >> m;

    vector<array<int, MAX_PERM_SIZE>> perms(n), rev_perms(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> perms[i][j];
            --perms[i][j];
        }

        for (int j = 0; j < m; ++j)
            rev_perms[i][perms[i][j]] = j;
    }

    sort(rev_perms.begin(), rev_perms.end(), [m](const auto &lhs, const auto &rhs) {
        for (int i = 0; i < m; ++i) {
            if (lhs[i] != rhs[i])
                return lhs[i] < rhs[i];
        }

        return false;
    });

    vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
        array<int, MAX_PERM_SIZE> perm = perms[i];

        for (int j = m - 1; j >= 0; --j) {
            auto it = lower_bound(rev_perms.begin(), rev_perms.end(), perm);

            if (it != rev_perms.end()) {
                bool valid = true;

                for (int k = 0; k <= j; ++k) {
                    if (perm[k] != (*it)[k]) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    ans[i] = j + 1;
                    break;
                }
            }

            perm[j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';

    cout << '\n';
}

int main() {
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
