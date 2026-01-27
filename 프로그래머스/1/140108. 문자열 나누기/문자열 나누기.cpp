#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int size = s.length();
    
    char temp = '0';
    int yes = 0;
    int no = 0;
    for (int i = 0 ; i < size ; ++i){
        if (temp == '0'){
            temp = s[i];  
            yes++;
        }
        
        else if (temp == s[i]) {
            yes++;
        }
        else {
            no++;
        }
        
        if (yes > 0 && no > 0 && yes == no) {
            temp = '0';
            yes = 0;
            no = 0;
            answer++;
        }
        else if (i == size - 1)
            answer++;

    }
    return answer;
}