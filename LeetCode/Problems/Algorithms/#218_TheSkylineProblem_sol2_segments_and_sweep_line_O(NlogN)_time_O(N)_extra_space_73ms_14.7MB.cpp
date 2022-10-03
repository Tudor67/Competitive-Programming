class Segment{
public:
    int x1;
    int x2;
    int height;
    
    Segment(int x1, int x2, int height = 0){
        this->x1 = x1;
        this->x2 = x2;
        this->height = height;
    }
    
    bool intersects(const Segment& OTHER) const{
        return max(this->x1, OTHER.x1) <= min(this->x2, OTHER.x2);
    }
    
    static bool incXComp(const Segment& LHS, const Segment& RHS){
        return (LHS.x1 < RHS.x1);
    }
    
    static bool incHeightIncXComp(const Segment& LHS, const Segment& RHS){
        return ((LHS.height < RHS.height) ||
                (LHS.height == RHS.height && LHS.x1 < RHS.x1));
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        const int N = buildings.size();
        
        vector<Segment> sortedSegments;
        int maxX = buildings[0][1];
        for(const vector<int>& B: buildings){
            int x1 = B[0];
            int x2 = B[1];
            int height = B[2];
            sortedSegments.push_back(Segment(x1, x2, height));
            if(maxX < x1){
                sortedSegments.push_back(Segment(maxX, x1, 0));
            }
            maxX = max(maxX, x2);
        }
        
        sort(sortedSegments.begin(), sortedSegments.end(), Segment::incHeightIncXComp);
        
        set<Segment, decltype(&Segment::incXComp)> mergedSegments(Segment::incXComp);
        vector<Segment> resSegments;
        for(int i = (int)sortedSegments.size() - 1; i >= 0; --i){
            Segment currentSegment = sortedSegments[i];
            
            auto it = mergedSegments.lower_bound(currentSegment);
            if(it != mergedSegments.begin() && currentSegment.x1 <= prev(it)->x2){
                it = prev(it); 
            }
            
            int minX = currentSegment.x1;
            int maxX = currentSegment.x2;
            int prevX = currentSegment.x1;
            while(it != mergedSegments.end() && it->intersects(currentSegment)){
                if(prevX < it->x1){
                    resSegments.push_back(Segment(prevX, it->x1, currentSegment.height));
                }
                prevX = it->x2;
                
                minX = min(minX, it->x1);
                maxX = max(maxX, it->x2);
                
                it = mergedSegments.erase(it);
            }
            
            if(prevX < currentSegment.x2){
                resSegments.push_back(Segment(prevX, currentSegment.x2, currentSegment.height));
            }
            
            mergedSegments.insert(Segment(minX, maxX));
        }
        
        sort(resSegments.begin(), resSegments.end(), Segment::incXComp);
        
        const int R = resSegments.size();
        vector<vector<int>> resPoints;
        for(int i = 0; i < R; ++i){
            if(i == 0 || resSegments[i - 1].height != resSegments[i].height){
                resPoints.push_back({resSegments[i].x1, resSegments[i].height});
            }
        }
        resPoints.push_back({resSegments[R - 1].x2, 0});
        
        return resPoints;
    }
};