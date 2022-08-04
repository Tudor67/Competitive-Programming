class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        const int R = rectangles.size();
        const int P = points.size();
        
        // sort rectangles
        vector<pair<int, int>> sortedRectangles(R);
        int maxRectangleWidth = 0;
        int maxRectangleHeight = 0;
        for(int i = 0; i < R; ++i){
            int width = rectangles[i][0];
            int height = rectangles[i][1];
            sortedRectangles[i] = {width, height};
            maxRectangleWidth = max(maxRectangleWidth, width);
            maxRectangleHeight = max(maxRectangleHeight, height);
        }
        
        sort(sortedRectangles.begin(), sortedRectangles.end());
        
        // sort points and keep their indices in the original vector
        vector<tuple<int, int, int>> sortedPointsWithIndices(P);
        for(int j = 0; j < P; ++j){
            sortedPointsWithIndices[j] = {points[j][0], points[j][1], j};
        }
        
        sort(sortedPointsWithIndices.begin(), sortedPointsWithIndices.end());
        
        // solve from right (point with max x) to left (point with min x)
        vector<int> res(P);
        vector<int> count(maxRectangleHeight + 2);
        int i = R;
        for(int idx = P - 1; idx >= 0; --idx){
            int x, y, j;
            tie(x, y, j) = sortedPointsWithIndices[idx];
            
            if(x > maxRectangleWidth || y > maxRectangleHeight){
                continue;
            }
            
            while(0 <= i - 1 && x <= sortedRectangles[i - 1].first){
                int height = sortedRectangles[i - 1].second;
                count[height] += 1;
                i -= 1;
            }
            
            res[j] = accumulate(count.begin() + y, count.end(), 0);
        }
        
        return res;
    }
};