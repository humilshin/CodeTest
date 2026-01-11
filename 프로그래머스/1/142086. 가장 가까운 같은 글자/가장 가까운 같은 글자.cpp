#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<char, int> data;
    
    for (int i = 0 ; i < s.size() ; ++i) {
        
        //search
        auto it = data.find(s[i]);
        //search success
        if(it != data.end()) {
            int temp = it->second;
            answer.push_back(i - temp);
            data[s[i]] = i;
        }
        //search fail
        else {
            answer.push_back(-1);
            data.insert({s[i], i});
        }
    }
    
    return answer;
}