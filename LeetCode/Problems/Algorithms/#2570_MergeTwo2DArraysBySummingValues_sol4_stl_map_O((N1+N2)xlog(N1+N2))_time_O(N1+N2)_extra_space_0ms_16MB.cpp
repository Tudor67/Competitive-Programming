class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        map<int, int> idToSum;
        for(int i1 = 0; i1 < N1; ++i1){
            idToSum[nums1[i1][0]] += nums1[i1][1];
        }

        for(int i2 = 0; i2 < N2; ++i2){
            idToSum[nums2[i2][0]] += nums2[i2][1];
        }

        vector<vector<int>> res;
        for(auto& [id, sum]: idToSum){
            res.push_back({id, sum});
        }

        return res;
    }
};