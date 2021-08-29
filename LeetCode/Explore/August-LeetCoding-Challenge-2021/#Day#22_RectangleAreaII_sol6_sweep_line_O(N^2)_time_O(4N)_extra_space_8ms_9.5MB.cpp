class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const int MODULO = 1e9 + 7;
        
        using Rectangle = vector<int>;
        using Segment = pair<int, int>;
        
        unordered_map<int, vector<Segment>> startSegments;
        unordered_map<int, vector<Segment>> endSegments;
        set<int> xSortedSet;
        for(const Rectangle& R: rectangles){
            int x1 = R[0];
            int y1 = R[1];
            int x2 = R[2];
            int y2 = R[3];
            startSegments[x1].push_back({y1, y2});
            endSegments[x2].push_back({y1, y2});
            xSortedSet.insert(x1);
            xSortedSet.insert(x2);
        }
        
        int totalArea = 0;
        int prevX = *xSortedSet.begin();
        multiset<Segment> activeVerticalSegments;
        for(int x: xSortedSet){
            // x is fixed => update total area, add all starting vertical segments, erase all ending vertical segments
            // update total area
            if(!activeVerticalSegments.empty()){
                long long w = x - prevX;
                long long hSum = 0;
                int maxY = activeVerticalSegments.begin()->first;
                for(const Segment& SEG: activeVerticalSegments){
                    int y1 = SEG.first;
                    int y2 = SEG.second;
                    hSum += max(0, y2 - max(y1, maxY));
                    maxY = max(maxY, y2);
                }
                totalArea += (w * hSum) % MODULO;
                totalArea %= MODULO;
            }
            // update active vertical segments
            for(const Segment& SEG: startSegments[x]){
                activeVerticalSegments.insert(SEG);
            }
            for(const Segment& SEG: endSegments[x]){
                activeVerticalSegments.erase(activeVerticalSegments.find(SEG));
            }
            prevX = x;
        }
        
        return totalArea;
    }
};