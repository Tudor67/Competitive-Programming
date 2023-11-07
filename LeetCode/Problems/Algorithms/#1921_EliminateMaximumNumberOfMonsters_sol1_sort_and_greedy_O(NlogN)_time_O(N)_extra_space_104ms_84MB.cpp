class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        const int N = dist.size();

        vector<int> arrivalTimes(N);
        for(int i = 0; i < N; ++i){
            arrivalTimes[i] = (dist[i] + speed[i] - 1) / speed[i];
        }

        sort(arrivalTimes.begin(), arrivalTimes.end());

        for(int i = 0; i < N; ++i){
            if(arrivalTimes[i] <= i){
                return i;
            }
        }

        return N;
    }
};