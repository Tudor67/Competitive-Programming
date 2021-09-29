class Solution {
public:
    int tribonacci(int n) {
        vector<int> t = {0, 1, 1};
        for(int i = 3; i <= n; ++i){
            t[i % 3] = t[0] + t[1] + t[2];
        }
        return t[n % 3];
    }
};