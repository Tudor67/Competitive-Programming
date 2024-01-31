class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int N = nums.size();

        vector<int> res(2);

        vector<bool> vis(N + 1, false);
        for(int num: nums){
            if(vis[num]){
                res[0] = num;
            }
            vis[num] = true;
        }

        for(int num = 1; num <= N; ++num){
            if(!vis[num]){
                res[1] = num;
            }
        }

        return res;
    }
};