class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> numSet1(nums1.begin(), nums1.end());
        unordered_set<int> numSet2(nums2.begin(), nums2.end());
        
        vector<int> intersection;
        for(int num: numSet1){
            if(numSet2.count(num)){
                intersection.push_back(num);
            }
        }
        
        return intersection;
    }
};