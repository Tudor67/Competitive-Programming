class Solution {
private:
    int solve(vector<int> slices, map<vector<int>, int>& memo) {
        const int SIZE = slices.size();
        
        if(memo.count(slices)){
            return memo[slices];
        }
        
        if(SIZE == 0){
            memo[slices] = 0;
            return memo[slices];
        }
        
        if(SIZE == 3){
            memo[slices] = *max_element(slices.begin(), slices.end());
            return memo[slices];
        }
        
        int res = 0;
        for(int i = 0; i < SIZE; ++i){
            const int MODULO = slices.size();
            vector<int> indices = {(i - 1 + MODULO) % MODULO, i, (i + 1) % MODULO};
            sort(indices.rbegin(), indices.rend());
            
            vector<int> prevSlices = slices;
            for(int idx: indices){
                prevSlices.erase(prevSlices.begin() + idx);
            }
            
            res = max(res, slices[i] + solve(prevSlices, memo));
        }
        
        memo[slices] = res;
        return res;
    }
    
public:
    int maxSizeSlices(vector<int>& slices) {
        map<vector<int>, int> memo;
        return solve(slices, memo);
    }
};