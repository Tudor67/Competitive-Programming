class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        const int N = nums.size();

        vector<int> p = nums;
        sort(p.begin(), p.end());
        
        vector<vector<int>> permutations;
        do{
            permutations.push_back(p);
        }while(next_permutation(p.begin(), p.end()));

        return permutations;
    }
};