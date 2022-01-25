class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        const int N = nums.size();
        
        // leftMaxLen[i]: length of the LIS (from left to right) ending with nums[i]
        vector<int> leftMaxLen(N);
        vector<int> v;
        for(int i = 0; i < N; ++i){
            int k = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
            v.resize(max((int)v.size(), k + 1));
            v[k] = nums[i];
            leftMaxLen[i] = k + 1;
        }
        
        // rightMaxLen[i]: length of the LIS (from right to left) ending with nums[i]
        vector<int> rightMaxLen(N);
        v.clear();
        for(int i = N - 1; i >= 0; --i){
            int k = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
            v.resize(max((int)v.size(), k + 1));
            v[k] = nums[i];
            rightMaxLen[i] = k + 1;
        }
        
        int maxMountainLen = 0;
        for(int i = 0; i < N; ++i){
            if(leftMaxLen[i] >= 2 && rightMaxLen[i] >= 2){
                maxMountainLen = max(maxMountainLen, leftMaxLen[i] + rightMaxLen[i] - 1);
            }
        }
        
        return N - maxMountainLen;
    }
};