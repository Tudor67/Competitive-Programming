class Solution {
public:
    int numTeams(vector<int>& rating) {
        const int N = rating.size();

        int validTeams = 0;
        for(int j = 1; j < N - 1; ++j){
            int leftSize = j;
            int leftSmallerCount = 0;
            for(int i = 0; i < j; ++i){
                if(rating[i] < rating[j]){
                    leftSmallerCount += 1;
                }
            }

            int rightSize = N - 1 - j;
            int rightGreaterCount = 0;
            for(int k = j + 1; k < N; ++k){
                if(rating[j] < rating[k]){
                    rightGreaterCount += 1;
                }
            }

            validTeams += leftSmallerCount * rightGreaterCount;
            validTeams += (leftSize - leftSmallerCount) * (rightSize - rightGreaterCount);
        }

        return validTeams;
    }
};