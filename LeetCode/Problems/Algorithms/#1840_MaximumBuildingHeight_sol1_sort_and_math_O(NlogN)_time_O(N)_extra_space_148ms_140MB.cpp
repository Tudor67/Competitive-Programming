class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        vector<vector<int>> r = restrictions;
        
        r.push_back({1, 0});
        sort(r.begin(), r.end());
        if(r.back()[0] != n){
            r.push_back({n, n - 1});
        }

        for(int i = 1; i < (int)r.size(); ++i){
            int idxDist = r[i][0] - r[i - 1][0];
            r[i][1] = min(r[i][1], r[i - 1][1] + idxDist);
        }

        for(int i = (int)r.size() - 2; i >= 0; --i){
            int idxDist = r[i + 1][0] - r[i][0];
            r[i][1] = min(r[i][1], r[i + 1][1] + idxDist);
        }

        int maxHeight = 0;
        for(int i = 1; i < (int)r.size(); ++i){
            int leftIdx = r[i - 1][0];
            int leftHeight = r[i - 1][1];
            int rightIdx = r[i][0];
            int rightHeight = r[i][1];
            int idxDist = rightIdx - leftIdx;
            maxHeight = max(maxHeight, (leftHeight + rightHeight + idxDist) / 2);
        }

        return maxHeight;
    }
};