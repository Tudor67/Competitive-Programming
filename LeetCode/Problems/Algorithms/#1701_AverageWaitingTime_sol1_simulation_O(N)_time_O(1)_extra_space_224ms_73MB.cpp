class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        const int N = customers.size();

        int chefActiveTime = 0;
        double waitingTimeSum = 0;
        for(int i = 0; i < N; ++i){
            int arrive = customers[i][0];
            int prepareTime = customers[i][1];
            chefActiveTime = max(chefActiveTime, arrive) + prepareTime;
            waitingTimeSum += (chefActiveTime - arrive);
        }

        return waitingTimeSum / N;
    }
};