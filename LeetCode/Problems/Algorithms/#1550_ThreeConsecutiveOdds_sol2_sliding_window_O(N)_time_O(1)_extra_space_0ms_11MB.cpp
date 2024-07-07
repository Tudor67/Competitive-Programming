class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        const int N = arr.size();
        const int K = 3;

        int odds = 0;
        for(int i = 0; i < N; ++i){
            odds += (int)(arr[i] % 2);
            if(i >= K){
                odds -= (int)(arr[i - K] % 2);
            }
            if(odds == K){
                return true;
            }
        }

        return false;
    }
};