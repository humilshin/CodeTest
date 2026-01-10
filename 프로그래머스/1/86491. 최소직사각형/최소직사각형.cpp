#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    vector<int> vv;
    vector<int> hv;
    for (vector<int> entry : sizes) {
        if (entry[0] < entry [1]) {
            hv.push_back(entry[1]);
            vv.push_back(entry[0]);
        }
        else {
            hv.push_back(entry[0]);
            vv.push_back(entry[1]);
        }
    }
    
    return *max_element( hv.begin(), hv.end() ) * *max_element( vv.begin(), vv.end() );
}