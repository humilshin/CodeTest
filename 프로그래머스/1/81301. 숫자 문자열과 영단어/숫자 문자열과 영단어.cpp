#include <string>
#include <vector>

using namespace std;

int check (string s) {
    if (s == "zero")
        return 0;
    if (s == "one")
        return 1;
    else if (s == "two")
        return 2;
    else if (s == "three")
        return 3;
    else if (s == "four")
        return 4;
    else if (s == "five")
        return 5;
    else if (s == "six")
        return 6;
    else if (s == "seven")
        return 7;
    else if (s == "eight")
        return 8;
    else if (s == "nine")
        return 9;
    else
    return -1;
}

int solution(string s) {
    string answer;
    
    string temp;
    for (char c : s) {
        if ( c >= '0' && c <= '9') {
            answer += c;
            continue;
        }
        else {
            temp += c;
            if (check(temp) == -1){
                continue;
            }
            else {
                answer += to_string(check(temp));
                //answer += '0' + check(temp);
                temp = "";
            } 
        }
    }
    
    return stoi(answer);
}