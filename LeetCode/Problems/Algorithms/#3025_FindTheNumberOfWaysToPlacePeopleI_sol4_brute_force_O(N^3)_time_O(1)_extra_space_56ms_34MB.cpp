class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
        const int N = p.size();

        int validPairs = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(p[i][0] <= p[j][0] && p[i][1] >= p[j][1]){
                    int pointsCount = 0;
                    for(int k = 0; k < N; ++k){
                        if(p[i][0] <= p[k][0] && p[k][0] <= p[j][0] &&
                           p[i][1] >= p[k][1] && p[k][1] >= p[j][1]){
                            pointsCount += 1;
                        }
                    }

                    if(pointsCount == 2){
                        validPairs += 1;
                    }
                }
            }
        }

        return validPairs;
    }
};