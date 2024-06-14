class Solution {
private:
    void merge(vector<int>& v, const int L, const int MID, const int R){
        if(L >= R){
            return;
        }

        int l = L;
        int r = MID + 1;
        vector<int> tempVector;
        while(l <= MID && r <= R){
            if(v[l] <= v[r]){
                tempVector.push_back(v[l]);
                l += 1;
            }else{
                tempVector.push_back(v[r]);
                r += 1;
            }
        }
        
        copy(v.begin() + l, v.begin() + MID + 1, back_inserter(tempVector));
        copy(v.begin() + r, v.begin() + R + 1, back_inserter(tempVector));

        copy(tempVector.begin(), tempVector.end(), v.begin() + L);
    }

    void mergeSort(vector<int>& v, const int L, const int R){
        if(L >= R){
            return;
        }
        const int MID = (L + R) / 2;
        mergeSort(v, L, MID);
        mergeSort(v, MID + 1, R);
        merge(v, L, MID, R);
    }

public:
    int heightChecker(vector<int>& heights) {
        const int N = heights.size();

        vector<int> sortedHeights = heights;
        mergeSort(sortedHeights, 0, N - 1);

        int badIndices = 0;
        for(int i = 0; i < N; ++i){
            badIndices += (int)(sortedHeights[i] != heights[i]);
        }

        return badIndices;
    }
};