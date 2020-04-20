class Solution {
private:
    vector<vector<int>> solutions;
    vector<int> st;
    
    void back(int level, const int& n, const int& k){
        if(level == k + 1){
            solutions.push_back(vector<int>(st.begin() + 1, st.end()));
        }else{
            for(int i = st[level - 1] + 1; i <= n; ++i){
                st[level] = i;
                back(level + 1, n, k);
            }
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        solutions.clear();
        st.resize(k + 1);
        st[0] = 0;
        back(1, n, k);
        return solutions;
    }
};