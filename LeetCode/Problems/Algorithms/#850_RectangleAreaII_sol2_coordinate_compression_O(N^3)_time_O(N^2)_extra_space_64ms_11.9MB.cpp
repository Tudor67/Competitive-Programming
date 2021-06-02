class Solution {
private:
    pair<unordered_map<int, int>, unordered_map<int, int>> coordinateCompression(const set<int>& ORIGINAL_VALUES){
        unordered_map<int, int> originalToCompressed;
        unordered_map<int, int> compressedToOriginal;
        int idx = 0;
        for(int originalValue: ORIGINAL_VALUES){
            originalToCompressed[originalValue] = idx;
            compressedToOriginal[idx] = originalValue;
            idx += 1;
        }
        return {originalToCompressed, compressedToOriginal};
    }
    
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        using Rectangle = vector<int>;
        
        set<int> xOriginalValues;
        set<int> yOriginalValues;
        for(const Rectangle& R: rectangles){
            xOriginalValues.insert(R[0]);
            yOriginalValues.insert(R[1]);
            xOriginalValues.insert(R[2]);
            yOriginalValues.insert(R[3]);
        }
        
        pair<unordered_map<int, int>, unordered_map<int, int>> px = coordinateCompression(xOriginalValues);
        unordered_map<int, int> originalToCompressedX(px.first);
        unordered_map<int, int> compressedToOriginalX(px.second);
        
        pair<unordered_map<int, int>, unordered_map<int, int>> py = coordinateCompression(yOriginalValues);
        unordered_map<int, int> originalToCompressedY(py.first);
        unordered_map<int, int> compressedToOriginalY(py.second);

        const int ROWS = originalToCompressedY.size();
        const int COLS = originalToCompressedX.size();
        const int MODULO = 1e9 + 7;
        
        vector<vector<bool>> grid(ROWS, vector<bool>(COLS, false));
        for(const Rectangle& R: rectangles){
            int compressedColStart = originalToCompressedX[R[0]];
            int compressedRowStart = originalToCompressedY[R[1]];
            int compressedColEnd = originalToCompressedX[R[2]];
            int compressedRowEnd = originalToCompressedY[R[3]];
            for(int row = compressedRowStart; row < compressedRowEnd; ++row){
                for(int col = compressedColStart; col < compressedColEnd; ++col){
                    grid[row][col] = true;
                }
            }
        }
        
        long long totalArea = 0;
        for(int row = 0; row < ROWS - 1; ++row){
            for(int col = 0; col < COLS - 1; ++col){
                if(grid[row][col]){
                    long long h = compressedToOriginalY[row + 1] - compressedToOriginalY[row];
                    long long w = compressedToOriginalX[col + 1] - compressedToOriginalX[col];
                    totalArea += (h * w) % MODULO;
                    totalArea %= MODULO;
                }
            }
        }
        
        return totalArea;
    }
};