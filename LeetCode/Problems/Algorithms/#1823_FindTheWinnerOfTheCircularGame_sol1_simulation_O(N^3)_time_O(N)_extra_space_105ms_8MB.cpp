class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<bool> inGame(n, true);
        
        int i = -1;
        for(int step = 1; step <= n - 1; ++step){
            int visCount = 0;
            while(visCount < k){
                i += 1;
                i %= n;
                visCount += (int)inGame[i];
            }
            inGame[i] = false;
        }

        return find(inGame.begin(), inGame.end(), true) - inGame.begin() + 1;
    }
};