#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    unordered_map<int,int> um;
    
    // init
    for(int entry : tangerine) 
    {
        um[entry]++;
    }
    
    vector<pair<int, int>> v(um.begin(), um.end());
    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });
    
    int amount = tangerine.size();
    int size = v.size();
    for(const auto& entry : v) {
        int temp = size;
        size--;
        amount = amount - entry.second;
        if (amount < k)
            return temp;
    }
    return 1;

}

