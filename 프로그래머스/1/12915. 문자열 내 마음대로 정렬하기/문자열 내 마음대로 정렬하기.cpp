#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 람다 함수
vector<string> solution(vector<string> strings, int n) {
    sort(strings.begin(), strings.end(), [n](string a, string b) {
        if (a[n] == b[n]) {
            return a < b;  // n번째 글자가 같으면 사전순
        }
        return a[n] < b[n];  // n번째 글자 기준 정렬
    });
    
    return strings;
}