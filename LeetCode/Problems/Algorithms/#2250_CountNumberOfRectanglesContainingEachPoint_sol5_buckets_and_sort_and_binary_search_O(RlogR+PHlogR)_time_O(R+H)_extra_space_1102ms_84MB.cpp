class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        const int R = rectangles.size();
        const int P = points.size();
        
        // buckets[h] contains the sorted widths of rectangles with height equal to h
        vector<vector<int>> buckets;
        int maxRectangleWidth = 0;
        int maxRectangleHeight = 0;
        for(int i = 0; i < R; ++i){
            int width = rectangles[i][0];
            int height = rectangles[i][1];
            if(height >= (int)buckets.size()){
                buckets.resize(height + 1);
            }
            buckets[height].push_back(width);
            maxRectangleWidth = max(maxRectangleWidth, width);
            maxRectangleHeight = max(maxRectangleHeight, height);
        }
        
        for(int height = 0; height <= maxRectangleHeight; ++height){
            sort(buckets[height].begin(), buckets[height].end());
        }
        
        // for a given point (x, y):
        //     iterate over all buckets[height] with height >= y and
        //     count with binary search the number of widths >= x in the buckets[height]
        vector<int> res(P);
        for(int j = 0; j < P; ++j){
            int x = points[j][0];
            int y = points[j][1];
            
            if(x > maxRectangleWidth || y > maxRectangleHeight){
                continue;
            }
            
            for(int height = y; height <= maxRectangleHeight; ++height){
                int lowerBoundPos = lower_bound(buckets[height].begin(), buckets[height].end(), x) - buckets[height].begin();
                int validRectanglesCount = (int)buckets[height].size() - lowerBoundPos;
                res[j] += validRectanglesCount;
            }
        }
        
        return res;
    }
};