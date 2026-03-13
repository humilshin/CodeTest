#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    unordered_map<int, int> um1;
    unordered_set<int> us1;
    unordered_map<int, int> um2;
    unordered_set<int> us2(topping.begin(), topping.end());
    int size = topping.size();

    for(int entry : topping) {
        um2[entry]++;
    }
    
    for(int i = 0 ; i < size ; i++) {
        um1[topping[i]]++;
        us1.insert(topping[i]);
        um2[topping[i]]--;
        if(um2[topping[i]] == 0)
            us2.erase(topping[i]);
        
        if(us1.size() == us2.size())
            answer++;
    }
    
    return answer;
}