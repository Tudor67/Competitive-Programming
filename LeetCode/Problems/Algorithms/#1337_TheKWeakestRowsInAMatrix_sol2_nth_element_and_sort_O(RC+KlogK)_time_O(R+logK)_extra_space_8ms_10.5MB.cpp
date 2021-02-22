class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        const int N = mat.size();
        
        vector<pair<int, int>> sr(N);
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < mat[row].size(); ++col){
                if(mat[row][col] == 1){
                    sr[row].first = col + 1;
                }
            }
            sr[row].second = row;
        }
        
        nth_element(sr.begin(), sr.begin() + k - 1, sr.end());
        sort(sr.begin(), sr.begin() + k);
        
        vector<int> answer(k);
        for(int i = 0; i < k; ++i){
            answer[i] = sr[i].second;
        }
        
        return answer;
    }
};