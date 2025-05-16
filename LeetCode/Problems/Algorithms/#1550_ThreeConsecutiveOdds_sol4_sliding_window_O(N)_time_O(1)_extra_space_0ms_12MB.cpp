class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        const int N = arr.size();
        const int K = 3;

        int wOddCount = 0;
        for(int i = 0; i < N; ++i){
            wOddCount += (arr[i] % 2);
            if(i >= K){
                wOddCount -= (arr[i - K] % 2);
            }
            if(wOddCount == K){
                return true;
            }
        }

        return false;
    }
};