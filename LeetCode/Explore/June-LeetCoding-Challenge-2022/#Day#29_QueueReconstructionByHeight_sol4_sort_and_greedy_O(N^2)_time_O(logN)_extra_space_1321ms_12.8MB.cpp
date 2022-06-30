class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        const int N = people.size();
        
        vector<vector<int>> res = people;
        sort(res.begin(), res.end(),
             [](const vector<int>& LHS, const vector<int>& RHS){
                 return (LHS[0] > RHS[0] || (LHS[0] == RHS[0] && LHS[1] < RHS[1]));
             });
        
        for(int i = 1; i < N; ++i){
            int k = res[i][1];
            if(i != k){
                res.insert(res.begin() + k, res[i]);
                res.erase(res.begin() + i + 1);
            }
        }
        
        return res;
    }
};