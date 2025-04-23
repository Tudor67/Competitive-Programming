class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        const int N = nums.size();

        unordered_set<int> vis;
        for(int i = N - 1; i >= 0; --i){
            if(vis.count(nums[i])){
                return (i + 3) / 3;
            }
            vis.insert(nums[i]);
        }

        return 0;
    }
};