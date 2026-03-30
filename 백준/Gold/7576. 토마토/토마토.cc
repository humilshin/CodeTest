#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> box;
int N, M; // N: 세로(row), M: 가로(col)
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int BFS(const vector<pair<int, int>> &start)
{
    queue<pair<int, int>> q;
    int max_val = 1; // 토마토가 하나라도 있으면 최소값은 1 (날짜로는 0일)

    for (const auto &entry : start)
        q.push(entry);

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M && box[nr][nc] == 0)
            {
                box[nr][nc] = box[r][c] + 1;
                q.push({nr, nc});
                max_val = max(max_val, box[nr][nc]);
            }
        }
    }
    return max_val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 중요: 문제에서는 가로(M), 세로(N) 순서로 줍니다.
    if (!(cin >> M >> N))
        return 0;

    box.assign(N, vector<int>(M));
    vector<pair<int, int>> start;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> box[i][j];
            if (box[i][j] == 1)
                start.push_back({i, j});
        }
    }

    int result = BFS(start);

    // BFS 후 안 익은 토마토 확인
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (box[i][j] == 0)
            {
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    // 결과값에서 1을 빼야 실제 '경과 일수'가 됩니다.
    cout << result - 1 << "\n";

    return 0;
}