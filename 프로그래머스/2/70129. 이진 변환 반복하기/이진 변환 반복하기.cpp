#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toBinary(int n) {
    if (n == 0) return "0";
    string res = "";
    while (n > 0) {
        res += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

vector<int> solution(string s) {
    int transformCount = 0; // 변환 횟수
    int totalRemovedZeros = 0; // 제거된 0의 총 개수

    while (s != "1") {
        int onesCount = 0;
        int zerosInCurrent = 0;

        // 1. 0의 개수와 1의 개수를 분리하여 계산
        for (char c : s) {
            if (c == '0') zerosInCurrent++;
            else onesCount++;
        }

        // 2. 결과 업데이트
        totalRemovedZeros += zerosInCurrent;
        
        // 3. 1의 개수(onesCount)를 2진법으로 변환하여 s를 갱신
        s = toBinary(onesCount);
        transformCount++;
    }

    return {transformCount, totalRemovedZeros};
}