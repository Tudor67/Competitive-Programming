class Solution {
private:
    int getLeftChild(int node){
        return 2 * node + 1;
    }
    
    int getRightChild(int node){
        return 2 * node + 2;
    }
    
    void heapDown(vector<int>& h, int size, int node){
        while(getLeftChild(node) < size){
            int leftChild = getLeftChild(node);
            int rightChild = getRightChild(node);
            if(rightChild < size && h[leftChild] < h[rightChild] && h[node] < h[rightChild]){
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
    
    void makeHeap(vector<int>& h, int size){
        for(int i = size / 2; i >= 0; --i){
            heapDown(h, size, i);
        }
    }
    
    void popHeap(vector<int>& h, int size){
        swap(h[0], h[size - 1]);
        heapDown(h, size - 1, 0);
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> res = nums;
        
        makeHeap(res, N);
        for(int i = N; i >= 1; --i){
            popHeap(res, i);
        }
        
        return res;
    }
};