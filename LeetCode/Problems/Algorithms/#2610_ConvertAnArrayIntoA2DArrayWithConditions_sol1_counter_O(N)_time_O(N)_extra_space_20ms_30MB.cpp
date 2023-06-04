class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        const int N = nums.size();
        
        unordered_map<int, int> count;
        for(int num: nums){
            count[num] += 1;
        }

        vector<vector<int>> res;
        for(const pair<int, int>& P: count){
            int num = P.first;
            int numCount = P.second;

            for(int i = 0; i < numCount; ++i){
                if(i >= (int)res.size()){
                    res.resize(i + 1);
                }
                res[i].push_back(num);
            }
        }
        
        return res;
    }
};