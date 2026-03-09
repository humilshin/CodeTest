#include <vector>
using namespace std;

int answer = 0;
vector<bool> visited;

void dfs(int k, int count, vector<vector<int>>& dungeons) {
    answer = max(answer, count);
    
    for (int i = 0; i < dungeons.size(); i++) {
        // 방문 안 했고, 피로도가 최소 필요 피로도 이상이면
        if (!visited[i] && k >= dungeons[i][0]) {
            visited[i] = true;
            dfs(k - dungeons[i][1], count + 1, dungeons);
            visited[i] = false;  // 백트래킹
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    answer = 0;
    visited.assign(dungeons.size(), false);
    dfs(k, 0, dungeons);
    return answer;
}