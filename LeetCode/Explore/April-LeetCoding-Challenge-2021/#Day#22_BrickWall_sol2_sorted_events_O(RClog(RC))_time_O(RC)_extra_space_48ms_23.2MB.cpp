class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        const int START_EVENT = 1;
        const int END_EVENT = 0;
        
        vector<pair<int, int>> events;
        for(int row = 0; row < (int)wall.size(); ++row){
            int widthPrefSum = 0;
            for(int col = 0; col < (int)wall[row].size(); ++col){
                int width = wall[row][col];
                events.emplace_back(widthPrefSum, START_EVENT);
                events.emplace_back(widthPrefSum + width, END_EVENT);
                widthPrefSum += width;
            }
        }
        
        sort(events.begin(), events.end());
        
        while(events.back().second == END_EVENT){
            events.pop_back();
        }
        
        int answer = wall.size();
        int bricks = 0;
        for(const pair<int, int>& EVENT: events){
            if(EVENT.second == END_EVENT){
                bricks -= 1;
                answer = min(bricks, answer);
            }else{
                bricks += 1;
            }
        }
        
        return answer;
    }
};