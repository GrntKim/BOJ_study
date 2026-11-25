#include <iostream>

using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;

    int sum = 0;
    for (int i = 0; i < x; i++) sum += days[i];
    sum += y-1;

    cout << day[sum%7] << '\n';

    return 0;
}