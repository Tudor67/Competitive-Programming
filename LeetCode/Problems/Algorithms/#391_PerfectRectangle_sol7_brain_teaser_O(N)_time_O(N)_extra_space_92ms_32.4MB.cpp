class Solution {
private:
    using Rectangle = vector<int>;
    const int INF = 1e9;
    const int BASE = 1e8;
    
    long long pairToNum(int x, int y){
        return 1LL * x * BASE + y;
    }
    
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        // Step 1: compute area and targetArea
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
        bool validArea = (targetArea == area);
        
        // Step 2: compute freqParity for each corner of rectangles
        //         all rectangles will share all corners an even number of times,
        //         except the 4 extreme corners ({minX, minY}, .. {maxX, maxY}) which will be shared an odd number of times
        unordered_map<long long, bool> freqParity;
        for(const Rectangle& R: rectangles){
            int xStart = R[0];
            int xEnd = R[2];
            int yStart = R[1];
            int yEnd = R[3];
            
            freqParity[pairToNum(xStart, yStart)] ^= 1;
            freqParity[pairToNum(xStart, yEnd)] ^= 1;
            freqParity[pairToNum(xEnd, yStart)] ^= 1;
            freqParity[pairToNum(xEnd, yEnd)] ^= 1;
        }
        
        int cornersWithOddFreq = 0;
        for(const pair<long long, bool>& P: freqParity){
            cornersWithOddFreq += P.second;
        }
        
        bool validNumberOfCorners = (cornersWithOddFreq == 4 &&
                                     freqParity[pairToNum(minX, minY)] &&
                                     freqParity[pairToNum(minX, maxY)] &&
                                     freqParity[pairToNum(maxX, minY)] &&
                                     freqParity[pairToNum(maxX, maxY)]);
        
        return (validArea && validNumberOfCorners);
    }
};