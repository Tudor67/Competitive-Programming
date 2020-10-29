class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        const int N = nums.size();
        
        // init leftMin and rightNums
        int leftMin = nums[0];
        multiset<int> rightNums(nums.begin() + 1, nums.end());
        
        for(int pos = 1; pos < N - 1; ++pos){
            // fix midNum
            int midNum = nums[pos];
            int rightNum = INT_MIN;
            
            // update leftMin and rightNums
            leftMin = min(nums[pos - 1], leftMin);
            rightNums.erase(rightNums.find(midNum));
            
            // try to find a valid rightNum
            multiset<int>::iterator rightIt = rightNums.lower_bound(midNum);
            if(rightIt != rightNums.begin()){
                rightNum = *prev(rightIt);
            }
            
            // check if the current triplet is valid
            if(leftMin < midNum && midNum > rightNum && leftMin < rightNum){
                return true;
            }
        }
        
        return false;
    }
};