#include <iostream>
using namespace std;

int main(){
    const int A = 1;
    const int B = 12500;
    const int MIN_DIV_CNT = 501;
    
    long long answer = -1;
    int answer_div_cnt = -1;
    for(long long i = A; i <= B; ++i){
        long long x = (i * (i + 1)) / 2;
        int div_cnt = 0;
        for(long long j = 1; j * j <= x; ++j){
            if(x % j == 0){
                div_cnt += 2;
            }
        }
        if(div_cnt >= MIN_DIV_CNT){
            answer = x;
            answer_div_cnt = div_cnt;
            break;
        }
    }
    
    // 76576500: 576
    cout << answer << ": " << answer_div_cnt;
    return 0;
}