class Solution {
private:
    void heapDown(vector<int>& h, int heapSize, int i){
        while(2 * i + 1 < heapSize){
            int leftChildIdx = 2 * i + 1;
            int rightChildIdx = 2 * i + 2;
            int maxChildIdx = leftChildIdx;
            if(rightChildIdx < heapSize && h[leftChildIdx] < h[rightChildIdx]){
                maxChildIdx = rightChildIdx;
            }
            if(h[i] < h[maxChildIdx]){
                swap(h[i], h[maxChildIdx]);
                swap(i, maxChildIdx);
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

        int heapSize = N;
        for(int i = 0; i < N - 1; ++i){
            swap(h[0], h[heapSize - 1]);
            heapDown(h, heapSize - 1, 0);
            heapSize -= 1;
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};