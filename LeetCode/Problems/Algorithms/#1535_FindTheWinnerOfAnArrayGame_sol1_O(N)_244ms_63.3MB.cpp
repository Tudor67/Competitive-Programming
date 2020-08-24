class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winner = arr[0];
        int win_cnt = 0;
        
        for(int i = 1; i < arr.size(); ++i){
            if(winner > arr[i]){
                win_cnt += 1;
            }else{
                winner = arr[i];
                win_cnt = 1;
            }
            
            if(win_cnt == k){
                break;
            }
        }
        
        return winner;
    }
};