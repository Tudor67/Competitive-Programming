class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> superUglyNumbers;
        superUglyNumbers.reserve(n);
        superUglyNumbers.push_back(1);
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        for(int i = 0; i < primes.size(); ++i){
            minHeap.push({primes[i], i, 0});
        }
        
        while(superUglyNumbers.size() < n){
            superUglyNumbers.push_back(minHeap.top()[0]);
            while(!minHeap.empty() && minHeap.top()[0] == superUglyNumbers.back()){
                vector<int> v = minHeap.top();
                if(superUglyNumbers[v[2] + 1] <= INT_MAX / primes[v[1]]){
                    minHeap.push({superUglyNumbers[v[2] + 1] * primes[v[1]], v[1], v[2] + 1});
                }
                minHeap.pop();
            }
        }
        
        return superUglyNumbers.back();
    }
};