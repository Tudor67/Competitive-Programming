class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        const int N = seats.size();
        const int INF = 1e9;
        
        for(int i = 0; i < N; ++i){
            if(seats[i] == 1){
                seats[i] = 0;
            }else if(i > 0){
                seats[i] = seats[i - 1] + 1;
            }else{
                seats[i] = INF;
            }
        }
        
        for(int i = N - 2; i >= 0; --i){
            seats[i] = min(seats[i], 1 + seats[i + 1]);
        }
        
        int maxDist = *max_element(seats.begin(), seats.end());
        
        for(int i = 0; i < N; ++i){
            if(seats[i] == 0){
                seats[i] = 1;
            }else{
                seats[i] = 0;
            }
        }
        
        return maxDist;
    }
};