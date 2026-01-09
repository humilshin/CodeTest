#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    string temp;
    int answer = 0;
    for (int entry : numbers)
        temp += to_string(entry);
    
    for (int i=0 ; i <10 ; ++i) {
        if (temp.find(to_string(i)) == string::npos) {
            answer += i;
        }
    }
    return answer;
}


// int solution(vector<int> numbers) {
//     int answer = 45;  // 0~9 합
//     for (int n : numbers)
//         answer -= n;
//     return answer;
// }