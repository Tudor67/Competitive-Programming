class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<vector<int>> nums(N + 1);
        for(int num = 0; num <= 9; ++num){
            nums[1].push_back(num);
        }
        
        for(int i = 2; i <= N; ++i){
            for(int num: nums[i - 1]){
                for(int next_digit: set<int>{num % 10 + K, num % 10 - K}){
                    if(num > 0 && next_digit >= 0 && next_digit <= 9){
                        nums[i].push_back(10 * num + next_digit);
                    }
                }
            }
        }
        
        return nums[N];
    }
};