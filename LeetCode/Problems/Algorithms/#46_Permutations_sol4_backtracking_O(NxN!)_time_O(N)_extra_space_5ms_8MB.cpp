class Solution {
private:
    void back(vector<int>& nums, vector<bool>& vis, vector<int>& permutation, vector<vector<int>>& permutations){
        const int N = nums.size();
        if((int)permutation.size() == N){
            permutations.push_back(permutation);
        }else{
            for(int i = 0; i < N; ++i){
                if(!vis[i]){
                    vis[i] = true;
                    permutation.push_back(nums[i]);
                    back(nums, vis, permutation, permutations);
                    permutation.pop_back();
                    vis[i] = false;
                }
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        const int N = nums.size();

        vector<bool> vis(N, false);
        vector<int> permutation;
        vector<vector<int>> permutations;
        back(nums, vis, permutation, permutations);

        return permutations;
    }
};