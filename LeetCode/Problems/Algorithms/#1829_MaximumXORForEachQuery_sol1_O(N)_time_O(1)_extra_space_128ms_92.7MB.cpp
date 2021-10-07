class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        const int N = nums.size();
        const int MAX_MASK = (1 << maximumBit) - 1;
        
        int prefXOR = 0;
        for(int num: nums){
            prefXOR ^= num;
        }
        
        vector<int> answer(N);
        for(int i = N - 1; i >= 0; --i){
            answer[N - 1 - i] = (prefXOR ^ MAX_MASK);
            prefXOR ^= nums[i];
        }
        
        return answer;
    }
};