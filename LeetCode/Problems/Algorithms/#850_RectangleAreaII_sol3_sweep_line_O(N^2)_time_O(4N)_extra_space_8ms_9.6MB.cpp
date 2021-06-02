class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const int N = rectangles.size();
        const int MODULO = 1e9 + 7;
        
        using Rectangle = vector<int>;
        using Segment = pair<int, int>;
        
        unordered_map<int, vector<Segment>> startSegments;
        unordered_map<int, vector<Segment>> endSegments;
        set<int> xCoordinates;
        for(const Rectangle& R: rectangles){
            int startX = R[0];
            int startY = R[1];
            int endX = R[2];
            int endY = R[3];
            startSegments[startX].push_back({startY, endY});
            endSegments[endX].push_back({startY, endY});
            xCoordinates.insert(startX);
            xCoordinates.insert(endX);
        }
        
        long long totalArea = 0;
        int minX = *xCoordinates.begin();
        multiset<Segment> activeSegments; // only vertical segments which are still active at X
        for(const Segment& SEG: startSegments[minX]){
            activeSegments.insert(SEG);
        }
        
        for(set<int>::iterator it = next(xCoordinates.begin()); it != xCoordinates.end(); ++it){
            const int PREV_X = *prev(it);
            const int X = *it;
            const long long WIDTH = X - PREV_X;
            
            long long heightSum = 0;
            int maxY = -1;
            for(const Segment& SEG: activeSegments){
                int y1 = max(SEG.first, maxY);
                int y2 = max(SEG.second, maxY);
                heightSum += (y2 - y1);
                maxY = max(y2, maxY);
            }
            
            for(const Segment& SEG: startSegments[X]){
                activeSegments.insert(SEG);
            }
            
            for(const Segment& SEG: endSegments[X]){
                activeSegments.erase(activeSegments.find(SEG));
            }
            
            totalArea += (WIDTH * heightSum) % MODULO;
            totalArea %= MODULO;
        }
        
        return totalArea;
    }
};