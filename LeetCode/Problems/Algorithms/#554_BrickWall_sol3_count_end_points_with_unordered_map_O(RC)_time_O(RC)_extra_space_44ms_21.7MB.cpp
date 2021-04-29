class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> count;
        for(int row = 0; row < (int)wall.size(); ++row){
            int endPoint = 0;
            for(int col = 0; col < (int)wall[row].size() - 1; ++col){
                endPoint += wall[row][col];
                count[endPoint] += 1;
            }
        }
        
        int answer = wall.size();
        for(const pair<int, int>& P: count){
            int endPointsCount = P.second;
            answer = min((int)wall.size() - endPointsCount, answer);
        }
        
        return answer;
    }
};