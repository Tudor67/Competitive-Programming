class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        const int N = seats.size();
        const int INF = 1e9;
        
        vector<int> lDist(N, INF);
        for(int i = 0; i < N; ++i){
            if(seats[i] == 1){
                lDist[i] = 0;
            }else if(i > 0){
                lDist[i] = lDist[i - 1] + 1;
            }
        }
        
        vector<int> rDist(N, INF);
        for(int i = N - 1; i >= 0; --i){
            if(seats[i] == 1){
                rDist[i] = 0;
            }else if(i + 1 < N){
                rDist[i] = 1 + rDist[i + 1];
            }
        }
        
        int maxDist = 0;
        for(int i = 0; i < N; ++i){
            if(seats[i] == 0){
                int minDist = min(lDist[i], rDist[i]);
                maxDist = max(maxDist, minDist);
            }
        }
        
        return maxDist;
    }
};