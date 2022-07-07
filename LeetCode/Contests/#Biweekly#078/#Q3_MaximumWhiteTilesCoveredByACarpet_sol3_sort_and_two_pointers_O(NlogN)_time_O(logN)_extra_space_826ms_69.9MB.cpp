class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        const int N = tiles.size();
        
        sort(tiles.begin(), tiles.end());
        
        int maxCover = 0;
        int rangeSum = tiles[0][1] - tiles[0][0] + 1;
        int j = 0;
        for(int i = 0; i < N; ++i){
            int maxPosition = tiles[i][0] + carpetLen - 1;
            
            if(i - 1 >= 0){
                rangeSum -= (tiles[i - 1][1] - tiles[i - 1][0] + 1);
            }
            
            while(j + 1 < N && tiles[j + 1][0] <= maxPosition){
                rangeSum += (tiles[j + 1][1] - tiles[j + 1][0] + 1);
                j += 1;
            }
            
            int cover = rangeSum;
            if(maxPosition < tiles[j][1]){
                cover -= (tiles[j][1] - maxPosition);
            }
            
            maxCover = max(maxCover, cover);
        }
        
        return maxCover;
    }
};