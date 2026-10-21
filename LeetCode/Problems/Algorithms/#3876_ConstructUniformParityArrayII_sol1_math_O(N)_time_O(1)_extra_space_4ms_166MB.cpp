class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        const int MIN_NUM = *min_element(nums1.begin(), nums1.end());

        // Case 1: MIN_NUM is odd
        if(MIN_NUM % 2 == 1){
            return true;
        }

        // Case 2: MIN_NUM is even
        for(int num: nums1){
            if(num % 2 == 1){
                return false;
            }
        }

        return true;
    }
};