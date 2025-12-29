#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> numbers;
    
    while (1) {
        numbers.push_back(n % 10);
        if (n < 10) 
            break;
        n /= 10;
    }
    
    sort(numbers.begin(), numbers.end(), greater<>());
    
    for (int entry : numbers)
    {
        answer += entry;
        answer *= 10;
    }
    
    answer /= 10;
    return answer;
}

/* 
// String으로 변환 후 자릿수 정렬
long long solution(long long n) {
    string str = to_string(n);
    
    // 내림차순 정렬
    sort(str.begin(), str.end(), greater<char>());
    
    return stoll(str);
} 
*/

