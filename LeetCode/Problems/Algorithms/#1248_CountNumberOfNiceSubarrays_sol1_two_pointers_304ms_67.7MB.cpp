class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();
        int i = 0;
        int j = 0;
        int odd_cnt = 0;
        int answer = 0;
        
        while(j < N){
            while(j < N && odd_cnt < k){
                odd_cnt += nums[j] % 2;
                ++j;
            }
            
            int mult_factor = 1;
            while(j < N && odd_cnt == k && (nums[j] % 2 == 0)){
                ++mult_factor;
                ++j;
            }
            
            while(i < j && odd_cnt == k){
                answer += mult_factor;
                odd_cnt -= nums[i] % 2;
                ++i;
            }
        }
        
        return answer;
    }
};