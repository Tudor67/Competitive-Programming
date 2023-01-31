class Solution {
public:
    int tribonacci(int n) {
        vector<int> t(3);
        t[0] = 0;
        t[1] = 1;
        t[2] = 1;
        for(int i = 3; i <= n; ++i){
            t[i % 3] = t[(i - 1) % 3] + t[(i - 2) % 3] + t[(i - 3) % 3];
        }
        return t[n % 3];
    }
};