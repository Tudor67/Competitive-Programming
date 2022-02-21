class Solution {
private:
    void back(int startPos, int sum, int target, vector<int>& st, vector<int>& candidates, vector<vector<int>>& answer){
        if(sum == target){
            answer.push_back(st);
        }else{
            for(int i = startPos; i < (int)candidates.size(); ++i){
                if(sum + candidates[i] <= target){
                    sum += candidates[i];
                    st.push_back(candidates[i]);
                    back(i, sum, target, st, candidates, answer);
                    st.pop_back();
                    sum -= candidates[i];
                }
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> st;
        vector<vector<int>> answer;
        back(0, 0, target, st, candidates, answer);
        return answer;
    }
};