class Solution {
public:
    bool isGood(vector<int>& nums) {
        const int N = nums.size();

        unordered_set<int> vis(nums.begin(), nums.end());

        for(int num = 1; num <= N - 1; ++num){
            if(!vis.count(num)){
                return false;
            }
        }

        return count(nums.begin(), nums.end(), N - 1) == 2;
    }
};