class Solution {
public:
    int timeRequiredToBuy(vector<int>& ticketsIn, int k) {
        vector<int> tickets = ticketsIn;

        const int N = tickets.size();

        int currentTime = 0;
        while(tickets[k] >= 1){
            for(int i = 0; i < N; ++i){
                if(tickets[i] >= 1 && tickets[k] >= 1){
                    tickets[i] -= 1;
                    currentTime += 1;
                }
            }
        }

        return currentTime;
    }
};