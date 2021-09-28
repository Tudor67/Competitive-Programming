class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        const int MAX_NUM1 = *max_element(nums1.begin(), nums1.end());
        
        vector<int> count(MAX_NUM1 + 1, 0);
        for(int num: nums1){
            count[num] += 1;
        }
        
        vector<int> intersection;
        for(int num: nums2){
            if(num <= MAX_NUM1 && count[num] > 0){
                count[num] -= 1;
                intersection.push_back(num);
            }
        }
        
        return intersection;
    }
};