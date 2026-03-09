#include <string>
#include <vector>

using namespace std;

vector<int> calculate(int row,int first, int last) {
    vector<int> temp;
    for(int i = first ; i <= last ; i++) 
    {
        if( i <= row ) 
            temp.push_back(row+1);
        else 
            temp.push_back(i+1);
    }
    return temp;
}

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    vector<int> temp;
    //left 가 몇번째 줄 n인지 찾기
    int lrow = left / n; 
    int lmod = left % n;
    //right가 몇번쨰 n 줄인지 찾기
    int rrow = right / n;
    int rmod = right % n;
    
    if (lrow == rrow) {
        // lrow 줄에서 lmod에서 rmod까지 출력
        temp = calculate(lrow, lmod, rmod);
        answer.insert(answer.end(), temp.begin(), temp.end());
    }
    else{
        // left 줄 입력
        temp = calculate(lrow, lmod, n-1);
        answer.insert(answer.end(), temp.begin(), temp.end());
        // 사이 입력
        for (int i = lrow + 1; i < rrow; i++) {
            temp = calculate(i, 0, n-1);
            answer.insert(answer.end(), temp.begin(), temp.end());
        }
        // right 줄 입력
         temp = calculate(rrow, 0, rmod);
         answer.insert(answer.end(), temp.begin(), temp.end());
    }

    return answer;
}