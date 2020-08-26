#include <iostream>
#include <vector>
using namespace std;

int main(){
    const int MAX_NUM = 28123;
    vector<int> prop_div_sum(MAX_NUM + 1, 0);
    
    for(int j = 1; j <= MAX_NUM; ++j){
        for(int i = 2 * j; i <= MAX_NUM; i += j){
            prop_div_sum[i] += j;
        }
    }
    
    vector<int> abundant_nums;
    for(int num = 2; num <= MAX_NUM; ++num){
        if(num < prop_div_sum[num]){
            abundant_nums.push_back(num);
        }
    }
    
    int total_sum = MAX_NUM * (MAX_NUM + 1) / 2;
    int excluded_sum = 0;
    vector<int> is_excluded(MAX_NUM + 1, false);
    for(int i = 0; i < abundant_nums.size(); ++i){
        for(int j = i; j < abundant_nums.size(); ++j){
            int num = abundant_nums[i] + abundant_nums[j];
            if(num <= MAX_NUM && !is_excluded[num]){
                excluded_sum += num;
                is_excluded[num] = true;
            }
        }
    }
    
    int answer = total_sum - excluded_sum;
    
    // 4179871
    cout << answer;
    
    return 0;
}