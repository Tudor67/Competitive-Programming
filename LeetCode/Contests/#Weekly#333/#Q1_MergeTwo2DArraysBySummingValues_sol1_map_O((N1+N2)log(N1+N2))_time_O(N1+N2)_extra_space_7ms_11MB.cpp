class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        
        map<int, int> valSumOf;
        for(int i = 0; i < N1; ++i){
            valSumOf[nums1[i][0]] += nums1[i][1];
        }
        
        for(int i = 0; i < N2; ++i){
            valSumOf[nums2[i][0]] += nums2[i][1];
        }
        
        vector<vector<int>> res;
        for(const pair<int, int>& P: valSumOf){
            int id = P.first;
            int valSum = P.second;
            res.push_back({id, valSum});
        }
        
        return res;
    }
};