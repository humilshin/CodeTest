#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = 0;
    long long sum2 = 0;
    int answer = 0;
    queue<int> q1;
    queue<int> q2;
    int size = queue1.size();
    for (int i = 0 ; i < size ; i++) {
        q1.push(queue1[i]);
        sum1 += queue1[i];
        q2.push(queue2[i]);
        sum2 += queue2[i];
    }
    
    while (1) {
        if (sum1 == sum2)
            return answer;
        
        if (answer > 3 * size)
            return -1;
        
        if ( sum1 > sum2 ) {
            int temp = q1.front();
            sum1 -= temp;
            sum2 += temp;
            q2.push(temp);
            q1.pop();
        }   
        
        else if ( sum1 < sum2 ) {
            int temp = q2.front();
            sum1 += temp;
            sum2 -= temp;
            q1.push(temp);
            q2.pop();  
        }
        
        answer++;
    }
}