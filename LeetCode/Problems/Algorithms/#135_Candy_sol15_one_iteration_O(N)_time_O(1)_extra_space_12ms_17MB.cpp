class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();

        int totalCandies = 0;
        int i = 0;
        while(i < N){
            while(i + 1 < N && ratings[i] == ratings[i + 1]){
                i += 1;
                totalCandies += 1;
            }

            int j = i;
            while(j + 1 < N && ratings[j] < ratings[j + 1]){
                j += 1;
            }

            int k = j;
            while(k + 1 < N && ratings[k] > ratings[k + 1]){
                k += 1;
            }

            // ratings[i] < ratings[i + 1] < ... < ratings[j]
            // ratings[j] > ratings[j + 1] > ... > ratings[k]
            int totalLen = k - i + 1;
            int maxLen = max(j - i + 1, k - j + 1);
            int remLen = totalLen - maxLen;
            totalCandies += maxLen * (maxLen + 1) / 2;
            totalCandies += remLen * (remLen + 1) / 2;
            if(totalLen >= 2){
                totalCandies -= 1;
            }

            i = max(i + 1, k);
        }

        return totalCandies;
    }
};