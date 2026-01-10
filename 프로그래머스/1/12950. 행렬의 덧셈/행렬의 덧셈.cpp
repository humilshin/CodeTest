#include <string>
#include <vector>

using namespace std;

//vector인데 size 지정없이 바로 대입을 하려고 해서 문제 생겼다. 

//size 지정
// vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
        
//     int column = arr1[0].size(); // 한 줄의 사이즈
//     int row = arr1.size(); // 줄들의 개수 
     
//     vector<vector<int>> answer(row, vector<int>(column));
//     for (int i = 0 ; i < row ; ++i ) {
//         for (int j = 0 ; j < column ; ++j) {
//             answer[i][j] = arr1[i][j] + arr2[i][j];
//         }
//     }
    
//     return answer;
// }

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
        
    int column = arr1[0].size(); // 한 줄의 사이즈
    int row = arr1.size(); // 줄들의 개수 
     
    vector<vector<int>> answer;
    for (int i = 0 ; i < row ; ++i ) {
        vector<int> temp;
        for (int j = 0 ; j < column ; ++j) {
            temp.push_back(arr1[i][j] + arr2[i][j]);
        }
        answer.push_back(temp);
    }
    
    return answer;
}