#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> answer;
bool found = false;

void dfs(string cur, vector<vector<string>>& tickets, vector<bool>& used, vector<string>& path) {
    if (path.size() == tickets.size() + 1) {
        answer = path;
        found = true;
        return;
    }
    
    for (int i = 0; i < tickets.size(); i++) {
        if (!used[i] && tickets[i][0] == cur) {
            used[i] = true;
            path.push_back(tickets[i][1]);
            
            dfs(tickets[i][1], tickets, used, path);
            
            if (found) return;  // 이미 찾았으면 바로 탈출
            
            path.pop_back();
            used[i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    // 알파벳 순 정렬 → DFS에서 먼저 찾는 경로가 정답
    sort(tickets.begin(), tickets.end());
    
    vector<bool> used(tickets.size(), false);
    vector<string> path;
    path.push_back("ICN");
    
    dfs("ICN", tickets, used, path);
    
    return answer;
}