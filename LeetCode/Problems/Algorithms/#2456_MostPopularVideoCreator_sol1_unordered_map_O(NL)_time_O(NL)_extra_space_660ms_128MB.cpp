class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        const int N = creators.size();
        
        long long maxTotalViews = 0;
        unordered_map<string, long long> totalViews;
        unordered_map<string, pair<int, string>> mostViewsAndID;
        for(int i = 0; i < N; ++i){
            totalViews[creators[i]] += views[i];
            maxTotalViews = max(maxTotalViews, totalViews[creators[i]]);
            if(mostViewsAndID.count(creators[i])){
                mostViewsAndID[creators[i]] = min(mostViewsAndID[creators[i]], pair<int, string>{-views[i], ids[i]});
            }else{
                mostViewsAndID[creators[i]] = {-views[i], ids[i]};
            }
        }
        
        vector<vector<string>> res;
        for(const pair<string, long long>& P: totalViews){
            string creator = P.first;
            long long creatorTotalViews = P.second;
            if(creatorTotalViews == maxTotalViews){
                res.push_back({creator, mostViewsAndID[creator].second});
            }
        }
        
        return res;
    }
};