class Solution {
public:
    int specialArray(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> suffCount(N + 2);
        for(int num: nums){
            suffCount[min(num, N + 1)] += 1;
        }
        
        for(int num = N; num >= 0; --num){
            suffCount[num] += suffCount[num + 1];
        }
        
        int i = 0;
        for(int x = 1; x <= N; ++x){
            if(x == suffCount[x]){
                return x;
            }
        }
        
        return -1;
    }
};