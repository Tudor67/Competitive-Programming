class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        const int N = nums.size();
        const int INF = 1e9 + 9;

        long long maxSum = accumulate(nums.begin(), nums.end(), (long long)0);
        int posContribCount = 0;
        int minPosContrib = INF;
        int maxNegContrib = -INF;

        for(int num: nums){
            int contrib = (num ^ k) - num;
            if(contrib >= 0){
                maxSum += contrib;
                minPosContrib = min(minPosContrib, contrib);
                posContribCount += 1;
            }else{
                maxNegContrib = max(maxNegContrib, contrib);
            }
        }

        if(posContribCount % 2 == 1){
            maxSum = max(maxSum + maxNegContrib, maxSum - minPosContrib);
        }

        return maxSum;
    }
};