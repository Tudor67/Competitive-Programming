class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = accumulate(nums1.begin(), nums1.end(), (long long)0);
        long long s2 = accumulate(nums2.begin(), nums2.end(), (long long)0);
        long long z1 = count(nums1.begin(), nums1.end(), 0);
        long long z2 = count(nums2.begin(), nums2.end(), 0);

        if(s1 + z1 > s2 + z2){
            swap(s1, s2);
            swap(z1, z2);
        }
        
        if(z1 == 0 && s1 + z1 < s2 + z2){
            return -1;
        }
        
        return s2 + z2;
    }
};