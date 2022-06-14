class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        const int N = nums.size();
        const int INF = 1e9;
        
        int prefSum = 0;
        int suffSum = accumulate(nums.begin(), nums.end(), 0);
        int minOps = INF;
        
        int j = 0;
        for(int i = 0; i < N; ++i){
            while(j < i || (j < N && prefSum + suffSum > x)){
                suffSum -= nums[j];
                j += 1;
            }
            
            if(prefSum + suffSum == x){
                minOps = min(minOps, i + (N - j));
            }
            
            prefSum += nums[i];
        }
        
        if(minOps == INF){
            minOps = -1;
        }
        
        return minOps;
    }
};