#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> us;
    int size = elements.size();
    
    for (int i = 0 ; i < size ; i++) {
        elements.push_back(elements[i]);
    }
    
    for(int n = 1 ; n <= size ; n++) {
        for (int i = 0 ; i < size ; i++) {
            int temp = 0;
            for (int j = i ; j < i+n ; j++) {
               temp += elements[j];
            }
            us.insert(temp);
        }
    }
    
    
    return us.size();
}