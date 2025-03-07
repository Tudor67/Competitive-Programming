class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        vector<vector<int>> res;

        int i1 = 0;
        int i2 = 0;
        while(i1 < N1 && i2 < N2){
            if(nums1[i1][0] == nums2[i2][0]){
                res.push_back({nums1[i1][0], nums1[i1][1] + nums2[i2][1]});
                i1 += 1;
                i2 += 1;
            }else if(nums1[i1][0] < nums2[i2][0]){
                res.push_back(nums1[i1]);
                i1 += 1;
            }else{
                res.push_back(nums2[i2]);
                i2 += 1;
            }
        }

        copy(nums1.begin() + i1, nums1.end(), back_inserter(res));
        copy(nums2.begin() + i2, nums2.end(), back_inserter(res));

        return res;
    }
};