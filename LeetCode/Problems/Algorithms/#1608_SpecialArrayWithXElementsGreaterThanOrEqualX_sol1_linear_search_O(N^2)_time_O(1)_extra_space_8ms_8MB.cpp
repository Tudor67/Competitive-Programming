class Solution {
private:
    int countEqualOrGreater(vector<int>& nums, int x){
        int count = 0;
        for(int num: nums){
            if(x <= num){
                count += 1;
            }
        }
        return count;
    }
    
public:
    int specialArray(vector<int>& nums) {
        const int N = nums.size();
        for(int x = 1; x <= N; ++x){
            if(x == countEqualOrGreater(nums, x)){
                return x;
            }
        }
        return -1;
    }
};