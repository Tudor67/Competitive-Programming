class Solution {
private:
    void updateResult(vector<vector<int>>& res, vector<int>& idVal){
        if(res.empty() || res.back()[0] != idVal[0]){
            res.push_back(idVal);
        }else{
            res.back()[1] += idVal[1];
        }
    }

public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();

        vector<vector<int>> res;

        int i1 = 0;
        int i2 = 0;
        while(i1 < N1 || i2 < N2){
            if(i2 == N2 || (i1 < N1 && nums1[i1] <= nums2[i2])){
                updateResult(res, nums1[i1]);
                i1 += 1;
            }else{
                updateResult(res, nums2[i2]);
                i2 += 1;
            }
        }
        
        return res;
    }
};