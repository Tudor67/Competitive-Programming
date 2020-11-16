class Solution {
private:
    void back(int level, map<int, int>& cnt, vector<int>& permutation, vector<vector<int>>& permutations){
        if(level == permutation.size()){
            permutations.push_back(permutation);
        }else{
            for(const pair<int, int>& P: cnt){
                int num = P.first;
                if(cnt[num] > 0){
                    cnt[num] -= 1;
                    permutation[level] = num;
                    back(level + 1, cnt, permutation, permutations);
                    cnt[num] += 1;
                }
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> permutations;
        map<int, int> cnt;
        for(int num: nums){
            cnt[num] += 1;
        }
        
        vector<int> permutation(nums.size());
        back(0, cnt, permutation, permutations);
        
        return permutations;
    }
};