#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int weight[] = {781, 156, 31, 6, 1};
    string vowels = "AEIOU";
    int answer = 0;

    for (int i = 0; i < word.size(); i++) {
        int idx = vowels.find(word[i]);  // A=0, E=1, I=2, O=3, U=4
        answer += idx * weight[i] + 1;
    }

    return answer;
}

// "AAAAE" 각 자리:
// i=0: A(idx=0) → 0 * 781 + 1 = 1    ← "A" 자체를 세는 +1
// i=1: A(idx=0) → 0 * 156 + 1 = 1    ← "AA" 자체를 세는 +1
// i=2: A(idx=0) → 0 *  31 + 1 = 1    ← "AAA" 자체를 세는 +1
// i=3: A(idx=0) → 0 *   6 + 1 = 1    ← "AAAA" 자체를 세는 +1
// i=4: E(idx=1) → 1 *   1 + 1 = 2    ← "AAAAA" 건너뜀 + "AAAAE" 자체

// 합계 = 1 + 1 + 1 + 1 + 2 = 6 ✓