class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        const vector<pair<int, int>> DIRECTIONS = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        const int COLOR = image[sr][sc];
        vector<vector<int>> newImage = image;
        
        if(COLOR != newColor){
            queue<pair<int, int>> q;
            q.push({sr, sc});        

            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                newImage[x][y] = newColor;

                for(const pair<int, int>& direction: DIRECTIONS){
                    int newX = x + direction.first;
                    int newY = y + direction.second;
                    if(newX >= 0 && newX < newImage.size() &&
                       newY >= 0 && newY < newImage[0].size() &&
                       newImage[newX][newY] == COLOR){
                        q.push({newX, newY});
                    }
                }
            }
        }
        
        return newImage;
    }
};