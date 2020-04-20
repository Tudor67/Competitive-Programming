class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<pair<int, int>> idx_num_pairs;
        
        for(int i = 0; i < (int)nums.size(); ++i){
            idx_num_pairs.push_back({i, nums[i]});
        }
        
        do{
            vector<int> p(idx_num_pairs.size());
            for(int i = 0; i < (int)idx_num_pairs.size(); ++i){
                p[i] = idx_num_pairs[i].second;
            }
            permutations.push_back(p);
        }while(next_permutation(idx_num_pairs.begin(), idx_num_pairs.end()));
        
        return permutations;
    }
};