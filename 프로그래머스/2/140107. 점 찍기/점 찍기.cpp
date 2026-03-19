#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
   
    vector<pair<int,int>> max;
    for (int i = 0; i <= d; i = i + k) {
        max.push_back({i, sqrt((long long)d*d - (long long)i*i)});
    }
    
    for (const auto & entry : max) {
        if (entry.first % k == 0) {
            answer += entry.second / k + 1;
        }
    }
    
    return answer;
}