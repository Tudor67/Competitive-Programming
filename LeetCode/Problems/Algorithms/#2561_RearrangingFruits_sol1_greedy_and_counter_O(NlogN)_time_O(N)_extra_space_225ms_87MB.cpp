class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        const int N = basket1.size();
        
        map<int, int> balance;
        for(int i = 0; i < N; ++i){
            balance[basket1[i]] += 1;
            balance[basket2[i]] -= 1;
        }
        
        vector<int> v;
        for(const pair<int, int>& P: balance){
            int num = P.first;
            int numBalance = P.second;
            if(numBalance == 0){
                // num with the same count/freq in both vectors
            }else if(numBalance % 2 == 0){
                v.resize(v.size() + abs(numBalance) / 2, num);
            }else{
                return -1;
            }
        }
        
        const int V_SIZE = v.size();
        int minNum = balance.begin()->first;

        long long res = 0;
        for(int i = 0; i < V_SIZE / 2; ++i){
            res += min(v[i], 2 * minNum);
        }
        
        return res;
    }
};