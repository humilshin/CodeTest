#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    queue<int> q;
    
    int size = sequence.size();
    int sum = 0;
    int index = 0;
    
    for (int i = size - 1 ; i >= 0; i--) {
        if (sum == 0) // 초기 또는 Stack이 비워졌을때 top index 지정
            index = i;
        
        if (sum < k) { // 합이 k보다 작을때는 Push
            q.push(sequence[i]);
            sum += sequence[i];
        }

        if (sum > k) {
            while(1) {
                sum -= q.front();
                q.pop();
                index--;
                if (sum <= k) 
                    break;
            }            
        }
        
        if (sum == k) {
            if (i > 0 && (q.front() == sequence[i-1])) {
                sum -= q.front();
                q.pop();
                index--;
            }
                
            else 
                break;
        }    
    }
    
    answer.push_back(index - q.size() + 1);
    answer.push_back(index);
    
    return answer;
}