class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> factors;
        for(int i = 1; i * i <= n; ++i){
            if(n % i == 0){
                factors.push_back(i);
                if(i != n / i){
                    factors.push_back(n / i);
                }
            }
        }
        
        int answer = -1;
        if(k <= factors.size()){
            nth_element(factors.begin(), factors.begin() + k - 1, factors.end());
            answer = factors[k - 1];
        }
        
        return answer;
    }
};