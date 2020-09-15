class Solution {
private:
    void back(const int& K, const int& N, int level, int sum, vector<int>& st, vector<vector<int>>& answer){
        if(level == K + 1){
            if(sum == N){
                answer.push_back(vector<int>(st.begin() + 1, st.end()));
            }
        }else{
            for(int i = st[level - 1] + 1; i <= 9 && sum + i <= N; ++i){
                st[level] = i;
                back(K, N, level + 1, sum + st[level], st, answer);
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        const int MAX_POSSIBLE_K = 9;
        const int MAX_POSSIBLE_SUM = 45;
        vector<vector<int>> answer;
        if(k <= MAX_POSSIBLE_K && n <= MAX_POSSIBLE_SUM){
            vector<int> st(k + 1);
            back(k, n, 1, 0, st, answer);
        }
        return answer;
    }
};