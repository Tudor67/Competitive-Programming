class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        const int N = points.size();
        const int A = 26;
        const int INF = 2e9;

        vector<int> min1(A, INF);
        vector<int> min2(A, INF);
        int border = INF;

        for(int i = 0; i < N; ++i){
            int dist = max(abs(points[i][0]), abs(points[i][1]));
            char tagID = s[i] - 'a';
            if(dist < min1[tagID]){
                min2[tagID] = min1[tagID];
                min1[tagID] = dist;
            }else if(dist < min2[tagID]){
                min2[tagID] = dist;
            }
            border = min(border, min2[tagID] - 1);
        }

        int maxValidTags = 0;
        for(int i = 0; i < N; ++i){
            int dist = max(abs(points[i][0]), abs(points[i][1]));
            if(dist <= border){
                maxValidTags += 1;
            }
        }
        
        return maxValidTags;
    }
};