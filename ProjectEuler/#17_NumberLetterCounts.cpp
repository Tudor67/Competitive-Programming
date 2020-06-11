#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, string> word = {
    {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}, {6, "six"},
    {7, "seven"}, {8, "eight"}, {9, "nine"}, {10, "ten"}, {11, "eleven"},
    {12, "twelve"}, {13, "thirteen"}, {14, "fourteen"}, {15, "fifteen"},
    {16, "sixteen"}, {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"},
    {20, "twenty"}, {30, "thirty"}, {40, "forty"}, {50, "fifty"}, {60, "sixty"},
    {70, "seventy"}, {80, "eighty"}, {90, "ninety"}, {100, "hundred"},
    {1000, "thousand"}
};

int main(){
    // [1, 100)
    int sum = 0;
    for(int i = 1; i <= 19; ++i){
        sum += word[i].length();
    }
    
    int tens = 0;
    for(int i = 20; i <= 99; ++i){
        if(word.count(i)){
            tens = i;
            sum += word[i].length();
        }else{
            sum += word[tens].length() + word[i - tens].length();
        }
    }
    
    // [100, 1000)
    int answer = sum; // 1, 2, 3, ... 99
    for(int i = 1; i <= 9; ++i){
                  // 100, 200, ..., 900
        answer += (word[i].length() + word[100].length()) +
                  // 101, 102, 103, ..., 199, 201, 202, ..., 899, 901, ..., 999
                  (word[i].length() + word[100].length() + 3) * 99 + sum;
    }
    
    // [1000, 1000]
    answer += word[1].length() + word[1000].length();
    
    // 21124
    cout << answer;
    
    return 0;
}