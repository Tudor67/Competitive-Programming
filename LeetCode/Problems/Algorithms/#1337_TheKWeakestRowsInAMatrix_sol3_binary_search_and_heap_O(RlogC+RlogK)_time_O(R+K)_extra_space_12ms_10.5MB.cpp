class Solution {
private:
    int soldiersCount(const vector<int>& V){
        int l = 0;
        int r = (int)V.size() - 1;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(V[mid] == 1){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        int soldiers = 0;
        if(V[r] == 1){
            soldiers = r + 1;
        }
        return soldiers;
    }
    
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        const int N = mat.size();
        
        vector<int> soldiers(N, 0);
        for(int row = 0; row < N; ++row){
            soldiers[row] = soldiersCount(mat[row]);
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