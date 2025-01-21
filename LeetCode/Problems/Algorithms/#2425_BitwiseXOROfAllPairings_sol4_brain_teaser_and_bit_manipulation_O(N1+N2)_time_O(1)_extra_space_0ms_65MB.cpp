class Solution {
private:
    int computeXOR(vector<int>& nums){
        int numsXOR = 0;
        for(int num: nums){
            numsXOR ^= num;
        }
        return numsXOR;
    }

public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        int res = 0;
        if(N1 % 2 == 1){
            res ^= computeXOR(nums2);
        }

        if(N2 % 2 == 1){
            res ^= computeXOR(nums1);
        }

        return res;
    }
};