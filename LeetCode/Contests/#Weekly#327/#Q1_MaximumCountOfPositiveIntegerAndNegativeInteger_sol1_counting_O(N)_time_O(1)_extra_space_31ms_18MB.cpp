class Solution {
public:
    int maximumCount(vector<int>& nums) {
        const int N = nums.size();

        int pos = 0;
        int neg = 0;
        for(int num: nums){
            if(num > 0){
                pos += 1;
            }else if(num < 0){
                neg += 1;
            }
        }
        
        return max(pos, neg);
    }
};