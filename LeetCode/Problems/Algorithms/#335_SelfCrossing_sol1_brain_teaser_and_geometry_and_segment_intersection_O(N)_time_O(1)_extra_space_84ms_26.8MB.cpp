class Solution {
private:
    using Point = pair<long long, long long>;
    using Segment = pair<Point, Point>;
    
    int getOrientation(const Point& P1, const Point& P2, const Point& P3){
        long long a = P1.first * P2.second + P1.second * P3.first + P2.first * P3.second -
                      P3.first * P2.second - P3.second * P1.first - P2.first * P1.second;
        if(a < 0){
            return -1;
        }else if(a == 0){
            return 0;
        }
        return 1;
    }
    
    long double getDist(const Point& P1, const Point& P2){
        long double dx = P1.first - P2.first;
        long double dy = P1.second - P2.second;
        return sqrt(dx * dx + dy * dy);
    }
    
    bool intersects(const Segment& S1, const Segment& S2){
        int orientation1 = getOrientation(S1.first, S1.second, S2.first);
        int orientation2 = getOrientation(S1.first, S1.second, S2.second);
        int orientation3 = getOrientation(S2.first, S2.second, S1.first);
        int orientation4 = getOrientation(S2.first, S2.second, S1.second);
        if(orientation1 == orientation2 && orientation3 == orientation4 && orientation1 == 0 && orientation3 == 0){
            // collinearity
            if(getDist(S1.first, S2.first) + getDist(S2.first, S1.second) == getDist(S1.first, S1.second) ||
               getDist(S1.first, S2.second) + getDist(S2.second, S1.second) == getDist(S1.first, S1.second) ||
               getDist(S2.first, S1.first) + getDist(S1.first, S2.second) == getDist(S2.first, S2.second) ||
               getDist(S2.first, S1.second) + getDist(S1.second, S2.second) == getDist(S2.first, S2.second)){
                return true;
            }
        }
        if(orientation1 != orientation2 && orientation3 != orientation4){
            return true;
        }
        return false;
    }
    
public:
    bool isSelfCrossing(vector<int>& distance) {
        const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        const int N = distance.size();
        
        list<Segment> prevSegments;
        int x = 0;
        int y = 0;
        for(int i = 0; i < N; ++i){
            int prevX = x;
            int prevY = y;
            x += distance[i] * DIRECTIONS[i % 4].first;
            y += distance[i] * DIRECTIONS[i % 4].second;
            
            Segment currentSegment = {{prevX, prevY}, {x, y}};
            for(const Segment& PREV_SEGMENT: prevSegments){
                if(PREV_SEGMENT != prevSegments.back() && intersects(PREV_SEGMENT, currentSegment)){
                    return true;
                }
            }
            
            prevSegments.push_back(currentSegment);
            if(prevSegments.size() == 6){
                prevSegments.pop_front();
            }
        }
        
        return false;
    }
};