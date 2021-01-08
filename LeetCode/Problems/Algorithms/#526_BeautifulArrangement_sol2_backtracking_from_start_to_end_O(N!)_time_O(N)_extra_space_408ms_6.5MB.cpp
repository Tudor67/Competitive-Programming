class Solution {
private:
    void back(int level, int n, vector<int>& st, vector<bool>& vis, int& answer){
        if(level == n + 1){
            answer += 1;
        }else{
            for(int i = 1; i <= n; ++i){
                if(!vis[i] && (i % level == 0 || level % i == 0)){
                    st[level] = i;
                    vis[i] = true;
                    back(level + 1, n, st, vis, answer);
                    vis[i] = false;
                }
            }
        }
    }
    
public:
    int countArrangement(int n) {
        vector<int> st(n + 1);
        vector<bool> vis(n + 1, false);
        int answer = 0;
        back(1, n, st, vis, answer);
        return answer;
    }
};