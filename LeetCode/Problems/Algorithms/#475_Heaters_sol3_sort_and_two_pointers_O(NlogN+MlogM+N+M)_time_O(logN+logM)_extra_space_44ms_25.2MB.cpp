class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        const int N = houses.size();
        const int M = heaters.size();
        
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        int answer = 0;
        for(int i = 0, j = 0; i < N; ++i){
            int minR = INT_MAX;
            while(j < M && houses[i] > heaters[j]){
                j += 1;
            }
            if(j != M){
                minR = min(abs(heaters[j] - houses[i]), minR);
            }
            if(j != 0){
                minR = min(abs(heaters[j - 1] - houses[i]), minR);
            }
            answer = max(minR, answer);
        }
        
        return answer;
    }
};