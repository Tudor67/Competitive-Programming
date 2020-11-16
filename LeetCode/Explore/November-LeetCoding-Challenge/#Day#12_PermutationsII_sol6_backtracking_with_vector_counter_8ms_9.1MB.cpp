class Solution {
private:
    void back(int level, vector<int>& cnt, const int& MIN_NUM, const vector<int>& DISTINCT_NUMS,
              vector<int>& permutation, vector<vector<int>>& permutations){
        if(level == permutation.size()){
            permutations.push_back(permutation);
        }else{
            for(int num: DISTINCT_NUMS){
                if(cnt[num - MIN_NUM] > 0){
                    cnt[num - MIN_NUM] -= 1;
                    permutation[level] = num;
                    back(level + 1, cnt, MIN_NUM, DISTINCT_NUMS, permutation, permutations);
                    cnt[num - MIN_NUM] += 1;
                }
            }
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const int MIN_NUM = *min_element(nums.begin(), nums.end());
        const int SIZE = MAX_NUM - MIN_NUM + 1;
        
        vector<vector<int>> permutations;
        vector<int> cnt(SIZE);
        for(int num: nums){
            cnt[num - MIN_NUM] += 1;
        }
        
        vector<int> distinctNums;
        for(int num = MIN_NUM; num <= MAX_NUM; ++num){
            if(cnt[num - MIN_NUM] > 0){
                distinctNums.push_back(num);
            }
        }
        
        vector<int> permutation(nums.size());
        back(0, cnt, MIN_NUM, distinctNums, permutation, permutations);
        
        return permutations;
    }
};