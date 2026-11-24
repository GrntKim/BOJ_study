#include <iostream>
#include <vector>

using namespace std;

int n, m, k, ans = 0;

int stickers[105][15][15];
int src[45][45];
vector<pair<int, int>> sticker_size;

bool fits(int k) {
    int sr = sticker_size[k].first;
    int sw = sticker_size[k].second;

    for (int r = 0; r <= n - sr; r++) {
        for (int c = 0; c <= m - sw; c++) {
            bool skip = false;
            for (int i = r; i < r + sr; i++) {
                for (int j = c; j < c + sw; j++) {
                    if (stickers[k][i-r][j-c] && src[i][j]) {
                        skip = true;
                        break;
                    }
                }
                if (skip) break;
            }
            if (skip) continue;

            for (int i = r; i < r + sr; i++) {
                for (int j = c; j < c + sw; j++) {
                    if (stickers[k][i-r][j-c]) {
                        src[i][j] = 1;
                        ans++;
                    }
                }
            }
            return true;
        }
    }
    return false;
}

void rotate_r90(int k) {
    int r = sticker_size[k].first;
    int c = sticker_size[k].second;
    int tmp[c][r];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            tmp[j][r-1-i] = stickers[k][i][j];
        }
    }
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            stickers[k][i][j] = 0;
        }
    }

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            stickers[k][i][j] = tmp[i][j];
        }
    }

    sticker_size[k] = {c, r};
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        sticker_size.push_back({r, c});
        for (int y = 0; y < r; y++) {
            for (int x = 0; x < c; x++) {
                cin >> stickers[i][y][x];
            }
        }
    }

    for (int i = 0; i < k; i++)
        for (int j = 0; j < 4; j++) {
            if (fits(i)) break;
            rotate_r90(i);
        }

    cout << ans << '\n';

    return 0;
}