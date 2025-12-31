#include <string>

using namespace std;

bool solution(int x) {
    int sum = 0;
    int temp = x;
    
    // 각 자릿수의 합 계산
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    
    // x가 자릿수 합으로 나누어 떨어지면 하샤드 수
    return x % sum == 0;
}