class MKAverage {
private:
    int m;
    int k;
    queue<int> q;        // q contains the last m elements of the stream
    multiset<int> small; // smallest k elements from q
    multiset<int> mid;   // mid elements from q
    multiset<int> large; // largest k elements from q
    long long midSum;    // sum of mid elements from q
    
public:
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
        midSum = 0;
    }
    
    void addElement(int num) {
        q.push(num);
        
        if((int)q.size() == m + 1){
            int oldNum = q.front();
            q.pop();
            
            if(small.find(oldNum) != small.end()){
                small.erase(small.find(oldNum));
                if(!mid.empty()){
                    small.insert(*mid.begin());
                    midSum -= *mid.begin();
                    mid.erase(mid.begin());
                }else if(!large.empty()){
                    small.insert(*large.begin());
                    large.erase(large.begin());
                }
            }else if(mid.find(oldNum) != mid.end()){
                midSum -= oldNum;
                mid.erase(mid.find(oldNum));
            }else if(large.find(oldNum) != large.end()){
                large.erase(large.find(oldNum));
                if(!mid.empty()){
                    large.insert(*prev(mid.end()));
                    midSum -= *prev(mid.end());
                    mid.erase(prev(mid.end()));
                }
            }
        }
        
        if((int)small.size() < k){
            small.insert(num);
        }else{
            small.insert(num);
            midSum += *prev(small.end());
            mid.insert(*prev(small.end()));
            small.erase(prev(small.end()));
            
            large.insert(*prev(mid.end()));
            midSum -= *prev(mid.end());
            mid.erase(prev(mid.end()));
            
            if((int)large.size() == k + 1){
                midSum += *large.begin();
                mid.insert(*large.begin());
                large.erase(large.begin());
            }
        }
    }
    
    int calculateMKAverage() {
        if((int)q.size() < m){
            return -1;
        }
        return midSum / mid.size();
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */