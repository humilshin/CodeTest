#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int size = order.size();
    stack<int> s;
    int index = 0;

    for (int i = 1; i <= size; i++) {
        s.push(i);

        while (!s.empty() && s.top() == order[index]) {
            s.pop();
            answer++;
            index++;
        }
    }
    return answer;
}