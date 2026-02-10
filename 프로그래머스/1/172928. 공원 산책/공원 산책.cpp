#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int vsize = park.size();
    int hsize = park[0].length();
    
    int loc_x;
    int loc_y;
    
    for (int i = 0 ; i < vsize ; i++) {
        for (int j = 0 ; j < hsize ; j++)
        {
            if(park[i][j] == 'S')
            {
                loc_x = j;
                loc_y = i;
            }
        }
    }
    
    for (string entry : routes) {
        char direction = entry[0];
        int distance = stoi(entry.substr(2));
        
        if (direction == 'N'){
            if (loc_y - distance < 0)
                continue;
            bool check = true;
            for (int i = 1 ; i <= distance ; i++){
                if(park[loc_y - i][loc_x] == 'X')
                    check = false;
            }
            
            if(check) {
                loc_y = loc_y - distance;
            }
        }   
        else if (direction == 'W'){
            if (loc_x - distance < 0)
                continue;
            bool check = true;
            for (int i = 1 ; i <= distance ; i++){
                if(park[loc_y][loc_x - i] == 'X')
                    check = false;
            }
            
            if(check) {
                loc_x = loc_x - distance;
            }
        }
        else if (direction == 'E'){
            if (loc_x + distance >= hsize)
                continue;
            bool check = true;
            for (int i = 1 ; i <= distance ; i++){
                if(park[loc_y][loc_x + i] == 'X')
                    check = false;
            }
            
            if(check) {
                loc_x = loc_x + distance;
            }
        }
        else if (direction == 'S'){
            if (loc_y + distance >= vsize)
                continue;
            bool check = true;
            for (int i = 1 ; i <= distance ; i++){
                if(park[loc_y+i][loc_x] == 'X')
                    check = false;
            }
            
            if(check) {
                loc_y = loc_y + distance;
            }
        }
        
    }
    
    answer.push_back(loc_y);
    answer.push_back(loc_x);
    return answer;
}

