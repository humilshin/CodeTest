#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int h[2] = {50, 0};
    int v[2] = {50, 0};
    
    int vlength = wallpaper.size() ;
    int hlength = wallpaper[0].length();

    for (int i = 0 ; i < vlength ; ++i){
        for (int j = 0 ; j < hlength; ++j) {
            if (wallpaper[i][j] == '#') {
                if (h[0] >= j) h[0] = j;
                if (h[1] <= j) h[1] = j;
                if (v[0] >= i) v[0] = i;
                if (v[1] <= i) v[1] = i;
            }
        }
    }
    
    answer.push_back(v[0]);
    answer.push_back(h[0]);
    answer.push_back(v[1] + 1);
    answer.push_back(h[1] + 1);
    return answer;
}