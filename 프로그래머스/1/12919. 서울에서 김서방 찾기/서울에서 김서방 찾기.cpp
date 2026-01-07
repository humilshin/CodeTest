#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    int temp;
    for (int i = 0 ; i < seoul.size() ; ++i) {
        if ("Kim" == seoul[i])
            temp = i;
    }
    return "김서방은 " + to_string(temp) + "에 있다";
}