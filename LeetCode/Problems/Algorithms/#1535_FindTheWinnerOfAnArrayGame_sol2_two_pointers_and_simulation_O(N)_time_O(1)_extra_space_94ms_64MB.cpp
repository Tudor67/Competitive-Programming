class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        const int N = arr.size();
        const int MAX_NUM = *max_element(arr.begin(), arr.end());

        int i = 0;
        while(i < N){
            int j = i + 1;
            while(j < N && arr[i] > arr[j]){
                j += 1;
            }

            int winCount = 0;
            if(i == 0){
                winCount = j - i - 1;
            }else{
                winCount = j - i;
            }

            if(winCount >= k){
                return arr[i];
            }

            i = j;
        }

        return MAX_NUM;
    }
};