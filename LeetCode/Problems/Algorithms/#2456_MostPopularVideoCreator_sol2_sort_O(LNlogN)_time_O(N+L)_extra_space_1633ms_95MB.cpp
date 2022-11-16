class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        const int N = creators.size();
        
        vector<int> p(N);
        iota(p.begin(), p.end(), 0);
        
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                 return tuple<string, int, string>{creators[lhs], -views[lhs], ids[lhs]} >
                        tuple<string, int, string>{creators[rhs], -views[rhs], ids[rhs]};
             });
        
        long long maxViews = 0;
        long long creatorViews = 0;
        for(int i = 0; i < N; ++i){
            creatorViews += views[p[i]];
            if(i == N - 1 || creators[p[i]] != creators[p[i + 1]]){
                maxViews = max(maxViews, creatorViews);
                creatorViews = 0;
            }
        }
        
        vector<vector<string>> res;
        creatorViews = 0;
        for(int i = 0; i < N; ++i){
            creatorViews += views[p[i]];
            if(i == N - 1 || creators[p[i]] != creators[p[i + 1]]){
                if(creatorViews == maxViews){
                    res.push_back({creators[p[i]], ids[p[i]]});
                }
                creatorViews = 0;
            }
        }
        
        return res;
    }
};