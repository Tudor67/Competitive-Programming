class Solution {
private:
    void back(int startVal, int n, int k, vector<int>& combination, vector<vector<int>>& combinations){
        if((int)combination.size() == k){
            combinations.push_back(combination);
        }else{
            for(int val = startVal; val <= n; ++val){
                combination.push_back(val);
                back(val + 1, n, k, combination, combinations);
                combination.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        vector<vector<int>> combinations;
        back(1, n, k, combination, combinations);
        return combinations;
    }
};