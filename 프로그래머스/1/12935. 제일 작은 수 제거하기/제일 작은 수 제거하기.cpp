#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    auto it = min_element(arr.begin(), arr.end());
    arr.erase(it);
    
    if (arr.empty()) {
        arr.push_back(-1);
        return arr;
    }
    else 
        return arr;
}