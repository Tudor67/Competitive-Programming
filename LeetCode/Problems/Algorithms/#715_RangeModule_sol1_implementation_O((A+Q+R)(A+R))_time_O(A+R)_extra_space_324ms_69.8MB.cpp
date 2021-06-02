class RangeModule {
private:
    using Segment = pair<int, int>;
    vector<Segment> segments;
    
    bool intersects(const Segment& SEG1, const Segment& SEG2){
        int l = max(SEG1.first, SEG2.first);
        int r = min(SEG1.second, SEG2.second);
        return (l <= r);
    }
    
    bool areNeighbors(const Segment& SEG1, const Segment& SEG2){
        return (SEG1.second + 1 == SEG2.first || SEG2.second + 1 == SEG1.first);
    }
    
    Segment intersection(const Segment& SEG1, const Segment& SEG2){
        // only for segments that intersect
        int l = max(SEG1.first, SEG2.first);
        int r = min(SEG1.second, SEG2.second);
        return {l, r};
    }
    
    Segment merge(const Segment& SEG1, const Segment& SEG2){
        // only for neighboring segments and for segments that intersect
        int l = min(SEG1.first, SEG2.first);
        int r = max(SEG1.second, SEG2.second);
        return {l, r};
    }
    
    vector<Segment> difference(const Segment& SEG1, const Segment& SEG2){
        // return (SEG1 - SEG2) if and only if SEG1 intersects with SEG2
        vector<Segment> diffSegments;
        if(SEG1.first <= SEG2.first - 1){
            diffSegments.push_back({SEG1.first, SEG2.first - 1});
        }
        if(SEG2.second + 1 <= SEG1.second){
            diffSegments.push_back({SEG2.second + 1, SEG1.second});
        }
        return diffSegments;
    }
    
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        Segment currentSegment = {left, right - 1};
        for(const Segment& SEG: segments){
            if(intersects(SEG, currentSegment) || areNeighbors(SEG, currentSegment)){
                currentSegment = merge(SEG, currentSegment);
            }
        }
        int i = 0;
        int j = 0;
        while(j < (int)segments.size()){
            if(intersects(segments[j], currentSegment)){
                j += 1;
            }else{
                segments[i] = segments[j];
                i += 1;
                j += 1;
            }
        }
        segments.resize(i);
        segments.push_back(currentSegment);
    }
    
    bool queryRange(int left, int right) {
        Segment currentSegment = {left, right - 1};
        for(const Segment& SEG: segments){
            if(intersects(SEG, currentSegment) && intersection(SEG, currentSegment) == currentSegment){
                return true;
            }
        }
        return false;
    }
    
    void removeRange(int left, int right) {
        vector<Segment> extraSegments;
        Segment currentSegment = {left, right - 1};
        int i = 0;
        int j = 0;
        while(j < (int)segments.size()){
            if(intersects(segments[j], currentSegment)){
                int extraSegmentsPrevSize = extraSegments.size();
                vector<Segment> diffSegments = difference(segments[j], currentSegment);
                extraSegments.resize(extraSegmentsPrevSize + diffSegments.size());
                copy(diffSegments.begin(), diffSegments.end(), extraSegments.begin() + extraSegmentsPrevSize);
                j += 1;
            }else{
                segments[i] = segments[j];
                i += 1;
                j += 1;
            }
        }
        segments.resize(i + (int)extraSegments.size());
        copy(extraSegments.begin(), extraSegments.end(), segments.begin() + i);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */