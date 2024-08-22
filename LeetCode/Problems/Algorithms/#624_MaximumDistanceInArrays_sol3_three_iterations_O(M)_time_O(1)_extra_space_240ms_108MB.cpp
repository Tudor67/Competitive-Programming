class Solution {
private:
    int getIndexOfMaxExceptBadIndex(vector<vector<int>>& arrays, int badIndex){
        int indexOfMax = -1;
        for(int i = 0; i < (int)arrays.size(); ++i){
            if(i != badIndex){
                if(indexOfMax == -1 || arrays[indexOfMax].back() < arrays[i].back()){
                    indexOfMax = i;
                }
            }
        }
        return indexOfMax;
    }

public:
    int maxDistance(vector<vector<int>>& arrays) {
        const int M = arrays.size();

        int indexOfFirstMax = getIndexOfMaxExceptBadIndex(arrays, -1);
        int indexOfSecondMax = getIndexOfMaxExceptBadIndex(arrays, indexOfFirstMax);

        int maxDist = 0;
        for(int i = 0; i < M; ++i){
            if(i != indexOfFirstMax){
                maxDist = max(maxDist, arrays[indexOfFirstMax].back() - arrays[i].front());
            }
            if(i != indexOfSecondMax){
                maxDist = max(maxDist, arrays[indexOfSecondMax].back() - arrays[i].front());
            }
        }

        return maxDist;
    }
};