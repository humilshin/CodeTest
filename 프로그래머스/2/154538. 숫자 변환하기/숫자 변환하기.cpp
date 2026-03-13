#include <queue>
#include <unordered_set>
using namespace std;

int solution(int x, int y, int n) {
    if (x == y) return 0;
    
    queue<pair<int,int>> q;
    unordered_set<int> visited;
    
    q.push({x, 0});
    visited.insert(x);
    
    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        for (int next : {cur + n, cur * 2, cur * 3}) {
            if (next == y) return cnt + 1;
            if (next < y && !visited.count(next)) {
                visited.insert(next);
                q.push({next, cnt + 1});
            }
        }
    }
    
    return -1;
}