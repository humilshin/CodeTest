#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    vector<int> Month = {31, 29, 31, 30, 31, 30 ,31, 31, 30 ,31, 30, 31};
    vector<string> DAY = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int TotalDay = 0;
    
    for (int i = 0 ; i < a-1; ++i) {
        TotalDay += Month[i];
    }
    
    TotalDay += b;
  
    return DAY[ ( TotalDay - 1 ) % 7 ];
}