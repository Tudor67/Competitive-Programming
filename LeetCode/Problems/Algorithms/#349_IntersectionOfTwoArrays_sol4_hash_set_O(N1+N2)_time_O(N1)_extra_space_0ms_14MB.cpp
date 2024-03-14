class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        vector<int> intersection;
        unordered_set<int> nums1Set(nums1.begin(), nums1.end());
        for(int num: nums2){
            if(nums1Set.count(num)){
                nums1Set.erase(num);
                intersection.push_back(num);
            }
        }

        return intersection;
    }
};