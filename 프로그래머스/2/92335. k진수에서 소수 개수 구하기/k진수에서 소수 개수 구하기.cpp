#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;

// k진법 변환
string BaseChange(int n, int k) {
    if (n == 0) return "0";
    
    string result;
    while (n > 0) {
        result += to_string(n % k);  // 나머지 추가
        n /= k;
    }
    
    reverse(result.begin(), result.end());
    return result;   
}

bool IsPrime(long long n) {
    if (n < 2) return false;           // 0, 1은 소수 아님

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)                // 나눠떨어지면 소수 아님
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string bc = BaseChange(n, k);
    
    vector<string> tokens;
    stringstream ss(bc);
    string token;

    while (getline(ss, token, '0')) {
        if (!token.empty())    
            tokens.push_back(token);
    }

    for (const auto& t : tokens) {
        if(IsPrime(stoll(t)))
            answer++;
    }
    
    return answer;
}