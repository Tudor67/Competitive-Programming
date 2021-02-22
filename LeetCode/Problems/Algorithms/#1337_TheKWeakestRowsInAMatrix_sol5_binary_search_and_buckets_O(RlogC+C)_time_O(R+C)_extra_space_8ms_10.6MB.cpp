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
        const int M = mat[0].size();
        
        vector<vector<int>> buckets(M + 1);
        for(int row = 0; row < N; ++row){
            buckets[soldiersCount(mat[row])].push_back(row);
        }
        
        vector<int> answer;
        for(int soldiers = 0; soldiers <= M; ++soldiers){
            for(int row: buckets[soldiers]){
                if(answer.size() < k){
                    answer.push_back(row);
                }
            }
        }
        
        return answer;
    }
};