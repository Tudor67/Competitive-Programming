class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prevPos = -1;
        for(int pos = 0; pos < nums.size(); ++pos){
            if(nums[pos] == 1){
                if(prevPos != -1 && pos - prevPos - 1 < k){
                    return false;
                }
                prevPos = pos;
            }
        }
        return true;
    }
};