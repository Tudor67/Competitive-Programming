class Solution {
private:
    void downHeap(vector<int>& h, int heapSize, int node){
        while(2 * node + 1 < heapSize){
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            if(rightChild < heapSize && h[leftChild] < h[rightChild] && h[node] < h[rightChild]){
                swap(h[node], h[rightChild]);
                node = rightChild;
            }else if(h[node] < h[leftChild]){
                swap(h[node], h[leftChild]);
                node = leftChild;
            }else{
                break;
            }
        }
    }

    void heapSort(vector<int>& h){
        // make heap
        for(int node = ((int)h.size() - 2) / 2; node >= 0; --node){
            downHeap(h, h.size(), node);
        }

        // pop heap
        for(int heapSize = h.size(); heapSize >= 1; --heapSize){
            swap(h[0], h[heapSize - 1]);
            downHeap(h, heapSize - 1, 0);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};