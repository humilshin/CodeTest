#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int k, int m, vector<int> score) {
    priority_queue<int> pq(score.begin(), score.end());
    
    int answer = 0;
        
    int sum = 0;
    
    while (pq.size() >= m)
    {
        for (int i = 0; i < m ; ++i) {
            int max = pq.top();
            sum += max;
            pq.pop();
            if (i == m - 1)    
                answer += m * max;
        }
    }
    
    return answer;
}