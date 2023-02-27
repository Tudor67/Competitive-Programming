class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        const int N = s.length();
        const int Q = queries.size();
        const int MAX_BITS = 30;
        
        map<int, pair<int, int>> shortestRangeFor;
        for(int i = 0; i < N; ++i){
            int x = 0;
            if(s[i] == '0'){
                if(!shortestRangeFor.count(0)){
                    shortestRangeFor[0] = {i, i};
                }
            }else{
                for(int j = i; j <= min(N - 1, i + MAX_BITS - 1); ++j){
                    x = 2 * x + (s[j] - '0');
                    if(!shortestRangeFor.count(x)){
                        shortestRangeFor[x] = {i, j};
                    }
                }
            }
        }
        
        vector<vector<int>> res(Q, vector<int>(2, -1));
        for(int i = 0; i < Q; ++i){
            int x = queries[i][0] ^ queries[i][1];
            if(shortestRangeFor.count(x)){
                res[i] = {shortestRangeFor[x].first, shortestRangeFor[x].second};
            }
        }
        
        return res;
    }
};