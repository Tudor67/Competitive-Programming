class Solution {
private:
    static bool sort_comp(const pair<vector<int>, int>& LHS, const pair<vector<int>, int>& RHS){
        return (LHS.first[0] < RHS.first[0] || (LHS.first[0] == RHS.first[0] && LHS.second < RHS.second));
    }
    
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        const int N = intervals.size();
        
        vector<pair<vector<int>, int>> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = {intervals[i], i};
        }
        
        sort(v.begin(), v.end(), sort_comp);
        
        vector<int> answer(N);
        for(int i = 0; i < N; ++i){
            // binary search
            int val = intervals[i][1];
            int l = 0;
            int r = N - 1;
            while(l != r){
                int mid = (l + r) / 2;
                if(val <= v[mid].first[0]){
                    r = mid;
                }else{
                    l = mid + 1;
                }
            }
            
            if(r < N && val <= v[r].first[0]){
                answer[i] = v[r].second;
            }else{
                answer[i] = -1;
            }
        }
        
        return answer;
    }
};