class Solution {
private:
    vector<int> solve(int n){
        vector<int> p;
        if(n == 1){
            p = {1};
        }else{
            vector<int> pLeft = solve((n + 1) / 2);
            vector<int> pRight = solve(n / 2);
            // p = [valid odd subPermutation] concat [valid even subPermutation]
            // p = [2 * pLeft - 1] concat [2 * pRight]
            for(int elem: pLeft){
                p.push_back(2 * elem - 1);
            }
            for(int elem: pRight){
                p.push_back(2 * elem);
            }
        }
        return p;
    }
    
public:
    vector<int> beautifulArray(int n) {
        return solve(n);
    }
};