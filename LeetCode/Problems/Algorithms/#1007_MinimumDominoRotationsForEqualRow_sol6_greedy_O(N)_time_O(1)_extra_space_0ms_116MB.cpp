class Solution {
private:
    const int INF = 1e9;

    int computeMinOps(vector<int>& tops, vector<int>& bottoms, int target){
        const int N = tops.size();

        int minOps = 0;
        for(int i = 1; i < N; ++i){
            if(tops[i] != target){
                if(bottoms[i] == target){
                    minOps += 1;
                }else{
                    return INF;
                }
            }
        }

        return minOps;
    }

public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int minOps = min({computeMinOps(tops, bottoms, tops[0]),
                          1 + computeMinOps(tops, bottoms, bottoms[0]),
                          computeMinOps(bottoms, tops, bottoms[0]),
                          1 + computeMinOps(bottoms, tops, tops[0])});
        if(minOps == INF){
            return -1;
        }
        return minOps;
    }
};