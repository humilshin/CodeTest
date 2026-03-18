#include <string>
#include <queue>
#include <algorithm>

using namespace std;


bool visited[100][100];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int startX, int startY, const vector<string>& maps, int n, int m) {
    int daySum = 0;
    queue<pair<int, int>> q;
    
    q.push({startX, startY});
    visited[startX][startY] = true;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        daySum += (maps[x][y] - '0');
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && maps[nx][ny] != 'X') {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return daySum;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int n = maps.size();
    int m = maps[0].size();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) visited[i][j] = false;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maps[i][j] != 'X' && !visited[i][j]) {
                answer.push_back(bfs(i, j, maps, n, m));
            }
        }
    }

    if(answer.empty()) return {-1};
    sort(answer.begin(), answer.end());
    
    return answer;
}