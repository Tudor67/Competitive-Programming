class Solution {
private:
    int fastPow(int a, int n, const int MODULO){
        a %= MODULO;
        int res = 1;
        while(n > 0){
            if(n & 1){
                res = (res * a) % MODULO;
            }
            a = (a * a) % MODULO;
            n >>= 1;
        }
        return res;
    }
    
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        const int N = variables.size();
        
        vector<int> res;
        for(int i = 0; i < N; ++i){
            int x = fastPow(variables[i][0], variables[i][1], 10);
            int y = fastPow(x, variables[i][2], variables[i][3]);
            if(y == target){
                res.push_back(i);
            }
        }
        
        return res;
    }
};