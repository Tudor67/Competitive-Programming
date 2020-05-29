class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> answer;
        
        for(int p1 = 0, p2 = 0; p1 < A.size() && p2 < B.size(); ++p1){
            while(p2 < B.size() && A[p1][1] >= B[p2][0]){
                int l = max(A[p1][0], B[p2][0]);
                int r = min(A[p1][1], B[p2][1]);
                if(l <= r){
                    answer.push_back({l, r});
                }
                ++p2;
            }
            p2 = max(p2 - 1, 0);
        }
        
        return answer;
    }
};