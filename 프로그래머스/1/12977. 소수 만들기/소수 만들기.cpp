#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool check_prime(int n) { 
  for( int i = 2 ; i <= sqrt(n) ; ++i) {
      if ( ( n / i ) * i == n)
          return false;
  }      
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    int size = nums.size();
    for (int i = 0 ; i < size -2 ; ++i) {
        for (int j = i+1 ; j < size - 1 ; ++j) {
            for (int k = j+1 ; k < size ; ++k) {
                if (check_prime(nums[i] + nums[j]+ nums[k]))
                    answer++;
            }
        }
    }
    
    return answer;
}