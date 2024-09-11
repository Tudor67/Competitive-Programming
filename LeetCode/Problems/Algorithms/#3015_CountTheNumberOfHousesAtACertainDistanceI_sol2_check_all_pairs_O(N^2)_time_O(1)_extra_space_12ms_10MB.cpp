class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> res(n);
        
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(i != j){
                    int dist = min({abs(i - j),
                                    abs(i - x) + 1 + abs(y - j),
                                    abs(i - y) + 1 + abs(x - j)});
                    res[dist - 1] += 1;
                }
            }
        }

        return res;
    }
};