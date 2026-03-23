#include <string>
#include <set>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void dfs(string& numbers, string current, vector<bool>& used, set<int>& result) {
    if (!current.empty()) {
        int num = stoi(current);
        if (isPrime(num)) result.insert(num);
    }
    
    for (int i = 0; i < numbers.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        current += numbers[i];
        dfs(numbers, current, used, result);
        current.pop_back();
        used[i] = false;
    }
}

int solution(string numbers) {
    set<int> result;
    vector<bool> used(numbers.size(), false);
    string current = "";
    dfs(numbers, current, used, result);
    return result.size();
}