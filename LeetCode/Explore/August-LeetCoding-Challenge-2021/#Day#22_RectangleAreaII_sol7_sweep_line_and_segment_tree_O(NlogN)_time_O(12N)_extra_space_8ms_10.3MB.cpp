class SegmentTree{
private:
    const int N;
    const vector<int> ORIGINAL_COORDINATES;
    vector<long long> count;
    vector<long long> totalLength;
    
    void updateInterval(int node, int l, int r, const int& L, const int& R, const int& VAL){
        if(r < L || R < l){
            // stop
        }else if(L <= l && r <= R){
            count[node] += VAL;
        }else{
            int mid = (l + r) / 2;
            updateInterval(2 * node + 1, l, mid, L, R, VAL);
            updateInterval(2 * node + 2, mid + 1, r, L, R, VAL);
        }
        if(count[node] > 0){
            totalLength[node] = ORIGINAL_COORDINATES[r + 1] - ORIGINAL_COORDINATES[l];
        }else if(2 * node + 2 < (int)totalLength.size()){
            totalLength[node] = totalLength[2 * node + 1] + totalLength[2 * node + 2];
        }else{
            totalLength[node] = 0;
        }
    }
    
public:
    SegmentTree(const vector<int>& ORIGINAL_COORDINATES): N(ORIGINAL_COORDINATES.size()), ORIGINAL_COORDINATES(ORIGINAL_COORDINATES){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        count.resize(2 * minLeaves, 0);
        totalLength.resize(2 * minLeaves, 0);
    }
    
    void addInterval(const int& L, const int& R){
        if(L <= R){
            updateInterval(0, 0, N - 1, L, R, 1);
        }
    }
    
    void removeInterval(const int& L, const int& R){
        if(L <= R){
            updateInterval(0, 0, N - 1, L, R, -1);
        }
    }
    
    long long getTotalLength(){
        return totalLength[0];
    }
};

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const int MODULO = 1e9 + 7;
        
        using Rectangle = vector<int>;
        using Segment = pair<int, int>;
        
        unordered_map<int, vector<Segment>> startSegments;
        unordered_map<int, vector<Segment>> endSegments;
        set<int> xSortedSet;
        set<int> ySortedSet;
        for(const Rectangle& R: rectangles){
            int x1 = R[0];
            int y1 = R[1];
            int x2 = R[2];
            int y2 = R[3];
            startSegments[x1].push_back({y1, y2});
            endSegments[x2].push_back({y1, y2});
            xSortedSet.insert(x1);
            xSortedSet.insert(x2);
            ySortedSet.insert(y1);
            ySortedSet.insert(y2);
        }
        
        const int M = ySortedSet.size();
        vector<int> yCompressedToOriginal(ySortedSet.begin(), ySortedSet.end());
        unordered_map<int, int> yOriginalToCompressed;
        for(int i = 0; i < M; ++i){
            yOriginalToCompressed[yCompressedToOriginal[i]] = i;
        }
        
        int totalArea = 0;
        int prevX = *xSortedSet.begin();
        SegmentTree activeVerticalSegments(yCompressedToOriginal);
        for(int x: xSortedSet){
            // x is fixed => update total area, add all starting vertical segments, erase all ending vertical segments
            // update total area
            long long w = x - prevX;
            long long hSum = activeVerticalSegments.getTotalLength();
            totalArea += (w * hSum) % MODULO;
            totalArea %= MODULO;
            // update active vertical segments
            for(const Segment& SEG: startSegments[x]){
                activeVerticalSegments.addInterval(yOriginalToCompressed[SEG.first], yOriginalToCompressed[SEG.second] - 1);
            }
            for(const Segment& SEG: endSegments[x]){
                activeVerticalSegments.removeInterval(yOriginalToCompressed[SEG.first], yOriginalToCompressed[SEG.second] - 1);
            }
            prevX = x;
        }
        
        return totalArea;
    }
};