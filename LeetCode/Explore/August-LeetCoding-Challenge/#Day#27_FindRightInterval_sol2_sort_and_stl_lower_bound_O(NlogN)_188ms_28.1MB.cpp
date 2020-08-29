class Solution {
private:
    static bool sort_comp(const pair<vector<int>, int>& LHS, const pair<vector<int>, int>& RHS){
        return (LHS.first[0] < RHS.first[0] || (LHS.first[0] == RHS.first[0] && LHS.second < RHS.second));
    }
    
    static bool lb_comp(const pair<vector<int>, int>& IT, const int& VAL){
        return IT.first[0] < VAL;
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
            int pos = lower_bound(v.begin(), v.end(), intervals[i][1], lb_comp) - v.begin();
            if(pos < N){
                answer[i] = v[pos].second;
            }else{
                answer[i] = -1;
            }
        }
        
        return answer;
    }
};