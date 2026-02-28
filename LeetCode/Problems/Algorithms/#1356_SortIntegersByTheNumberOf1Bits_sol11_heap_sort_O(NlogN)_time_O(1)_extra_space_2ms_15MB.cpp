class HeapUtils{
public:
    static void heapDown(vector<int>& h, int heapSize, function<bool(int, int)>& comp, int i){
        while(2 * i + 1 < heapSize){
            int j = 2 * i + 1;
            if(2 * i + 2 < heapSize && comp(h[2 * i + 1], h[2 * i + 2])){
                j = 2 * i + 2;
            }
            if(comp(h[i], h[j])){
                swap(h[i], h[j]);
                i = j;
            }else{
                return;
            }
        }
    }

    static void makeHeap(vector<int>& h, int heapSize, function<bool(int, int)>& comp){
        for(int i = heapSize - 1; i >= 0; --i){
            heapDown(h, heapSize, comp, i);
        }
    }

    static void popHeap(vector<int>& h, int& heapSize, function<bool(int, int)>& comp){
        swap(h[0], h[heapSize - 1]);
        heapSize -= 1;
        heapDown(h, heapSize, comp, 0);
    }
};

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> h = arr;
        int heapSize = h.size();

        function<bool(int, int)> comp = [](int lhs, int rhs) {
            return pair<int, int>{popcount((unsigned int)lhs), lhs} <
                   pair<int, int>{popcount((unsigned int)rhs), rhs};
        };
        HeapUtils::makeHeap(h, heapSize, comp);

        while(heapSize > 1){
            HeapUtils::popHeap(h, heapSize, comp);
        }

        return h;
    }
};