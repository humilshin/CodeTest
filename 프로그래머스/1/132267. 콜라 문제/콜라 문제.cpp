#include <string>
#include <vector>

using namespace std;

int cola(int x, int a, int b ) {
    // x : 마트에 제출하는 빈병의 수
    // a : 콜라 b병에 필요한 빈병 반환 개수
    // b: : 반환 해주는 콜라 b병
    
    int temp = x / a;
    
    return temp * b;
}

int solution(int a, int b, int n) {
    int answer = 0;
    
    while (n >= a)
    {
        int reward_cola  = cola(n, a, b);
        int remain_cola  =  n - (reward_cola / b) * a; 
        n = remain_cola  + reward_cola; 
        answer += reward_cola;
    }
    
    return answer;
}