class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        const int N = chalk.size();
        const long long SUM = accumulate(chalk.begin(), chalk.end(), 0LL);
        
        k %= SUM;
        for(int i = 0; i < N; ++i){
            k -= chalk[i];
            if(k < 0){
                return i;
            }
        }
        
        return -1;
    }
};