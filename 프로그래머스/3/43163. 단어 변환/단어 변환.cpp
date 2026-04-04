#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<bool> visit;

bool checkdiff(const string & a, const string & b) {
    int size = a.length();
    int n = 0;
    for (int i = 0 ; i < size ; i++)
    {
        if( a[i] != b[i] )
            n++;
    }
    if (n == 1)
        return true;
    else 
        return false;
}

int BFS(string word, string target, const vector<string> & words) {
    queue<pair<string,int>> q;
    q.push({word, 0});
    
    while(!q.empty()){
        string temp = q.front().first;
        int index = q.front().second;
        q.pop();
        
        if (target == temp) 
            return index;
        
        for (const auto & entry : words) {
            if (checkdiff(entry, temp))
                q.push({entry,index + 1});
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 1;
    int length = begin.length();
    int size = words.size();
    

    if (find(words.begin(), words.end(), target) == words.end())
        return 0;
    
    return BFS(begin, target, words);
}