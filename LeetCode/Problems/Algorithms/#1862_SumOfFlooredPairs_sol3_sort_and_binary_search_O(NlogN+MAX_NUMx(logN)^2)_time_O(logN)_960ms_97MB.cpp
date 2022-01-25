class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        const int N = nums.size();
        const int MODULO = 1e9 + 7;
        
        sort(nums.begin(), nums.end());
        
        int answer = 0;
        int i = 0;
        while(i < N){
            int duplicates = 1;
            while(i + duplicates < N && nums[i] == nums[i + duplicates]){
                duplicates += 1;
            }
            int j = i;
            while(j < N){
                int f = nums[j] / nums[i];
                int k = lower_bound(nums.begin() + j, nums.end(), nums[i] * (f + 1LL)) - nums.begin() - 1;
                answer += (f * (k - j + 1LL) * duplicates) % MODULO;
                answer %= MODULO;
                j = k + 1;
            }
            i += duplicates;
        }
        
        return answer;
    }
};