#include <iostream>

using namespace std;

const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;

int board[25][25];
int n, ans = -1;

void process_line(int p, int dir) {
    int tmp[25] = {0,};
    int idx = 0;

    for (int i = 0; i < n; i++) {
        int k = (dir == RIGHT || dir == DOWN) ? n-i-1 : i;
        int cur = (dir == UP || dir == DOWN) 
            ? board[k][p] 
            : board[p][k];
        if (!cur) continue;

        if (!tmp[idx]) tmp[idx] = cur;
        else if (tmp[idx] == cur) tmp[idx++] += cur;
        else tmp[++idx] = cur;
    }

    for (int i = 0; i < n; i++) {
        int k = (dir == RIGHT || dir == DOWN) ? n-i-1 : i;
        if (dir == UP || dir == DOWN) board[k][p] = tmp[i];
        else board[p][k] = tmp[i];
    }
}

void move(int dir) {
    for (int p = 0; p < n; p++) {
        process_line(p, dir);
    }
}

void simulate(int depth) {
    if (depth == 5) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!board[i][j]) continue;
                ans = max(ans, board[i][j]);
            }
        }
        return;
    }
    int saved[25][25];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            saved[i][j] = board[i][j];

    for (int d = 0; d < 4; d++) {
        move(d);
        simulate(depth+1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = saved[i][j];
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    simulate(0);

    cout << ans << '\n';

    return 0;
}