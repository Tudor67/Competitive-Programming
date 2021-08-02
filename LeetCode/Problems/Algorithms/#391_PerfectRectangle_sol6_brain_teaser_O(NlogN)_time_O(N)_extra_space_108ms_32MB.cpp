class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        using Rectangle = vector<int>;
        const int INF = 1e9;
        
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
        map<pair<int, int>, bool> freqParity;
        for(const Rectangle& R: rectangles){
            int xStart = R[0];
            int xEnd = R[2];
            int yStart = R[1];
            int yEnd = R[3];
            
            freqParity[{xStart, yStart}] ^= 1;
            freqParity[{xStart, yEnd}] ^= 1;
            freqParity[{xEnd, yStart}] ^= 1;
            freqParity[{xEnd, yEnd}] ^= 1;
        }
        
        int cornersWithOddFreq = 0;
        for(const pair<pair<int, int>, bool>& P: freqParity){
            cornersWithOddFreq += P.second;
        }
        
        bool validNumberOfCorners = (cornersWithOddFreq == 4 &&
                                     freqParity[{minX, minY}] &&
                                     freqParity[{minX, maxY}] &&
                                     freqParity[{maxX, minY}] &&
                                     freqParity[{maxX, maxY}]);
        
        return (validArea && validNumberOfCorners);
    }
};