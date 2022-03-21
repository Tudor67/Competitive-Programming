class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int N = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int maxPoints = 0;
        vector<int> dp0(N);
        vector<int> dp1(N);
        
        int i = 0;
        while(i < N){
            int j = i;
            while(j + 1 < N && nums[i] == nums[j + 1]){
                ++j;
            }
            int numContrib = nums[i] * (j - i + 1);
            
            if(i == 0){
                dp0[j] = 0;
                dp1[j] = numContrib;
            }else if(nums[i - 1] == nums[i] - 1){
                dp0[j] = max(dp0[i - 1], dp1[i - 1]);
                dp1[j] = dp0[i - 1] + numContrib;
            }else{
                dp0[j] = max(dp0[i - 1], dp1[i - 1]);
                dp1[j] = max(dp0[i - 1], dp1[i - 1]) + numContrib;
            }
            
            maxPoints = max(maxPoints, max(dp0[j], dp1[j]));
            
            i = j + 1;
        }
        
        return maxPoints;
    }
};