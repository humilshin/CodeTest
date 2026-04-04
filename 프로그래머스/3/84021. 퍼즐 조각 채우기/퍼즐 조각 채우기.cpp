#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// BFS로 연결된 칸들을 추출
vector<pair<int,int>> bfs(vector<vector<int>>& board, int sr, int sc, int target, vector<vector<bool>>& visited) {
    int n = board.size();
    queue<pair<int,int>> q;
    vector<pair<int,int>> cells;

    visited[sr][sc] = true;
    q.push({sr, sc});
    cells.push_back({sr, sc});

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nr = r + dx[d];
            int nc = c + dy[d];
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
            if (visited[nr][nc] || board[nr][nc] != target) continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
            cells.push_back({nr, nc});
        }
    }
    return cells;
}

// 좌표 정규화: (0,0) 기준으로 맞추고 정렬
vector<pair<int,int>> normalize(vector<pair<int,int>>& shape) {
    int minR = INT_MAX, minC = INT_MAX;
    for (auto [r, c] : shape) {
        minR = min(minR, r);
        minC = min(minC, c);
    }
    vector<pair<int,int>> result;
    for (auto [r, c] : shape) {
        result.push_back({r - minR, c - minC});
    }
    sort(result.begin(), result.end());
    return result;
}

// 90도 회전: (r, c) → (c, -r)
vector<pair<int,int>> rotate(vector<pair<int,int>> shape) {
    vector<pair<int,int>> rotated;
    for (auto [r, c] : shape) {
        rotated.push_back({c, -r});
    }
    return normalize(rotated);
}

// 4방향 회전하며 매칭 확인
bool match(vector<pair<int,int>>& blank, vector<pair<int,int>> piece) {
    if (blank.size() != piece.size()) return false;
    for (int rot = 0; rot < 4; rot++) {
        if (blank == piece) return true;
        piece = rotate(piece);
    }
    return false;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int n = game_board.size();

    // 1단계: game_board에서 빈 칸(0) 그룹 추출
    vector<vector<pair<int,int>>> blanks;
    {
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!visited[i][j] && game_board[i][j] == 0) {
                    vector<pair<int,int>> raw = bfs(game_board, i, j, 0, visited);
                    blanks.push_back(normalize(raw));
                }
    }

    // 2단계: table에서 퍼즐 조각(1) 그룹 추출
    vector<vector<pair<int,int>>> pieces;
    {
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!visited[i][j] && table[i][j] == 1) {
                    vector<pair<int,int>> raw = bfs(table, i, j, 1, visited);
                    pieces.push_back(normalize(raw));
                }
    }

    // 3단계: 빈 칸과 조각 매칭
    int answer = 0;
    vector<bool> used(pieces.size(), false);

    for (auto& blank : blanks) {
        for (int j = 0; j < pieces.size(); j++) {
            if (used[j]) continue;
            if (match(blank, pieces[j])) {
                used[j] = true;
                answer += blank.size();
                break;
            }
        }
    }

    return answer;
}