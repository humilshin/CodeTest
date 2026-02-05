#include <string>
#include <vector>

using namespace std;

void save(char type, int offset, int* arr) {
    
    if (type == 'R') arr[0] += offset;
    else if (type == 'T') arr[1] += offset;
    else if (type == 'C') arr[2] += offset;
    else if (type == 'F') arr[3] += offset;
    else if (type == 'J') arr[4] += offset;
    else if (type == 'M') arr[5] += offset;
    else if (type == 'A') arr[6] += offset;
    else if (type == 'N') arr[7] += offset;
}

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int size = survey.size();
    int arr[8] = {0,}; //RTCFJMAN
    
    for (int i = 0 ; i < size ; ++i)
    {
        char left = survey[i][0];
        char right = survey[i][1];
        
        if (choices[i] == 1) save(left, 3 ,arr);
        else if (choices[i] == 2) save(left, 2 ,arr);
        else if (choices[i] == 3) save(left, 1 ,arr);
        else if (choices[i] == 5) save(right, 1 ,arr);
        else if (choices[i] == 6) save(right, 2 ,arr);
        else if (choices[i] == 7) save(right, 3 ,arr);
    }   
    
    if (arr[0] >= arr[1]) 
        answer += 'R';
    else 
        answer += 'T';
        
    if (arr[2] >= arr[3]) 
        answer += 'C';
    else 
        answer += 'F';
        
    if (arr[4] >= arr[5]) 
        answer += 'J';
    else 
        answer += 'M';
        
    if (arr[6] >= arr[7]) 
        answer += 'A';
    else 
        answer += 'N'; 
    
    return answer;
}

