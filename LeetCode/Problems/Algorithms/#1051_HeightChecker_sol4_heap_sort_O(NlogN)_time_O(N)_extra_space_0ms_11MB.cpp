class Solution {
private:
    void heapDown(vector<int>& h, int heapSize, int i){
        while(2 * i + 1 < heapSize){
            int childIndex = 2 * i + 1;
            if(2 * i + 2 < heapSize && h[2 * i + 1] < h[2 * i + 2]){
                childIndex = 2 * i + 2;
            }

            if(h[i] < h[childIndex]){
                swap(h[i], h[childIndex]);
                swap(i, childIndex);
            }else{
                break;
            }
        }
    }

    void heapSort(vector<int>& h){
        const int N = h.size();

        for(int i = N - 1; i >= 0; --i){
            heapDown(h, N, i);
        }

        for(int i = N - 1; i >= 0; --i){
            swap(h[0], h[i]);
            heapDown(h, i, 0);
        }
    }

public:
    int heightChecker(vector<int>& heights) {
        const int N = heights.size();

        vector<int> sortedHeights = heights;
        heapSort(sortedHeights);

        int badIndices = 0;
        for(int i = 0; i < N; ++i){
            badIndices += (int)(sortedHeights[i] != heights[i]);
        }

        return badIndices;
    }
};