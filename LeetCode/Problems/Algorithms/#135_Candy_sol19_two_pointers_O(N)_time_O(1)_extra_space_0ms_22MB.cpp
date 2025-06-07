class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();

        int res = N;

        int i = 0;
        while(i + 1 < N){
            while(i + 1 < N && ratings[i] == ratings[i + 1]){
                i += 1;
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
            int len1 = j - i + 1;
            int len2 = k - j + 1;
            if(len1 > len2){
                swap(len1, len2);
            }

            res += (len1 - 2) * (len1 - 1) / 2;
            res += (len2 - 1) * len2 / 2;
            
            i = k;
        }

        return res;
    }
};