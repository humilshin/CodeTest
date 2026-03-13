#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (long long num : numbers) {
        if (num % 2 == 0) {
            // 짝수: 마지막 비트 0→1, 1비트만 다름
            answer.push_back(num + 1);
        } else {
            // 홀수: LSB쪽에서 최초의 0을 찾아서 처리
            long long bit = 1;
            while (num & bit) bit <<= 1;
            // bit = 최하위 0비트 위치
            num |= bit;           // 그 0을 1로
            num &= ~(bit >> 1);   // 바로 아래 1을 0으로
            answer.push_back(num);
        }
    }
    return answer;
}