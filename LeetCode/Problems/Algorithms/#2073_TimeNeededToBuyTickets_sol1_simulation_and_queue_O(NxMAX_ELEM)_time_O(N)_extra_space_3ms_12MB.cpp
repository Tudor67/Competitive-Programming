class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        const int N = tickets.size();

        queue<pair<int, int>> q;
        for(int i = 0; i < N; ++i){
            q.push({tickets[i], i});
        }

        int currentTime = 0;
        while(!q.empty()){
            int currentTickets = q.front().first;
            int currentIndex = q.front().second;
            q.pop();

            currentTime += 1;

            if(currentTickets - 1 >= 1){
                q.push({currentTickets - 1, currentIndex});
            }else if(currentIndex == k){
                return currentTime;
            }
        }

        return -1;
    }
};