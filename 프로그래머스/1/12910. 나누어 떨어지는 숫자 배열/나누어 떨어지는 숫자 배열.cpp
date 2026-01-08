#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
        
    for (int entry : arr) {
        if (entry % divisor == 0) {
            answer.push_back(entry);
        }
    }
    
    if(!answer.empty()) {
        sort(answer.begin(), answer.end());
    }
    else 
    {
        answer.push_back(-1);
    }

    
    return answer;
}