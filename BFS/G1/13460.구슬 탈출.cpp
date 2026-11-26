#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};
string board[15];
bool visited[15][15][15][15];
int n, m, rr, rc, br, bc;

void roll(int& r, int& c, int& dist, int& d) {
    dist = 0;
    while (board[r + dr[d]][c + dc[d]] != '#') {
        r += dr[d];
        c += dc[d];
        dist++;
        if (board[r][c] == 'O') break;
    }
}

void bfs(int rr, int rc, int br, int bc) {
    queue<tuple<int, int, int, int, int>> q;
    q.push({rr, rc, br, bc, 0});
    visited[rr][rc][br][bc] = true;

    while (!q.empty()) {
        auto [crr, crc, cbr, cbc, cur] = q.front();
        q.pop();

        if (cur > 10) {
            cout << -1 << '\n';
            return;
        }

        if (board[crr][crc] == 'O') {
            cout << cur << '\n';
            return;
        }

        for (int d = 0; d < 4; d++) {
            int nrr = crr, nrc = crc, nbr = cbr, nbc = cbc;
            int rd, bd;
            roll(nrr, nrc, rd, d);
            roll(nbr, nbc, bd, d);

            if (board[nbr][nbc] == 'O')
                continue;

            if (nrr == nbr && nrc == nbc) {
                if (rd > bd) {
                    nrr -= dr[d];
                    nrc -= dc[d];
                } else {
                    nbr -= dr[d];
                    nbc -= dc[d];
                }
            }

            if (!visited[nrr][nrc][nbr][nbc]) {
                visited[nrr][nrc][nbr][nbc] = true;
                q.push({nrr, nrc, nbr, nbc, cur + 1});
            }
        }
    }
    cout << -1 << '\n';
    return;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> board[0];
    for (int i = 1; i < n-1; i++) {
        cin >> board[i];
        for (int j = 1; j < m-1; j++) {
            if (board[i][j] == 'B') {
                br = i;
                bc = j;
            } else if (board[i][j] == 'R') {
                rr = i;
                rc = j;
            }
        }
    }
    cin >> board[n-1];

    bfs(rr, rc, br, bc);
    return 0;
}