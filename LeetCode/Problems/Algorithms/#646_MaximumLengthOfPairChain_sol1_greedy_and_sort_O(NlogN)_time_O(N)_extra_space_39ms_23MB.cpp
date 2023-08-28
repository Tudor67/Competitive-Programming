class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        const int N = pairs.size();

        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                 return pairs[lhs][1] < pairs[rhs][1];
             });

        int res = 0;
        int lastIncludedRight = pairs[p[0]][0] - 1;
        for(int i: p){
            if(lastIncludedRight < pairs[i][0]){
                lastIncludedRight = pairs[i][1];
                res += 1;
            }
        }

        return res;
    }
};