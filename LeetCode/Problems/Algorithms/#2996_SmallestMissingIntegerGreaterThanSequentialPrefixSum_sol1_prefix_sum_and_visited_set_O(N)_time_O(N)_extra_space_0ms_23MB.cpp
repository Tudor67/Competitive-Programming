class Solution {
public:
    int missingInteger(vector<int>& nums) {
        const int N = nums.size();

        int prefSum = 0;
        for(int i = 0; i < N; ++i){
            if(i == 0 || nums[i - 1] + 1 == nums[i]){
                prefSum += nums[i];
            }else{
                break;
            }
        }

        unordered_set<int> numsSet(nums.begin(), nums.end());
        int missingNum = prefSum;
        while(numsSet.count(missingNum)){
            missingNum += 1;
        }

        return missingNum;
    }
};