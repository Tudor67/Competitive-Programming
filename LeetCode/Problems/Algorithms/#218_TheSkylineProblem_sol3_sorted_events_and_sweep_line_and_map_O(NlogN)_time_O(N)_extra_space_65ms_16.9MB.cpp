class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        const int N = buildings.size();
        
        // for starting point: positive height
        // for ending point: negative height
        map<int, vector<int>> heightsAt;
        for(int i = 0; i < N; ++i){
            int x1 = buildings[i][0];
            int x2 = buildings[i][1];
            int height = buildings[i][2];
            heightsAt[x1].push_back(height);
            heightsAt[x2].push_back(-height);
        }
        
        vector<vector<int>> keyPoints;
        multiset<int> activeHeights;
        for(pair<const int, vector<int>>& P: heightsAt){
            int x = P.first;
            vector<int>& heights = P.second;
            
            for(int height: heights){
                if(height >= 1){
                    activeHeights.insert(height);
                }else{
                    activeHeights.erase(activeHeights.find(-height));
                }
            }
            
            int prevMaxActiveHeight = (keyPoints.empty() ? 0 : keyPoints.back()[1]);
            int maxActiveHeight = (activeHeights.empty() ? 0 : *prev(activeHeights.end()));
            if(prevMaxActiveHeight != maxActiveHeight){
                keyPoints.push_back({x, maxActiveHeight});
            }
        }
        
        return keyPoints;
    }
};