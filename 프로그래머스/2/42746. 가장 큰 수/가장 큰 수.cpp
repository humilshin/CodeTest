#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare (string a, string b) {
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    vector<string> vtemp;
    string answer = "";
    
    for (int temp : numbers)
        vtemp.push_back(to_string(temp));
    
    sort(vtemp.begin(), vtemp.end(), compare);    
    
    if(vtemp[0] == "0")
        return "0";
    
    for (string entry : vtemp)
        answer += entry;
    return answer;
    
    
}