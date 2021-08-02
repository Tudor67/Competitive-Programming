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
    
    bool intersects(const Segment& SEG1, const Segment& SEG2){
        return max(SEG1.first, SEG2.first) < min(SEG1.second, SEG2.second);
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
            for(const Segment& SEG: endVerticalSegments[x]){
                activeVerticalSegments.erase(activeVerticalSegments.find(SEG));
            }
            
            for(const Segment& SEG: startVerticalSegments[x]){
                auto it = activeVerticalSegments.lower_bound(SEG);
                if((it != activeVerticalSegments.end() && intersects(*it, SEG)) || 
                   (it != activeVerticalSegments.begin() && intersects(*prev(it), SEG))){
                    return true;
                }
                activeVerticalSegments.insert(SEG);
            }
        }
        
        return false;
    }
    
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        return areaMatch(rectangles) && !anyOverlap(rectangles);
    }
};