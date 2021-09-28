class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> intersection;
        int idx1 = 0;
        int idx2 = 0;
        while(idx1 < N1 && idx2 < N2){
            if(nums1[idx1] == nums2[idx2]){
                intersection.push_back(nums1[idx1]);
                idx1 += 1;
                idx2 += 1;
            }else if(nums1[idx1] < nums2[idx2]){
                idx1 += 1;
            }else{
                idx2 += 1;
            }
        }
        
        return intersection;
    }
};