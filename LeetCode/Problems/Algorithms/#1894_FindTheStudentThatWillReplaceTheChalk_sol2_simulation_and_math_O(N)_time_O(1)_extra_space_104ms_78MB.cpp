class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        const int N = chalk.size();
        const long long TOTAL_SUM = accumulate(chalk.begin(), chalk.end(), (long long)0);

        k %= TOTAL_SUM;

        for(int i = 0; i < N; ++i){
            k -= chalk[i];
            if(k < 0){
                return i;
            }
        }

        return -1;
    }
};