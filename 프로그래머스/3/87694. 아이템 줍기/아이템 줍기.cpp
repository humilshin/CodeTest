#include <bits/stdc++.h>
using namespace std;

int board[102][102];
bool visited[102][102];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    
    // 1. 좌표 2배 확장 후 테두리/내부 표시
    for (auto& r : rectangle) {
        int x1 = r[0]*2, y1 = r[1]*2;
        int x2 = r[2]*2, y2 = r[3]*2;

        // 테두리 표시 (1)
        for (int x = x1; x <= x2; x++) {
            if (!board[y1][x]) board[y1][x] = 1;
            if (!board[y2][x]) board[y2][x] = 1;
        }
        for (int y = y1; y <= y2; y++) {
            if (!board[y][x1]) board[y][x1] = 1;
            if (!board[y][x2]) board[y][x2] = 1;
        }

        // 내부 표시 (2) - 테두리를 덮어쓰지 않게 나중에
        for (int y = y1+1; y < y2; y++)
            for (int x = x1+1; x < x2; x++)
                board[y][x] = 2;
    }

    // 2. BFS
    queue<tuple<int,int,int>> q; // x, y, dist
    int sx = characterX*2, sy = characterY*2;
    int ex = itemX*2,      ey = itemY*2;

    q.push({sx, sy, 0});
    visited[sy][sx] = true;

    while (!q.empty()) {
        auto [cx, cy, dist] = q.front(); q.pop();

        if (cx == ex && cy == ey) return dist / 2;

        for (int d = 0; d < 4; d++) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx < 0 || ny < 0 || nx > 100 || ny > 100) continue;
            if (visited[ny][nx]) continue;
            if (board[ny][nx] != 1) continue; // 테두리만 이동 가능

            visited[ny][nx] = true;
            q.push({nx, ny, dist + 1});
        }
    }

    return -1;
}