class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        
        // sort
        sort(nums.begin(), nums.end());
        
        // save all lexicographically greater permutations
        do{
            permutations.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        
        return permutations;        
    }
};