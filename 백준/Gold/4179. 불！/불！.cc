#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 1001;
char grid[MAX][MAX];
int fdist[MAX][MAX];
int pdist[MAX][MAX];
int R, C;
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    memset(fdist, -1, sizeof(fdist));
    memset(pdist, -1, sizeof(pdist));

    queue<pair<int,int>> fq, pq;

    for (int i = 0; i < R; i++) {
        cin >> grid[i];
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 'F') {
                fdist[i][j] = 0;
                fq.push({i, j});
            }
            if (grid[i][j] == 'J') {
                pdist[i][j] = 0;
                pq.push({i, j});
            }
        }
    }

    while (!fq.empty()) {
        auto [r, c] = fq.front(); fq.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (grid[nr][nc] == '#' || fdist[nr][nc] != -1) continue;
            fdist[nr][nc] = fdist[r][c] + 1;
            fq.push({nr, nc});
        }
    }

    while (!pq.empty()) {
        auto [r, c] = pq.front(); pq.pop();
        if (r == 0 || r == R-1 || c == 0 || c == C-1) {
            cout << pdist[r][c] + 1;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (grid[nr][nc] == '#' || pdist[nr][nc] != -1) continue;
            if (fdist[nr][nc] != -1 && pdist[r][c] + 1 >= fdist[nr][nc]) continue;
            pdist[nr][nc] = pdist[r][c] + 1;
            pq.push({nr, nc});
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}