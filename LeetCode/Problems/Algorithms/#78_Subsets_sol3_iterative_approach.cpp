class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> solutions;
        solutions.push_back({});
        
        for(int num: nums){
            int lim = solutions.size();
            for(int i = 0; i < lim; ++i){
                solutions.push_back(solutions[i]);
                solutions.back().push_back(num);
            }
        }
        
        return solutions;
    }
};