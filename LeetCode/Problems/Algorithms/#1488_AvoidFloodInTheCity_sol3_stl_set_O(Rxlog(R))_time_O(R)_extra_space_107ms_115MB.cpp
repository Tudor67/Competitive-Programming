class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        const int R = rains.size();

        vector<int> ans(R, -1);
        unordered_map<int, int> lastDayOf;
        set<int> drySet;

        for(int i = 0; i < R; ++i){
            int lake = rains[i];
            if(lake == 0){
                ans[i] = 1;
                drySet.insert(i);
            }else{
                if(lastDayOf.count(lake)){
                    auto it = drySet.upper_bound(lastDayOf[lake]);
                    if(it == drySet.end()){
                        return {};
                    }
                    ans[*it] = lake;
                    drySet.erase(it);
                }
                lastDayOf[lake] = i;
            }
        }

        return ans;
    }
};