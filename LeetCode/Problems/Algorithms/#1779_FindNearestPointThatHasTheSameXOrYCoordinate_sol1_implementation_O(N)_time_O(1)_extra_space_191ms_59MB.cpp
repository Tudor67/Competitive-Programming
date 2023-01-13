class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        const int N = points.size();

        int index = -1;
        int minDist = -1;
        for(int i = N - 1; i >= 0; --i){
            if(points[i][0] == x || points[i][1] == y){
                int dist = abs(points[i][0] - x) + abs(points[i][1] - y);
                if(dist <= minDist || minDist == -1){
                    index = i;
                    minDist = dist;
                }
            }
        }

        return index;
    }
};