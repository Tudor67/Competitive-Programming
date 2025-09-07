class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        const int N = points.size();

        int goodPairs = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(i != j && points[i][0] <= points[j][0] && points[i][1] >= points[j][1]){
                    bool containsExtraPoints = false;

                    for(int k = 0; k < N && !containsExtraPoints; ++k){
                        if(i != k && k != j &&
                           points[i][0] <= points[k][0] && points[k][0] <= points[j][0] &&
                           points[i][1] >= points[k][1] && points[k][1] >= points[j][1]){
                            containsExtraPoints = true;
                        }
                    }
                    
                    if(!containsExtraPoints){
                        goodPairs += 1;
                    }
                }
            }
        }

        return goodPairs;
    }
};