class MaxHeap{
private:
    vector<int> v;
    
    int getLeftChild(int node){
        return 2 * node + 1;
    }
    
    int getRightChild(int node){
        return 2 * node + 2;
    }
    
    void heapDown(int node){
        int size = v.size();
        while(getLeftChild(node) < size){
            int leftChild = getLeftChild(node);
            int rightChild = getRightChild(node);
            if(rightChild < size && v[leftChild] < v[rightChild] && v[node] < v[rightChild]){
                swap(v[node], v[rightChild]);
                node = rightChild;
            }else if(v[node] < v[leftChild]){
                swap(v[node], v[leftChild]);
                node = leftChild;
            }else{
                break;
            }
        }
    }
    
public:
    MaxHeap(const vector<int>& NUMS): v(NUMS){
        for(int i = (int)v.size() / 2; i >= 0; --i){
            heapDown(i);
        }
    }
    
    int top(){
        return v[0];
    }
    
    void pop(){
        v[0] = v.back();
        v.pop_back();
        heapDown(0);
    }
};

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        const int N = nums.size();
        
        MaxHeap maxHeap(nums);
        vector<int> sortedArray(N);
        for(int i = N - 1; i >= 0; --i){
            sortedArray[i] = maxHeap.top();
            maxHeap.pop();
        }
        
        return sortedArray;
    }
};