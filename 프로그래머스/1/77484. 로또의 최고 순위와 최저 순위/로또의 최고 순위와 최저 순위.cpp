#include <string>
#include <vector>

using namespace std;

int lotto_rank (int n) {
    if ( n == 6) {
        return 1;
    }
    else if (n == 5) {
        return 2;
    }
    else if (n == 4) {
        return 3;
    }
    else if (n == 3) {
        return 4;
    }
    else if (n == 2) {
        return 5;
    }
    else {
        return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int check = 0;
    int zero = 0;
    for (int temp1 : win_nums) {
        for (int temp2 : lottos) {
            if (temp1 == temp2) {
                check++;
                break;
            }
        }
    }
    
    for (int entry : lottos) {
        if (entry == 0) {
            zero++;
        }
    }

    
    answer.push_back(lotto_rank(check + zero));
    answer.push_back(lotto_rank(check));
    
    return answer;
}