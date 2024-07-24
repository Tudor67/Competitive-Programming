class Solution {
private:
    int findTheWinnerIndex(int n, int k){
        if(n == 1){
            return 0;
        }
        return (findTheWinnerIndex(n - 1, k) + k) % n;
    }

public:
    int findTheWinner(int n, int k) {
        return 1 + findTheWinnerIndex(n, k);
    }
};