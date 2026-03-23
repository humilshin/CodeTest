#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

vector<int> dv(int n) {
    vector<int> ret;
    for (int i = 1; i <= sqrt(n) ; i++) {
        if(i * (n / i) == n) {
            if (i != sqrt(n)) {
                ret.push_back(i);
            }
            ret.push_back(n / i);
        }
    }
    
    sort(ret.begin(), ret.end(), [](const int & a, const int & b) { return a > b; });

    return ret;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    queue<int> qa;
    queue<int> qb;
    
    for(const auto& entry : arrayA) {
        qa.push(entry);
    }
    
    for(const auto& entry : arrayB) {
        qb.push(entry);
    }
    
    while (qa.size() >= 2) {
        int temp1, temp2;
        temp1 = qa.front();
        qa.pop();
        temp2 = qa.front();
        qa.pop();
        qa.push(gcd(temp1,temp2));
    }
    
    while (qb.size() >= 2) {
        int temp1, temp2;
        temp1 = qb.front();
        qb.pop();
        temp2 = qb.front();
        qb.pop();
        qb.push(gcd(temp1,temp2));
    }
    
    vector<int> va = dv(qa.front());
    vector<int> vb = dv(qb.front());

    int answer_a = 0;
    int answer_b = 0;

    for (int entry : va) {
        bool check = true;
        for (int i = 0 ; i < arrayB.size() ; i++) {
            if ( arrayB[i] % entry == 0) {
                check = false;
                break;
            }
        }
        if (check == true) {
            answer_a = entry;
            break;
        }
    }
    
    for (int entry : vb) {
        bool check = true;
        for (int i = 0 ; i < arrayA.size() ; i++ ) {
            if ( arrayA[i] % entry == 0) {
                check = false;
                break;
            }
        }
        if (check == true) {
            answer_b = entry;
            break;
        }
    }
    
    if (answer_a >= answer_b)
        return answer_a;
    else
        return answer_b;
}