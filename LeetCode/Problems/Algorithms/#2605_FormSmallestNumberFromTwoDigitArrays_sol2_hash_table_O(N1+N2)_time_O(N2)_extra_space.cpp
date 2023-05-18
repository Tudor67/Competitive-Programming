class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int d1 = *min_element(nums1.begin(), nums1.end());
        int d2 = *min_element(nums2.begin(), nums2.end());
        
        int res = min(d1, d2) * 10 + max(d1, d2);
        
        unordered_set<int> nums2Set(nums2.begin(), nums2.end());
        for(int num: nums1){
            if(nums2Set.count(num)){
                res = min(res, num);
            }
        }
        
        return res;
    }
};