class SegmentTree{
private:
    const int N;
    vector<long long> sum;
    vector<int> count;
    
    void add(int node, int l, int r, const int& NUM, const int& FREQ){
        if(l == r){
            sum[node] += FREQ * NUM;
            count[node] += FREQ;
        }else{
            int mid = (l + r) / 2;
            if(NUM <= mid){
                add(2 * node + 1, l, mid, NUM, FREQ);
            }else{
                add(2 * node + 2, mid + 1, r, NUM, FREQ);
            }
            sum[node] = sum[2 * node + 1] + sum[2 * node + 2];
            count[node] = count[2 * node + 1] + count[2 * node + 2];
        }
    }
    
    long long getSumOfFirstKNums(int node, int l, int r, int k){
        if(k == 0){
            return 0;
        }else if(k == count[node]){
            return sum[node];
        }else if(l == r){
            return k * (sum[node] / count[node]);
        }else{
            int mid = (l + r) / 2;
            if(k < count[2 * node + 1]){
                return getSumOfFirstKNums(2 * node + 1, l, mid, k);
            }else{
                return sum[2 * node + 1] + getSumOfFirstKNums(2 * node + 2, mid + 1, r, k - count[2 * node + 1]);
            }
        }
    }
    
public:
    SegmentTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        sum.resize(2 * minLeaves);
        count.resize(2 * minLeaves);
    }
    
    void add(const int& NUM, const int& FREQ){
        add(0, 0, N - 1, NUM, FREQ);
    }
    
    long long getTotalSum(){
        return sum[0];
    }
    
    long long getSumOfFirstKNums(int k){
        return getSumOfFirstKNums(0, 0, N - 1, k);
    }
};

class MKAverage {
private:
    const int MAX_NUM = 1e5;
    const int M;
    const int K;
    queue<int> q;
    SegmentTree segmentTree;
    
public:
    MKAverage(int m, int k): M(m), K(k), segmentTree(MAX_NUM + 1) {
        
    }
    
    void addElement(int num) {
        q.push(num);
        segmentTree.add(num, 1);
        
        if((int)q.size() == M + 1){
            int oldNum = q.front();
            q.pop();
            segmentTree.add(oldNum, -1);
        }
    }
    
    int calculateMKAverage() {
        if((int)q.size() < M){
            return -1;
        }
        long long totalSum = segmentTree.getTotalSum();
        long long smallestKSum = segmentTree.getSumOfFirstKNums(K);
        long long largestKSum = totalSum - segmentTree.getSumOfFirstKNums(M - K);
        return (totalSum - smallestKSum - largestKSum) / (M - 2 * K);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */