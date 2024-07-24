class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 1; i <= n; ++i){
            q.push(i);
        }

        for(int step = 1; step <= n - 1; ++step){
            for(int i = 1; i <= k - 1; ++i){
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }

        return q.front();
    }
};