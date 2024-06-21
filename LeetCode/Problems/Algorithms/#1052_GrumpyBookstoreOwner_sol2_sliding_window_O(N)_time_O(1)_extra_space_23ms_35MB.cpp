class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        const int N = customers.size();

        int notGrumpyTotalSum = 0;
        for(int i = 0; i < N; ++i){
            if(!grumpy[i]){
                notGrumpyTotalSum += customers[i];
            }
        }

        int maxWindowGrumpySum = 0;
        int windowGrumpySum = 0;
        for(int i = 0; i < N; ++i){
            windowGrumpySum += customers[i] * grumpy[i];
            if(i >= minutes){
                windowGrumpySum -= customers[i - minutes] * grumpy[i - minutes];
            }
            maxWindowGrumpySum = max(maxWindowGrumpySum, windowGrumpySum);
        }

        return notGrumpyTotalSum + maxWindowGrumpySum;
    }
};