#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<bool> visited;

int bfs(int start, const vector<vector<int>> branch, int n) {
    int answer = 0;
    visited.assign(n, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        answer++;
        
        for (int entry : branch[temp]) {
            if (visited[entry] == false) {
                visited[entry] = true;
                q.push(entry);
            }

        }
    }
    
    return answer;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 10000;
    int size = wires.size();
    
    for (int i = 0 ; i < size ; i++) { // case loop
        vector<int> selected;
        vector<vector<int>> branch(n+1);
        for (int j = 0; j < size ; j++) { // init loop
            if (i == j) {
                selected.push_back(wires[j][0]);
                selected.push_back(wires[j][1]);
            }
            else {
                branch[wires[j][0]].push_back(wires[j][1]);
                branch[wires[j][1]].push_back(wires[j][0]);
            }
        }
        
        int a1 = bfs(selected[0], branch, n+1);
        int a2 = bfs(selected[1], branch, n+1);
        int tempanswer;
        if(a1 >= a2) {
            tempanswer = a1 - a2;
        }
        else {
            tempanswer = a2 - a1;
        }
        
        if (tempanswer <= answer)
            answer = tempanswer;        
    }
    return answer;
}