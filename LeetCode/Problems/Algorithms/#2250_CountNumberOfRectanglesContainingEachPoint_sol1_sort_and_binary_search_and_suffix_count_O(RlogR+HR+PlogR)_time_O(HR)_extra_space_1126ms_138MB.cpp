class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        const int R = rectangles.size();
        const int P = points.size();
        
        // sort rectangles
        int maxRectangleWidth = 0;
        int maxRectangleHeight = 0;
        vector<pair<int, int>> sortedRectangles(R);
        for(int i = 0; i < R; ++i){
            int width = rectangles[i][0];
            int height = rectangles[i][1];
            sortedRectangles[i] = {width, height};
            maxRectangleWidth = max(maxRectangleWidth, width);
            maxRectangleHeight = max(maxRectangleHeight, height);
        }
        
        sort(sortedRectangles.begin(), sortedRectangles.end());
        
        // create suffCount[y][i]: number of rectangles in sortedRectangles[i .. R - 1]
        //                         with height >= y
        vector<vector<int>> suffCount(maxRectangleHeight + 2, vector<int>(R + 1));
        for(int i = R - 1; i >= 0; --i){
            for(int height = maxRectangleHeight; height >= 0; --height){
                if(height == sortedRectangles[i].second){
                    suffCount[height][i] = 1;
                }
                suffCount[height][i] += suffCount[height + 1][i];
                suffCount[height][i] += suffCount[height][i + 1];
                suffCount[height][i] -= suffCount[height + 1][i + 1];
            }
        }
        
        // solve
        vector<int> res(P);
        for(int j = 0; j < P; ++j){
            int x = points[j][0];
            int y = points[j][1];
            
            if(x > maxRectangleWidth || y > maxRectangleHeight){
                continue;
            }
            
            // binary search min pos i such that sortedRectangles[i].first >= x
            int l = 0;
            int r = R - 1;
            while(l != r){
                int mid = (l + r) / 2;
                if(sortedRectangles[mid].first < x){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }
            
            int i = r;
            res[j] = suffCount[y][i];
        }
        
        return res;
    }
};