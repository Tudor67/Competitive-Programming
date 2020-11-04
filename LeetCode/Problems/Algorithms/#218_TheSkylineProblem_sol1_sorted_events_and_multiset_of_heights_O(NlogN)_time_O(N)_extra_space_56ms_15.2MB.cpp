class Event{
public:
    static const int START_POINT = 0;
    static const int END_POINT = 1;
    int x;
    int height;
    int eventType;
    
    Event(int x, int height, int eventType){
        this->x = x;
        this->height = height;
        this->eventType = eventType;
    }
};

class Solution {
private:
    static bool eventComp(const Event& LHS, const Event& RHS){
        return (LHS.x < RHS.x) ||
               (LHS.x == RHS.x && LHS.eventType < RHS.eventType) ||
               (LHS.x == RHS.x && LHS.eventType == RHS.eventType && LHS.height > RHS.height);
    }
    
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Event> events;
        for(int i = 0; i < buildings.size(); ++i){
            int startX = buildings[i][0];
            int endX = buildings[i][1];
            int height = buildings[i][2];
            events.push_back(Event(startX, height, Event::START_POINT));
            events.push_back(Event(endX, height, Event::END_POINT));
        }
        
        sort(events.begin(), events.end(), eventComp);
        
        vector<vector<int>> keyPoints;
        int keyPointsLastEvent = Event::START_POINT;
        multiset<int> activeHeights;
        int prevMaxActiveHeight = 0;
        int maxActiveHeight = 0;
        for(Event& event: events){
            if(event.eventType == Event::START_POINT){
                activeHeights.insert(event.height);
                maxActiveHeight = *activeHeights.rbegin();
                if(prevMaxActiveHeight < maxActiveHeight){
                    keyPoints.push_back({event.x, maxActiveHeight});
                    keyPointsLastEvent = Event::START_POINT;
                }
            }else if(event.eventType == Event::END_POINT){
                activeHeights.erase(activeHeights.find(event.height));
                maxActiveHeight = (activeHeights.empty() ? 0 : *activeHeights.rbegin());
                if(keyPointsLastEvent == Event::END_POINT && keyPoints.back()[0] == event.x){
                    keyPoints.back()[1] = maxActiveHeight;
                }else if(prevMaxActiveHeight > maxActiveHeight){
                    keyPoints.push_back({event.x, maxActiveHeight});
                    keyPointsLastEvent = Event::END_POINT;
                }
            }
            prevMaxActiveHeight = maxActiveHeight;
        }
        
        return keyPoints;
    }
};

/*
Testcases:
[[0,2,3],[2,5,3]]
[[2,9,3],[3,7,9],[4,6,7],[13,25,3],[14,22,4],[16,17,7],[18,19,6],[18,21,8],[19,20,6],[20,21,7],[21,22,11],[21,27,6],[23,24,5]]
[[2,9,3],[3,7,9],[4,6,7],[13,25,3],[14,22,4],[16,17,7],[18,19,6],[18,21,8],[19,20,6],[20,21,7],[21,22,11],[23,24,5]]
[[2,9,3],[3,7,9],[4,6,7],[13,25,3],[14,22,4],[16,17,7],[18,19,6],[18,21,8],[19,20,6],[20,21,7],[23,24,5]]
[[1,7,3],[2,7,3],[3,7,3]]
[[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
[]
*/