class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();
        vector<int> odd_cnt(N, 0); // odd_cnt[i]: number of odd elements in range [0, i]
        
        odd_cnt[0] = nums[0] % 2;
        for(int i = 1; i < N; ++i){
            odd_cnt[i] = (nums[i] % 2) + odd_cnt[i - 1];
        }
        
        int answer = 0;
        vector<int> freq(odd_cnt.back() + 1, 0); // frequency of odd_cnt[val] at the current step
        freq[0] = 1;
        for(int i = 0; i < N; ++i){
            if(odd_cnt[i] - k >= 0){
                answer += freq[odd_cnt[i] - k];
            }
            ++freq[odd_cnt[i]];
        }
        
        return answer;
    }
};