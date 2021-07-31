class Solution {
private:
    vector<int> solve(int n, unordered_map<int, vector<int>>& memo){
        if(memo.count(n)){
            return memo[n];
        }
        vector<int> p;
        if(n == 1){
            p = {1};
        }else{
            vector<int> pLeft = solve((n + 1) / 2, memo);
            vector<int> pRight = solve(n / 2, memo);
            // p = [valid odd subPermutation] concat [valid even subPermutation]
            // p = [2 * pLeft - 1] concat [2 * pRight]
            for(int elem: pLeft){
                p.push_back(2 * elem - 1);
            }
            for(int elem: pRight){
                p.push_back(2 * elem);
            }
        }
        memo[n] = p;
        return p;
    }
    
public:
    vector<int> beautifulArray(int n) {
        unordered_map<int, vector<int>> memo;
        return solve(n, memo);
    }
};