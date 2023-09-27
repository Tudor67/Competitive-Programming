class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        const int N = nums.size();

        int duplicate = -1;
        vector<bool> vis(N + 1, false);
        for(int i = 0; i < N && duplicate == -1; ++i){
            if(vis[nums[i]]){
                duplicate = nums[i];
            }else{
                vis[nums[i]] = true;
            }
        }

        return duplicate;
    }
};