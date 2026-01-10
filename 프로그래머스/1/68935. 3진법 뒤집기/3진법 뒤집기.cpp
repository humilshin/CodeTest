#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    // 3진법 변환 (나머지를 저장하면 자동으로 뒤집힌 순서)
    std::vector<int> d3;
    while (n > 0) {
        d3.push_back(n % 3);
        n /= 3;
    }
    
    // 10진법으로 변환
    int base = 1;
    for (int i = d3.size() - 1; i >= 0; --i) {
        answer += d3[i] * base;
        base *= 3;
    }
    
    return answer;
}