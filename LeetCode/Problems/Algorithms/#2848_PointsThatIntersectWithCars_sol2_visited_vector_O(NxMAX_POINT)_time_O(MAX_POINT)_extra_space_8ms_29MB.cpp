class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        const int N = nums.size();

        int maxPoint = 0;
        for(const vector<int>& V: nums){
            maxPoint = max(maxPoint, V[1]);
        }
        
        vector<bool> vis(maxPoint + 1, false);
        for(const vector<int>& V: nums){
            int a = V[0];
            int b = V[1];
            for(int i = a; i <= b; ++i){
                vis[i] = true;
            }
        }
        
        return count(vis.begin(), vis.end(), true);
    }
};