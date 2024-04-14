class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        const int N = tickets.size();

        int totalTime = 0;
        for(int i = 0; i < N; ++i){
            if(i <= k){
                totalTime += min(tickets[k], tickets[i]);
            }else{
                totalTime += min(tickets[k] - 1, tickets[i]);
            }
        }

        return totalTime;
    }
};