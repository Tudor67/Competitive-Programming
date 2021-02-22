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
        
        vector<pair<int, int>> sr(N);
        for(int row = 0; row < N; ++row){
            sr[row] = {soldiersCount(mat[row]), row};
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