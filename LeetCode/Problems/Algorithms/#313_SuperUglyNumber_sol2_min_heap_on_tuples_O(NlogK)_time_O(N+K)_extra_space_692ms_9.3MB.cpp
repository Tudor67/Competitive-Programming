class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> superUglyNumbers;
        superUglyNumbers.reserve(n);
        superUglyNumbers.push_back(1);
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        for(int i = 0; i < primes.size(); ++i){
            minHeap.push({primes[i], i, 0});
        }
        
        while(superUglyNumbers.size() < n){
            superUglyNumbers.push_back(get<0>(minHeap.top()));
            while(!minHeap.empty() && get<0>(minHeap.top()) == superUglyNumbers.back()){
                tuple<int, int, int> t = minHeap.top();
                if(superUglyNumbers[get<2>(t) + 1] <= INT_MAX / primes[get<1>(t)]){
                    minHeap.push({superUglyNumbers[get<2>(t) + 1] * primes[get<1>(t)], get<1>(t), get<2>(t) + 1});
                }
                minHeap.pop();
            }
        }
        
        return superUglyNumbers.back();
    }
};