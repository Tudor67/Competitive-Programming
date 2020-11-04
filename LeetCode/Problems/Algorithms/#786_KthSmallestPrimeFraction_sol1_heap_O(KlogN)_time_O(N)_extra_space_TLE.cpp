class Solution {
private:
    using FractionT3 = tuple<double, int, int>;
    
    struct MinHeapFractionT3Comparator{
        bool operator()(const FractionT3& LHS, const FractionT3& RHS){
            return (get<0>(LHS) > get<0>(RHS));
        }
    };
    
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        const int N = A.size();
        
        priority_queue<FractionT3, vector<FractionT3>, MinHeapFractionT3Comparator> minHeap;        
        for(int i = 1; i <= N - 1; ++i){
            minHeap.push({(double)A[0] / (double)A[i], 0, i});
        }
        
        for(int k = 1; k <= K - 1; ++k){
            int pPos = get<1>(minHeap.top());
            int qPos = get<2>(minHeap.top());
            minHeap.pop();
            
            if(pPos + 1 < qPos){
                minHeap.push({(double)A[pPos + 1] / (double)A[qPos], pPos + 1, qPos});
            }
        }
        
        int p = A[get<1>(minHeap.top())];
        int q = A[get<2>(minHeap.top())];
        return {p, q};
    }
};