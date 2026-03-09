#include <vector>
#include <iostream>

using namespace std;

int dfs(const vector<int>& numbers, int target, int depth, int sum) {
    if (depth == numbers.size()) {  // 모든 숫자를 탐색한 경우
        return sum == target ? 1 : 0;  // 타겟 넘버를 만들었다면 1 반환
    }
    
    // 현재 숫자를 더하거나 빼는 두 가지 경우 탐색
    return dfs(numbers, target, depth + 1, sum + numbers[depth]) +
           dfs(numbers, target, depth + 1, sum - numbers[depth]);
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, target, 0, 0);
}
