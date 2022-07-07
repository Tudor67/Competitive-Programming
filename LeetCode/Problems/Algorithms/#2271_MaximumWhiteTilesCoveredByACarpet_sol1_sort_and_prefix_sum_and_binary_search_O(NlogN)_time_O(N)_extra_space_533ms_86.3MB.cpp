class Solution {
private:
    int getRangeSum(vector<int>& prefSum, const int& L, const int& R){
        if(L > R){
            return 0;
        }
        if(L == 0){
            return prefSum[R];
        }
        return prefSum[R] - prefSum[L - 1];
    }
    
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        const int N = tiles.size();
        
        vector<vector<int>> sortedTiles = tiles;
        sort(sortedTiles.begin(), sortedTiles.end());
        
        vector<int> prefSum(N);
        prefSum[0] = sortedTiles[0][1] - sortedTiles[0][0] + 1;
        for(int i = 1; i < N; ++i){
            prefSum[i] = prefSum[i - 1] + (sortedTiles[i][1] - sortedTiles[i][0] + 1);
        }
        
        int maxCover = 0;
        for(int i = 0; i < N; ++i){
            int maxPosition = sortedTiles[i][0] + carpetLen - 1;
            
            int l = i;
            int r = N - 1;
            while(l != r){
                int mid = (l + r + 1) / 2;
                if(sortedTiles[mid][0] <= maxPosition){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            
            int j = r;
            int cover = getRangeSum(prefSum, i, j);
            if(maxPosition < sortedTiles[j][1]){
                cover -= (sortedTiles[j][1] - maxPosition);
            }
            
            maxCover = max(maxCover, cover);
        }
        
        return maxCover;
    }
};