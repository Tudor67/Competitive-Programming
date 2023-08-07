class Solution {
private:
    void back(int level, vector<int>& permutation, vector<vector<int>>& permutations){
        const int N = permutation.size();
        if(level == N - 1){
            permutations.push_back(permutation);
        }else{
            for(int i = level; i < N; ++i){
                swap(permutation[level], permutation[i]);
                back(level + 1, permutation, permutations);
                swap(permutation[level], permutation[i]);
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        const int N = nums.size();

        vector<int> permutation = nums;
        vector<vector<int>> permutations;
        back(0, permutation, permutations);

        return permutations;
    }
};