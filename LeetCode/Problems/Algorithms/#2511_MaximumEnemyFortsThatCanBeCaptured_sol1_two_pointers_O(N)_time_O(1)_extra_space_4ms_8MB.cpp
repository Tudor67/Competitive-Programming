class Solution {
public:
    int captureForts(vector<int>& forts) {
        const int N = forts.size();

        int res = 0;
        for(int i = 0; i + 1 < N; ++i){
            if(forts[i] != 0 && forts[i + 1] == 0){
                int j = i + 1;
                while(j < N && forts[j] == 0){
                    j += 1;
                }
                if(j < N && forts[i] != forts[j]){
                    res = max(res, j - i - 1);
                }
            }
        }

        return res;
    }
};