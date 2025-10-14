class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        const int R = rains.size();

        unordered_map<int, vector<int>> lakeToIndices;
        for(int i = R - 1; i >= 0; --i){
            lakeToIndices[rains[i]].push_back(i);
        }

        vector<int> ans(R, -1);
        unordered_set<int> floodCandidates;
        set<int> waitingIndices;

        for(int i = 0; i < R; ++i){
            int lake = rains[i];
            if(lake == 0){
                if(waitingIndices.empty()){
                    ans[i] = 1;
                }else{
                    int lakeToDry = rains[*waitingIndices.begin()];
                    waitingIndices.erase(waitingIndices.begin());
                    ans[i] = lakeToDry;
                    floodCandidates.erase(lakeToDry);
                }
            }else{
                if(floodCandidates.count(lake)){
                    return {};
                }
                floodCandidates.insert(lake);
                lakeToIndices[lake].pop_back();
                if(!lakeToIndices[lake].empty()){
                    waitingIndices.insert(lakeToIndices[lake].back());
                }
            }
        }

        return ans;
    }
};