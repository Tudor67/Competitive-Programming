class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        const int N = nums.size();
        const int MAX_MASK = (1 << maximumBit) - 1;
        
        int k = MAX_MASK;
        for(int num: nums){
            k ^= num;
        }
        
        vector<int> answer(N);
        for(int i = N - 1; i >= 0; --i){
            answer[N - 1 - i] = k;
            k ^= nums[i];
        }
        
        return answer;
    }
};