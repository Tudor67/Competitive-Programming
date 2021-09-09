class Solution { 
public:
    int arrayNesting(vector<int>& nums) {
        const int N = nums.size();
        int maxLength = 0;
        vector<bool> vis(N, false);
        for(int startPos = 0; startPos < N; ++startPos){
            if(!vis[startPos]){
                int length = 0;
                for(int k = startPos; !vis[k]; k = nums[k]){
                    vis[k] = true;
                    length += 1;
                }
                maxLength = max(maxLength, length);
            }
        }
        return maxLength;
    }
};