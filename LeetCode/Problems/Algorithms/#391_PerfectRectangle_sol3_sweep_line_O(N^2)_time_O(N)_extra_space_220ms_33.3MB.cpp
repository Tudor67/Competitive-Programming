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
    
    bool anyOverlap(vector<Rectangle>& rectangles){        
        // sweep line
        set<int> xSet;
        unordered_map<int, vector<Segment>> startVerticalSegments;
        unordered_map<int, vector<Segment>> endVerticalSegments;
        for(const Rectangle& R: rectangles){
            int xStart = R[0];
            int xEnd = R[2];
            int yStart = R[1];
            int yEnd = R[3];
            
            xSet.insert(xStart);
            xSet.insert(xEnd);
            
            startVerticalSegments[xStart].push_back({yStart, yEnd});
            endVerticalSegments[xEnd].push_back({yStart, yEnd});
        }
        
        multiset<Segment> activeVerticalSegments;
        for(int x: xSet){
            int maxY = -INF;
            for(const Segment& SEG: activeVerticalSegments){
                if(SEG.first <= maxY && maxY <= SEG.second - 1){
                    return true;
                }
                maxY = max(SEG.second - 1, maxY);
            }
            
            for(const Segment& SEG: startVerticalSegments[x]){
                activeVerticalSegments.insert(SEG);
            }
            
            for(const Segment& SEG: endVerticalSegments[x]){
                activeVerticalSegments.erase(activeVerticalSegments.find(SEG));
            }
        }
        
        return false;
    }
    
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        return areaMatch(rectangles) && !anyOverlap(rectangles);
    }
};