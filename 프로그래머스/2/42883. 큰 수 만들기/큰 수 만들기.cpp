#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string result = "";

    for (char c : number) {
        // 스택 top보다 현재 숫자가 크면, top을 제거 (k번까지)
        while (!result.empty() && k > 0 && result.back() < c) {
            result.pop_back();
            k--;
        }
        result.push_back(c);
    }

    // 아직 k가 남았으면 뒤에서 제거
    result.erase(result.end() - k, result.end());

    return result;
} 