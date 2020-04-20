class Solution {
private:
    void back(int k, const int& sum, const int& target,
              const int& last_pos, vector<int>& st, const vector<int>& candidates, vector<vector<int>>& solutions){
        if(sum == target){
            solutions.push_back({st.begin(), st.begin() + k});
        }else{
            for(int i = last_pos; i < (int)candidates.size(); ++i){
                int elem = candidates[i];
                if(sum + elem <= target){
                    st[k] = elem;
                    back(k + 1, sum + elem, target, i, st, candidates, solutions);
                }
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        int n = target / candidates[0] + 1;
        vector<int> st(n);
        vector<vector<int>> solutions;
        
        back(0, 0, target, 0, st, candidates, solutions);
        
        return solutions;
    }
};