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
        
        int xor1 = computeXOR(nums1);
        int xor2 = computeXOR(nums2);
        
        int res = 0;
        if(N1 % 2 == 1){
            res ^= xor2;
        }
        if(N2 % 2 == 1){
            res ^= xor1;
        }
        
        return res;
    }
};