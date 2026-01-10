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

// substr을 사용해보자!
// int solution(std::string t, std::string p) {
//     int answer = 0;
//     int len = p.size();
    
//     for (int i = 0; i <= t.size() - len; i++) {
//         std::string sub = t.substr(i, len);
        
//         if (sub <= p) {  // 문자열 비교 (길이가 같으면 숫자 비교와 동일)
//             answer++;
//         }
//     }
    
//     return answer;
// }
