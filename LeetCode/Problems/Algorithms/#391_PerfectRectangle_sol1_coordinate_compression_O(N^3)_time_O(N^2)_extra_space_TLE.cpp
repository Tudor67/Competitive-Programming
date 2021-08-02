class Solution {
private:
    using Rectangle = vector<int>;
    
    const int INF = 1e9;
    
    bool areaMatch(vector<Rectangle>& rectangles){
        int minX = INF;
        int maxX = -INF;
        int minY = INF;
        int maxY = -INF;
        long long area = 0;
        for(const Rectangle& R: rectangles){
            int xStart = R[0];
            int xEnd = R[2];
            int yStart = R[1];
            int yEnd = R[3];
            
            minX = min(xStart, minX);
            maxX = max(xEnd, maxX);
            minY = min(yStart, minY);
            maxY = max(yEnd, maxY);
            area += (long long)(xEnd - xStart) * (long long)(yEnd - yStart);
        }
        
        long long targetArea = (long long)(maxX - minX) * (long long)(maxY - minY);
        
        return (targetArea == area);
    }
    
    bool anyOverlap(vector<Rectangle>& rectangles){
        // coordinate compression
        set<int> xSet;
        set<int> ySet;
        for(const Rectangle& R: rectangles){
            int xStart = R[0];
            int xEnd = R[2];
            int yStart = R[1];
            int yEnd = R[3];
            
            xSet.insert(xStart);
            xSet.insert(xEnd);
            ySet.insert(yStart);
            ySet.insert(yEnd);
        }
        
        // coordinate compression (x values)
        vector<int> compressedToOriginalX(xSet.begin(), xSet.end());
        unordered_map<int, int> originalToCompressedX;
        for(int i = 0; i < (int)compressedToOriginalX.size(); ++i){
            originalToCompressedX[compressedToOriginalX[i]] = i;
        }
        
        // coordinate compression (y values)
        vector<int> compressedToOriginalY(ySet.begin(), ySet.end());
        unordered_map<int, int> originalToCompressedY;
        for(int i = 0; i < (int)compressedToOriginalY.size(); ++i){
            originalToCompressedY[compressedToOriginalY[i]] = i;
        }
        
        // compressed rectangles
        const int COMPRESSED_ROWS = compressedToOriginalY.size();
        const int COMPRESSED_COLS = compressedToOriginalX.size();
        vector<vector<bool>> grid(COMPRESSED_ROWS, vector<bool>(COMPRESSED_COLS, false));
        for(const Rectangle& R: rectangles){
            int xStart = R[0];
            int xEnd = R[2];
            int yStart = R[1];
            int yEnd = R[3];
            
            for(int row = originalToCompressedY[yStart]; row < originalToCompressedY[yEnd]; ++row){
                for(int col = originalToCompressedX[xStart]; col < originalToCompressedX[xEnd]; ++col){
                    if(grid[row][col]){
                        return true;
                    }
                    grid[row][col] = true;
                }
            }
        }
        
        return false;
    }
    
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        return areaMatch(rectangles) && !anyOverlap(rectangles);
    }
};