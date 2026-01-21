class Solution {
private:
    // Event: (y, eventType, segmentOnXAxis)
    enum EventType { START = 1, END = -1 };
    using Segment = pair<int, int>;
    using Event = tuple<int, EventType, Segment>;
    
    bool overlaps(const Segment& A, const Segment& B){
        return max(A.first, B.first) <= min(A.second, B.second);
    }

    bool containsOverlappingSquares(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight, int targetSqSide){
        const int N = bottomLeft.size();

        vector<Event> events;
        for(int i = 0; i < N; ++i){
            int x1 = bottomLeft[i][0];
            int y1 = bottomLeft[i][1];
            int x2 = topRight[i][0];
            int y2 = topRight[i][1];
            int xSide = x2 - x1;
            int ySide = y2 - y1;

            if(xSide < targetSqSide || ySide < targetSqSide){
                continue;
            }

            events.push_back({y1, EventType::START, {x1, x2 - targetSqSide}});
            events.push_back({y2 - targetSqSide + 1, EventType::END, {x1, x2 - targetSqSide}});
        }

        sort(events.begin(), events.end());

        multiset<Segment> ms;
        for(Event& event: events){
            EventType eventType = get<1>(event);
            Segment seg = get<2>(event);
            if(eventType == EventType::END){
                ms.erase(ms.find(seg));
            }else{
                auto it = ms.lower_bound(seg);
                if(it != ms.end() && overlaps(seg, *it)){
                    return true;
                }
                if(it != ms.begin() && overlaps(seg, *prev(it))){
                    return true;
                }
                ms.insert(seg);
            }
        }

        return false;
    }

public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        const int N = bottomLeft.size();

        int maxSide = 0;
        for(int i = 0; i < N; ++i){
            maxSide = max(maxSide, max(topRight[i][0] - bottomLeft[i][0],
                                       topRight[i][1] - bottomLeft[i][1]));
        }

        int l = 0;
        int r = maxSide;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(containsOverlappingSquares(bottomLeft, topRight, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        return r * (long long)r;
    }
};