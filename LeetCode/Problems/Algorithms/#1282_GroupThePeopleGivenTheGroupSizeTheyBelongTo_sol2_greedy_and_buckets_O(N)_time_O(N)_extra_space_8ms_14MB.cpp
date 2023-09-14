class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        const int N = groupSizes.size();

        vector<vector<int>> res;
        vector<vector<int>> groups(N + 1);
        for(int i = 0; i < N; ++i){
            vector<int>& g = groups[groupSizes[i]];
            g.push_back(i);
            if((int)g.size() == groupSizes[i]){
                res.push_back(g);
                g.clear();
            }
        }

        return res;
    }
};