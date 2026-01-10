#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    vector<string> parts;
    for (int i = 0 ; i < t.length() - p.length() + 1; i++) {
        string temp = "";
        for (int j = 0; j <p.length() ; j++) {
           temp += t[i + j]; 
        }      
        parts.push_back(temp);
    }
     
    for (const auto& entry : parts) {
        if(entry <= p)
            answer++;
    }
    
    return answer;
}