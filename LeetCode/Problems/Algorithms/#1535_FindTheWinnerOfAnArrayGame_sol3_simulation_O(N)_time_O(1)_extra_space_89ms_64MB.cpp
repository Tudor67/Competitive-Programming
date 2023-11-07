class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        const int N = arr.size();

        int winner = arr[0];
        int winCount = 0;

        for(int i = 1; i < N; ++i){
            if(winner > arr[i]){
                winCount += 1;
            }else{
                winner = arr[i];
                winCount = 1;
            }

            if(winCount == k){
                break;
            }
        }

        return winner;
    }
};