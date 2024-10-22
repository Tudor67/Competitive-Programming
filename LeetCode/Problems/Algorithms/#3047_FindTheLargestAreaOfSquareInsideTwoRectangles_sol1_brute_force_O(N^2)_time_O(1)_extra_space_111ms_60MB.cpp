class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bl, vector<vector<int>>& tr) {
        const int N = bl.size();
        
        long long sqMaxArea = 0;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                int blX = max(bl[i][0], bl[j][0]);
                int blY = max(bl[i][1], bl[j][1]);
                int trX = min(tr[i][0], tr[j][0]);
                int trY = min(tr[i][1], tr[j][1]);
                long long dx = trX - blX;
                long long dy = trY - blY;
                if(dx > 0 && dy > 0){
                    long long side = min(dx, dy);
                    long long sqArea = side * side;
                    sqMaxArea = max(sqMaxArea, sqArea);
                }
            }
        }
        
        return sqMaxArea;
    }
};