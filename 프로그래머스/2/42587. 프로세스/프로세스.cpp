#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int size = priorities.size();
    queue <pair<int, int>> q;
    priority_queue <int> pq;
    for (int i = 0 ; i < size ; i++) { 
        q.push({priorities[i], i}); // location과 priority 저장 이후 queue를 통해 순환
        pq.push(priorities[i]);
    }
  
    int order = 0;
    while (1) { //queue에서 넣었다 뺀다 근데 priority 최대를 찾는다.
        if (q.front().first == pq.top()) {// 같을 경우
            if (q.front().second == location)
                return order+1;
            q.pop(); pq.pop();
            order++;
        }
        else {
            int ftemp = q.front().first;
            int stemp = q.front().second;
            q.pop();
            q.push({ftemp, stemp});
        } 
    }
    
    int answer = 0;
    return answer;
}