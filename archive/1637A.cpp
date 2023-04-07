#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> a1(n);

    for (int len = 1; len < n; len++) {
        memcpy(a1.data(), a.data(), sizeof(int) * a1.size());

        sort(a1.begin(), a1.begin()+len);
        sort(a1.begin()+len, a1.end());

        if (!is_sorted(a1.begin(), a1.end())) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
