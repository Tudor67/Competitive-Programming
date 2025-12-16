class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, vector<int>> xToYs;
        unordered_map<int, vector<int>> yToXs;
        for(vector<int>& building: buildings){
            int x = building[0];
            int y = building[1];
            xToYs[x].push_back(y);
            yToXs[y].push_back(x);
        }

        map<pair<int, int>, int> coveredCount;
        for(auto& [x, ys]: xToYs){
            sort(ys.begin(), ys.end());
            for(int i = 1; i < (int)ys.size() - 1; ++i){
                int y = ys[i];
                coveredCount[{x, y}] += 2;
            }
        }

        for(auto& [y, xs]: yToXs){
            sort(xs.begin(), xs.end());
            for(int i = 1; i < (int)xs.size() - 1; ++i){
                int x = xs[i];
                coveredCount[{x, y}] += 2;
            }
        }

        int coveredBuildings = 0;
        for(auto& [building, buildingCoveredCount]: coveredCount){
            if(buildingCoveredCount == 4){
                coveredBuildings += 1;
            }
        }

        return coveredBuildings;
    }
};