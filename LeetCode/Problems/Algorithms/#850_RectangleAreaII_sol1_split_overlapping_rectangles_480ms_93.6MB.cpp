class Solution {
private:
    using Rectangle = vector<int>;
    
    bool isValid(const Rectangle& R){
        return (R[0] < R[2] && R[1] < R[3]);
    }
    
    long long computeArea(const Rectangle& R){
        return (long long)(R[3] - R[1]) * (long long)(R[2] - R[0]);
    }
    
    Rectangle computeIntersection(const Rectangle& A, const Rectangle& B){
        int x1 = max(A[0], B[0]);
        int x2 = min(A[2], B[2]);
        int y1 = max(A[1], B[1]);
        int y2 = min(A[3], B[3]);
        return {x1, y1, x2, y2};
    }
    
    vector<Rectangle> split(const Rectangle& R, const Rectangle& I){
        return {{R[0], R[1], I[0], R[3]},
                {I[0], R[1], I[2], I[1]},
                {I[0], I[3], I[2], R[3]},
                {I[2], R[1], R[2], R[3]}};
    }
    
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        for(int i = 0; i < (int)rectangles.size(); ++i){
            for(int j = i + 1; j < (int)rectangles.size(); ++j){
                Rectangle intersection = computeIntersection(rectangles[i], rectangles[j]);
                if(isValid(intersection)){
                    vector<Rectangle> newRectangles = split(rectangles[i], intersection);
                    for(const Rectangle& newR: newRectangles){
                        if(isValid(newR)){
                            rectangles.push_back(newR);
                        }
                    }
                    // erase current rectangle
                    rectangles[i] = {0, 0, 0, 0};
                    break;
                }
            }
        }
        
        const long long MODULO = 1e9 + 7;
        long long totalArea = 0;
        for(const Rectangle& R: rectangles){
            if(isValid(R)){
                totalArea += computeArea(R);
                totalArea %= MODULO;
            }
        }
        
        return totalArea;
    }
};