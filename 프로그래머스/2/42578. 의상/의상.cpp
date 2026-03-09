#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string,int> type;
    int answer = 1; 
    
    for (vector<string> entry : clothes) {
        type[ entry[1] ]++;
    }
    for (auto entry : type) {
        answer *= (entry.second + 1);         
    }
    
    return answer-1;
}