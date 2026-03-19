#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(int storey) {
    int answer = 0;
    vector<int> numbers;
    while(storey != 0) {
        numbers.push_back(storey % 10);
        storey /= 10;
    }
    numbers.push_back(0);
    
    for (int i = 0 ; i < numbers.size() ; i++) {
        if (numbers[i] < 5) { // a case
            answer += numbers[i];
        }
        
        else if (numbers[i] == 5) {
            if (numbers[i+1] >= 5) {
                answer += 5;
                numbers[i+1]++; // carry 전파!
            } else {
                answer += 5; // 내려감, carry 없음
            }
        }
        else { // b case
            answer += 10 - numbers[i];
            numbers[i+1]++;
        }
    }
    return answer;
}