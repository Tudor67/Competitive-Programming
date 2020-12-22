class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int one = INT_MAX;
        int two = INT_MAX;
        for(int num: nums){
            if(num <= one){
                one = num;
            }else if(num <= two){
                two = num;
            }else{
                return true;
            }
        }
        return false;
    }
};