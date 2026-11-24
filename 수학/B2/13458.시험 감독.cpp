#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, ans = 0;
    cin >> n;
    vector<ll> v(n);
    for (ll& x : v) cin >> x;

    int b, c;
    cin >> b >> c;
    for (const ll& cur : v) {
        ans += 1;
        if (cur > b) {
            if ((cur - b) >= c) {
                ans += (cur-b) / c;
                if ((cur-b)%c) ans++;
            } else ans++;
        }
    }

    cout << ans << '\n';
}