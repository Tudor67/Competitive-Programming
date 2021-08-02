class SegmentTree{
private:
    const int N;
    vector<int> maxCount;
    vector<int> lazyCount;
    
    void propagateLazyCount(int node){
        if(2 * node + 2 < (int)lazyCount.size()){
            lazyCount[2 * node + 1] += lazyCount[node];
            lazyCount[2 * node + 2] += lazyCount[node];
        }
        lazyCount[node] = 0;
    }
    
    void update(int node, int l, int r, const int& L, const int& R, const int& VAL){
        if(r < L || R < l){
            // stop
        }else if(L <= l && r <= R){
            lazyCount[node] += VAL;
            maxCount[node] += lazyCount[node];
            propagateLazyCount(node);
        }else{
            propagateLazyCount(node);
            int mid = (l + r) / 2;
            update(2 * node + 1, l, mid, L, R, VAL);
            update(2 * node + 2, mid + 1, r, L, R, VAL);
            maxCount[node] = max(maxCount[2 * node + 1], maxCount[2 * node + 2]);
        }
    }
    
public:
    SegmentTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        maxCount.resize(2 * minLeaves, 0);
        lazyCount.resize(2 * minLeaves, 0);
    }
    
    void add(const int& L, const int& R){
        if(L <= R){
            update(0, 0, N - 1, L, R, 1);
        }
    }
    
    void remove(const int& L, const int& R){
        if(L <= R){
            update(0, 0, N - 1, L, R, -1);
        }
    }
    
    int getMaxCount(){
        return maxCount[0];
    }
};

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
        // coordinate compression (y values)
        set<int> ySet;
        for(const Rectangle& R: rectangles){
            int yStart = R[1];
            int yEnd = R[3];
            ySet.insert(yStart);
            ySet.insert(yEnd);
        }
        
        const int M = ySet.size();
        vector<int> compressedToOriginalY(ySet.begin(), ySet.end());
        unordered_map<int, int> originalToCompressedY;
        for(int i = 0; i < M; ++i){
            originalToCompressedY[compressedToOriginalY[i]] = i;
        }
        
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
        
        SegmentTree activeVerticalSegments(M);
        for(int x: xSet){
            for(const Segment& SEG: endVerticalSegments[x]){
                activeVerticalSegments.remove(originalToCompressedY[SEG.first], originalToCompressedY[SEG.second] - 1);
            }
            
            for(const Segment& SEG: startVerticalSegments[x]){
                activeVerticalSegments.add(originalToCompressedY[SEG.first], originalToCompressedY[SEG.second] - 1);
                if(activeVerticalSegments.getMaxCount() >= 2){
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