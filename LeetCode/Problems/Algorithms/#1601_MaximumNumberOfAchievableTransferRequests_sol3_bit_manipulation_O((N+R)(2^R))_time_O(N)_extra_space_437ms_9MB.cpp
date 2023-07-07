class Solution {
public:
    int maximumRequests(int N, vector<vector<int>>& requests) {
        const int R = requests.size();
        const int FULL_MASK = (1 << R) - 1;

        int res = 0;
        vector<int> inDegree(N);
        vector<int> outDegree(N);

        for(int mask = 1; mask <= FULL_MASK; ++mask){
            fill(inDegree.begin(), inDegree.end(), 0);
            fill(outDegree.begin(), outDegree.end(), 0);

            for(int bit = 0; bit < R; ++bit){
                if((mask >> bit) & 1){
                    int a = requests[bit][0];
                    int b = requests[bit][1];
                    outDegree[a] += 1;
                    inDegree[b] += 1;
                }
            }

            if(inDegree == outDegree){
                res = max(res, __builtin_popcount(mask));
            }
        }

        return res;
    }
};