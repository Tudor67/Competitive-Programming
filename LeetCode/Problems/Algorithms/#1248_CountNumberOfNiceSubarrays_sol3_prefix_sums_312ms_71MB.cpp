class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();
        int answer = 0;
        
        int odd_cnt_prefix_sum = 0;
        vector<int> freq(N + 1, 0); // frequency of prefix_sum at the current step
        freq[0] = 1;
        for(int i = 0; i < N; ++i){
            odd_cnt_prefix_sum += (nums[i] % 2);
            ++freq[odd_cnt_prefix_sum];
            if(odd_cnt_prefix_sum - k >= 0){
                answer += freq[odd_cnt_prefix_sum - k];
            }
        }
        
        return answer;
    }
};