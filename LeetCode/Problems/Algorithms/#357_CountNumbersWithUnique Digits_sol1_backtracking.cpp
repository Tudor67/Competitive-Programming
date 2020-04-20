class Solution {
private:
    void back(int k, vector<bool>& vis, const int& n, int& ans){
        if(k <= n){
            ans += (k > 0);
            for(int i = (k == 0); i <= 9; ++i){
                if(!vis[i]){
                    vis[i] = true;
                    back(k + 1, vis, n, ans);
                    vis[i] = false;
                }
            }
        }
    }
    
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<bool> vis(10, false);
        int ans = 1;
        back(0, vis, n, ans);
        return ans;
    }
};