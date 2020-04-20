class Solution {
private:
    void back(int k, vector<bool>& vis, const int& n, int& ans){
        if(k == n + 1){
            ++ans;
        }else{
            for(int i = 1; i <= n; ++i){
                bool is_valid = !vis[i] && (i % k == 0 || k % i == 0);
                if(is_valid){
                    vis[i] = true;
                    back(k + 1, vis, n, ans);
                    vis[i] = false;
                }
            }
        }
    }
    
public:
    int countArrangement(int N) {
        vector<bool> vis(N, false);
        int ans = 0;
        back(1, vis, N, ans);
        return ans;
    }
};