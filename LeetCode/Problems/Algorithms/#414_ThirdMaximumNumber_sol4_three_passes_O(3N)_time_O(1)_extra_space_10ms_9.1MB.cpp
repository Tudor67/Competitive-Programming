class Solution {
private:
    int findMaxLessThan(vector<int>& nums, const int& LIMIT){
        int constrainedMax = LIMIT;
        for(int num: nums){
            if(num < LIMIT){
                if(constrainedMax == LIMIT || constrainedMax < num){
                    constrainedMax = num;
                }
            }
        }
        return constrainedMax;
    }
    
public:
    int thirdMax(vector<int>& nums) {
        int max1 = *max_element(nums.begin(), nums.end());
        int max2 = findMaxLessThan(nums, max1);
        int max3 = findMaxLessThan(nums, max2);
        
        if(max3 == max2){
            return max1;
        }
        
        return max3;
    }
};