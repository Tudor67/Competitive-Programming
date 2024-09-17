class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
        const int N = p.size();

        sort(p.begin(), p.end(),
             [](const vector<int>& LHS, const vector<int>& RHS){
                return pair<int, int>{LHS[0], -LHS[1]} <
                       pair<int, int>{RHS[0], -RHS[1]};
             });

        int validPairs = 0;
        set<int> ySet;
        for(int i = 0; i < N; ++i){
            ySet.clear();
            for(int j = i + 1; j < N; ++j){
                if(p[i][1] >= p[j][1]){
                    set<int>::iterator it = ySet.lower_bound(p[j][1]);
                    if(it == ySet.end() || *it > p[i][1]){
                        validPairs += 1;
                        ySet.insert(p[j][1]);
                    }
                }
            }
        }

        return validPairs;
    }
};