class Solution {
private:
    using Rectangle = vector<int>;
    using Segment = pair<int, int>;
    
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
    
    bool overlap(const Rectangle& R1, const Rectangle& R2){
        int xStartI = max(R1[0], R2[0]);
        int yStartI = max(R1[1], R2[1]);
        int xEndI = min(R1[2], R2[2]);
        int yEndI = min(R1[3], R2[3]);
        return (xStartI < xEndI && yStartI < yEndI);
    }
    
    bool anyOverlap(vector<Rectangle>& rectangles){        
        const int N = rectangles.size();
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if(overlap(rectangles[i], rectangles[j])){
                    return true;
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