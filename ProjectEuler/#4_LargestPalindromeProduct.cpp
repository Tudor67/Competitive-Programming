#include <iostream>
using namespace std;

bool is_palindrome(int x){
    int num = x;
    int num_reversed = 0;
    while(x > 0){
        num_reversed = 10 * num_reversed + x % 10;
        x /= 10;
    }
    return (num == num_reversed);
}

int main(){
    int max_palindrome = -1;
    for(int i = 100; i <= 999; ++i){
        for(int j = 100; j <= 999; ++j){
            int num = i * j;
            if(is_palindrome(num)){
                max_palindrome = max(num, max_palindrome);
            }
        }
    }
    // 906609
    cout << max_palindrome;
    return 0;
}