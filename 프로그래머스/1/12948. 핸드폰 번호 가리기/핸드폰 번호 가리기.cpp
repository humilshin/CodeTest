#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    
    string answer = phone_number;
    for (int i = 0 ; i < phone_number.length()-4 ; i++) {
        answer[i] = '*';
    }
    
    return answer;
}

// string solution(string phone_number) {
//     int len = phone_number.size();
//     return string(len - 4, '*') + phone_number.substr(len - 4);
// }

// string solution(string phone_number) {
//     fill(phone_number.begin(), phone_number.end() - 4, '*');
//     return phone_number;
// }

