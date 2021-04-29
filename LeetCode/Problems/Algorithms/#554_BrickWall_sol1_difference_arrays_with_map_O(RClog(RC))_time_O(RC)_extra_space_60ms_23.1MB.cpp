class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map<int, int> count;
        for(int row = 0; row < (int)wall.size(); ++row){
            int widthPrefSum = 0;
            for(int col = 0; col < (int)wall[row].size(); ++col){
                int width = wall[row][col];
                count[widthPrefSum] += 1;
                count[widthPrefSum + width - 1] -= 1;
                widthPrefSum += width;
            }
        }
        count.erase(prev(count.end()));
        
        int answer = wall.size();
        int bricks = 0;
        for(const pair<int, int>& P: count){
            bricks += P.second;
            answer = min(bricks, answer);
        }
        
        return answer;
    }
};