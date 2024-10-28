class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        const int N = nums.size();

        int maxLen = 0;
        set<int> numsSet(nums.begin(), nums.end());
        while(!numsSet.empty()){
            int num = *numsSet.begin();
            numsSet.erase(numsSet.begin());

            int len = 1;
            while(num <= INT_MAX / num && numsSet.count(num * num)){
                len += 1;
                num *= num;
                numsSet.erase(num);
            }

            maxLen = max(maxLen, len);
        }

        if(maxLen <= 1){
            maxLen = -1;
        }

        return maxLen;
    }
};