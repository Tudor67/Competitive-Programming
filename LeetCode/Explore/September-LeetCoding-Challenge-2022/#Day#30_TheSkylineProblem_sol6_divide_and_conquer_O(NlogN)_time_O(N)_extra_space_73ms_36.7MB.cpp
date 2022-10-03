class Solution {
private:
    vector<pair<int, int>> solve(vector<vector<int>>& buildings, const int& L, const int& R){
        vector<pair<int, int>> keyPoints;
        if(L == R){
            int x1 = buildings[L][0];
            int x2 = buildings[L][1];
            int height = buildings[L][2];
            keyPoints.push_back({x1, height});
            keyPoints.push_back({x2, 0});
        }else{
            const int MID = (L + R) / 2;
            vector<pair<int, int>> leftKeyPoints = solve(buildings, L, MID);
            vector<pair<int, int>> rightKeyPoints = solve(buildings, MID + 1, R);
            
            int leftIdx = 0;
            int rightIdx = 0;
            int lastLeftHeight = 0;
            int lastRightHeight = 0;
            while(leftIdx < (int)leftKeyPoints.size() || rightIdx < (int)rightKeyPoints.size()){
                long long leftX = (leftIdx == (int)leftKeyPoints.size() ? LLONG_MAX : leftKeyPoints[leftIdx].first);
                int leftHeight = (leftIdx == (int)leftKeyPoints.size() ? 0 : leftKeyPoints[leftIdx].second);
                
                long long rightX = (rightIdx == (int)rightKeyPoints.size() ? LLONG_MAX : rightKeyPoints[rightIdx].first);
                int rightHeight = (rightIdx == (int)rightKeyPoints.size() ? 0 : rightKeyPoints[rightIdx].second);
                
                int bestX = 0;
                if(leftX < rightX){
                    bestX = leftX;
                    lastLeftHeight = leftHeight;
                    leftIdx += 1;
                }else if(leftX > rightX){
                    bestX = rightX;
                    lastRightHeight = rightHeight;
                    rightIdx += 1;
                }else{
                    bestX = leftX;
                    lastLeftHeight = leftHeight;
                    lastRightHeight = rightHeight;
                    leftIdx += 1;
                    rightIdx += 1;
                }
                int bestHeight = max(lastLeftHeight, lastRightHeight);
                
                if(keyPoints.empty() || keyPoints.back().second != bestHeight){
                    keyPoints.push_back({bestX, bestHeight});
                }
            }
        }
        return keyPoints;
    }
    
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        const int N = buildings.size();
        vector<pair<int, int>> keyPoints = solve(buildings, 0, N - 1);
        
        const int P = keyPoints.size();
        vector<vector<int>> keyPointsWithVector(P, vector<int>(2));
        for(int i = 0; i < P; ++i){
            keyPointsWithVector[i][0] = keyPoints[i].first;
            keyPointsWithVector[i][1] = keyPoints[i].second;
        }
        
        return keyPointsWithVector;
    }
};