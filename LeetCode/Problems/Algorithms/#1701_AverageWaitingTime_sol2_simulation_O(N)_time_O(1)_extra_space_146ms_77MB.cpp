class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        const int N = customers.size();

        int currentTime = 0;
        double totalWaitingTime = 0;
        for(const vector<int>& CUSTOMER: customers){
            int arrivalTime = CUSTOMER[0];
            int duration = CUSTOMER[1];
            currentTime = max(currentTime, arrivalTime);
            totalWaitingTime += (currentTime + duration - arrivalTime);
            currentTime += duration;
        }

        return (totalWaitingTime / N);
    }
};