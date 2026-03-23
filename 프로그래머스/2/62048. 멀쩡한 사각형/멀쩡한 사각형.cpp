using namespace std;

long long solution(int w,int h) {
    long long answer = (long long) w * h;
    
    
    for (long long i = 0; i < w; i++) {
        long long low = (i * h) / (long long) w;
        long long high;
        
        if ((i * h) % w == 0) {
            high = ( (i + 1) * h) / (long long) w; 
        } else {
            high = 1 + ( (i + 1) * h) / (long long) w; 
        }

        answer -= high - low;
    }
    
    return answer;
}