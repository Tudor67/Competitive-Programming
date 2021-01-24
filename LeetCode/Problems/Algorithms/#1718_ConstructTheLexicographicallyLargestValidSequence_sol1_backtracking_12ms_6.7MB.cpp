class Solution {
private:
    void back(int level, const int& N, vector<int>& st, vector<bool>& vis, vector<int>& seq){
        if(level == st.size()){
            seq = st;
            return;
        }
        if(st[level] > 0){
            back(level + 1, N, st, vis, seq);
        }else{
            for(int i = N; seq.empty() && i >= 1; --i){
                if(!vis[i]){
                    int levelPair = level + (i >= 2) * i;
                    if(levelPair < st.size() && st[levelPair] == 0){
                        vis[i] = true;
                        st[level] = i;
                        st[levelPair] = i;
                        back(level + 1, N, st, vis, seq);
                        vis[i] = false;
                        st[level] = 0;
                        st[levelPair] = 0;
                    }
                }
            }
        }
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> st(2 * n - 1, 0);
        vector<bool> vis(n + 1, false);
        vector<int> seq;
        back(0, n, st, vis, seq);
        return seq;
    }
};