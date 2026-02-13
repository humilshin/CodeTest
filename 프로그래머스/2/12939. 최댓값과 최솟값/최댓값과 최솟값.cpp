#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> numbers;
    stringstream ss(s);
    string token;
    while (ss >> token) {
        numbers.push_back(stoi(token));
    }
    
    int max = *max_element(numbers.begin(), numbers.end());
    int min = *min_element(numbers.begin(), numbers.end());
    
    answer += to_string(min);
    answer += " ";
    answer += to_string(max);

    return answer;
}