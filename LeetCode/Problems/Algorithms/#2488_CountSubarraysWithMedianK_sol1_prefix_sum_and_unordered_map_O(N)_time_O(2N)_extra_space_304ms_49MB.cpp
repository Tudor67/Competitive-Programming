class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        const int N = nums.size();
        const int POS_OF_K = find(nums.begin(), nums.end(), k) - nums.begin();

        vector<int> prefSum(N);
        unordered_map<int, int> count;
        count[0] = 1;
        for(int i = 0; i < N; ++i){
            if(nums[i] < k){
                prefSum[i] = -1;
            }else if(nums[i] > k){
                prefSum[i] = 1;
            }
            if(i >= 1){
                prefSum[i] += prefSum[i - 1];
            }
            if(i < POS_OF_K){
                count[prefSum[i]] += 1;
            }
        }
        
        int res = 0;
        for(int i = POS_OF_K; i < N; ++i){
            if(count.count(prefSum[i] - 1)){
                res += count[prefSum[i] - 1];
            }
            if(count.count(prefSum[i])){
                res += count[prefSum[i]];
            }
        }
        
        return res;
    }
};