class SegmentTree{
private:
    const int N;
    const vector<int> ORIGINAL_COORDINATES;
    vector<int> count;
    vector<long long> totalLength;
    
    void updateInterval(int node, int l, int r, const int& L, const int& R, const int& VAL){
        if(r < L || R < l){
            return;
        }else if(L <= l && r <= R){
            count[node] += VAL;
        }else{
            int mid = (l + r) / 2;
            updateInterval(2 * node + 1, l, mid, L, R, VAL);
            updateInterval(2 * node + 2, mid + 1, r, L, R, VAL);
        }
        if(count[node] > 0){
            totalLength[node] = (ORIGINAL_COORDINATES[r + 1] - ORIGINAL_COORDINATES[l]);
        }else if(2 * node + 2 < (int)totalLength.size()){
            totalLength[node] = totalLength[2 * node + 1] + totalLength[2 * node + 2];
        }else{
            totalLength[node] = 0;
        }
    }
    
public:
    SegmentTree(const int& N, const vector<int>& ORIGINAL_COORDINATES): N(N), ORIGINAL_COORDINATES(ORIGINAL_COORDINATES){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        count.resize(2 * minLeaves);
        totalLength.resize(2 * minLeaves);
    }
    
    void addInterval(const int& L_COMPRESSED, const int& R_COMPRESSED){
        if(L_COMPRESSED <= R_COMPRESSED){
            updateInterval(0, 0, N - 1, L_COMPRESSED, R_COMPRESSED, 1);
        }
    }
    
    void removeInterval(const int& L_COMPRESSED, const int& R_COMPRESSED){
        if(L_COMPRESSED <= R_COMPRESSED){
            updateInterval(0, 0, N - 1, L_COMPRESSED, R_COMPRESSED, -1);
        }
    }
    
    long long getTotalLength(){
        return totalLength[0];
    }
};

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
        set<int> yCoordinates;
        for(const Rectangle& R: rectangles){
            int startX = R[0];
            int startY = R[1];
            int endX = R[2];
            int endY = R[3];
            startSegments[startX].push_back({startY, endY});
            endSegments[endX].push_back({startY, endY});
            xCoordinates.insert(startX);
            xCoordinates.insert(endX);
            yCoordinates.insert(startY);
            yCoordinates.insert(endY);
        }
        
        const int M = yCoordinates.size();
        vector<int> compressedToOriginalY(yCoordinates.begin(), yCoordinates.end());
        unordered_map<int, int> originalToCompressedY;
        int idx = -1;
        for(int y: yCoordinates){
            idx += 1;
            originalToCompressedY[y] = idx;
        }
        
        long long totalArea = 0;
        SegmentTree activeSegmentsTree(M, compressedToOriginalY); // only vertical segments which are still active at X
        
        int minX = *xCoordinates.begin();
        for(const Segment& SEG: startSegments[minX]){
            activeSegmentsTree.addInterval(originalToCompressedY[SEG.first], originalToCompressedY[SEG.second] - 1);
        }
        
        for(set<int>::iterator it = next(xCoordinates.begin()); it != xCoordinates.end(); ++it){
            const int PREV_X = *prev(it);
            const int X = *it;
            const long long WIDTH = X - PREV_X;
            const long long HEIGHT_SUM = activeSegmentsTree.getTotalLength();

            for(const Segment& SEG: startSegments[X]){
                activeSegmentsTree.addInterval(originalToCompressedY[SEG.first], originalToCompressedY[SEG.second] - 1);
            }
            
            for(const Segment& SEG: endSegments[X]){
                activeSegmentsTree.removeInterval(originalToCompressedY[SEG.first], originalToCompressedY[SEG.second] - 1);
            }
            
            totalArea += (WIDTH * HEIGHT_SUM) % MODULO;
            totalArea %= MODULO;
        }
        
        return totalArea;
    }
};