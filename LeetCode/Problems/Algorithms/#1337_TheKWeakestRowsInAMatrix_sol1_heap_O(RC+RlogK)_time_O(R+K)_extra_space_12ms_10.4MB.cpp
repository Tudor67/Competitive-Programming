class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        const int N = mat.size();
        
        vector<int> soldiers(N, 0);
        for(int row = 0; row < N; ++row){
            for(int col = 0; col < mat[row].size(); ++col){
                if(mat[row][col] == 1){
                    soldiers[row] = col + 1;
                }
            }
        }
        
        priority_queue<pair<int, int>> maxHeap;
        for(int row = 0; row < N; ++row){
            maxHeap.push({soldiers[row], row});
            if(maxHeap.size() == k + 1){
                maxHeap.pop();
            }
        }
        
        vector<int> answer(k);
        for(int i = k - 1; i >= 0; --i){
            answer[i] = maxHeap.top().second;
            maxHeap.pop();
        }
        
        return answer;
    }
};