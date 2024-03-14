class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        const int MAX_NUM1 = *max_element(nums1.begin(), nums1.end());

        vector<bool> vis1(MAX_NUM1 + 1, false);
        for(int num: nums1){
            vis1[num] = true;
        }

        vector<int> intersection;
        for(int num: nums2){
            if(num <= MAX_NUM1 && vis1[num]){
                vis1[num] = false;
                intersection.push_back(num);
            }
        }

        return intersection;
    }
};