class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> vis(n, false);
        
        int i = 0;
        int stepSize = k;
        while(!vis[i]){
            vis[i] = true;
            i = (i + stepSize) % n;
            stepSize = (stepSize + k) % n;
        }

        vector<int> res;
        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                res.push_back(i + 1);
            }
        }

        return res;
    }
};