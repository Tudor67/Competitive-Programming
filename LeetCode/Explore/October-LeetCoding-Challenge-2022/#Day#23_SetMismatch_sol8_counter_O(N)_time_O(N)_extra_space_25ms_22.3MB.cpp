class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> count(N + 1);
        for(int num: nums){
            count[num] += 1;
        }
        
        int duplicate = 0;
        int missing = 0;
        for(int num = 1; num <= N; ++num){
            if(count[num] == 2){
                duplicate = num;
            }
            if(count[num] == 0){
                missing = num;
            }
        }
        
        return {duplicate, missing};
    }
};