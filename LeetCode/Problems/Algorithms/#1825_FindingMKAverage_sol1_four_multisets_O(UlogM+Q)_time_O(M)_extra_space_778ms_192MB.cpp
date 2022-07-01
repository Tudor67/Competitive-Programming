class StreamStats{
private:
    const int M;
    const int K;
    queue<int> q;           // q contains the last M elements of the stream
    multiset<int> values1;  // smallest K elements from q
    multiset<int> values2;  // remaining elements from q
    long long totalMSum;    // total sum of elements from q
    long long smallestKSum; // sum of the smallest K elements from q
    
public:
    StreamStats(const int& M, const int& K): M(M), K(K){
        totalMSum = 0;
        smallestKSum = 0;
    }
    
    long long getTotalMSum(){
        return totalMSum;
    }
    
    long long getSmallestKSum(){
        return smallestKSum;
    }
    
    bool containsEnoughData(){
        return ((int)q.size() == M);
    }
    
    void addElement(int num){
        q.push(num);
        totalMSum += num;
        
        if((int)q.size() == M + 1){
            int oldNum = q.front();
            q.pop();
            
            totalMSum -= oldNum;
            if(values2.find(oldNum) != values2.end()){
                values2.erase(values2.find(oldNum));
            }else{
                smallestKSum -= oldNum;
                values1.erase(values1.find(oldNum));
            }
        }
        
        values2.insert(num);
        smallestKSum += *values2.begin();
        values1.insert(*values2.begin());
        values2.erase(values2.begin());
        if((int)values1.size() == K + 1){
            values2.insert(*prev(values1.end()));
            smallestKSum -= *prev(values1.end());
            values1.erase(prev(values1.end()));
        }
    }
};

class MKAverage {
private:
    int m;
    int k;
    StreamStats streamStats1;
    StreamStats streamStats2;
    
public:
    MKAverage(int m, int k): streamStats1(m, k), streamStats2(m, m - k) {
        this->m = m;
        this->k = k;
    }
    
    void addElement(int num) {
        streamStats1.addElement(num);
        streamStats2.addElement(num);
    }
    
    int calculateMKAverage() {
        if(!streamStats1.containsEnoughData()){
            return -1;
        }
        long long totalSum = streamStats1.getTotalMSum();
        long long smallestKSum = streamStats1.getSmallestKSum();
        long long largestKSum = totalSum - streamStats2.getSmallestKSum();
        return (totalSum - smallestKSum - largestKSum) / (m - 2 * k);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */