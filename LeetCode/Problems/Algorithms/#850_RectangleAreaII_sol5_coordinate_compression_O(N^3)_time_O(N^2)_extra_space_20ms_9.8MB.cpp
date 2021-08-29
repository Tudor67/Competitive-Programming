class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const int MODULO = 1e9 + 7;
        
        using Rectangle = vector<int>;
        
        // coordinate compression
        set<int> xCoordinates;
        set<int> yCoordinates;
        for(const Rectangle& R: rectangles){
            xCoordinates.insert(R[0]);
            xCoordinates.insert(R[2]);
            yCoordinates.insert(R[1]);
            yCoordinates.insert(R[3]);
        }
        
        vector<int> xCompressedToOriginal;
        unordered_map<int, int> xOriginalToCompressed;
        for(int x: xCoordinates){
            xCompressedToOriginal.push_back(x);
            xOriginalToCompressed[x] = (int)xCompressedToOriginal.size() - 1;
        }
        
        vector<int> yCompressedToOriginal;
        unordered_map<int, int> yOriginalToCompressed;
        for(int y: yCoordinates){
            yCompressedToOriginal.push_back(y);
            yOriginalToCompressed[y] = (int)yCompressedToOriginal.size() - 1;
        }
        
        // mark cells in the compressed space
        const int X_SIZE = xOriginalToCompressed.size();
        const int Y_SIZE = yOriginalToCompressed.size();
        vector<vector<bool>> grid(X_SIZE, vector<bool>(Y_SIZE, false));
        
        for(const Rectangle& R: rectangles){
            int x1 = xOriginalToCompressed[R[0]];
            int y1 = yOriginalToCompressed[R[1]];
            int x2 = xOriginalToCompressed[R[2]];
            int y2 = yOriginalToCompressed[R[3]];
            for(int x = x1; x < x2; ++x){
                for(int y = y1; y < y2; ++y){
                    grid[x][y] = true;
                }
            }
        }
        
        // compute total area using compressed and original spaces
        int totalArea = 0;
        for(int x = 0; x + 1 < X_SIZE; ++x){
            for(int y = 0; y + 1 < Y_SIZE; ++y){
                if(grid[x][y]){
                    long long w = xCompressedToOriginal[x + 1] - xCompressedToOriginal[x];
                    long long h = yCompressedToOriginal[y + 1] - yCompressedToOriginal[y];
                    int area = (w * h) % MODULO;
                    totalArea += area;
                    totalArea %= MODULO;
                }
            }
        }
        
        return totalArea;
    }
};