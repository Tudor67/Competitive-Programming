class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        const int N = reward1.size();

        vector<int> v(N);
        for(int i = 0; i < N; ++i){
            v[i] = reward1[i] - reward2[i];
        }

        nth_element(v.begin(), v.end() - k, v.end());

        int res = accumulate(reward2.begin(), reward2.end(), 0) +
                  accumulate(v.end() - k, v.end(), 0);
                  
        return res;
    }
};