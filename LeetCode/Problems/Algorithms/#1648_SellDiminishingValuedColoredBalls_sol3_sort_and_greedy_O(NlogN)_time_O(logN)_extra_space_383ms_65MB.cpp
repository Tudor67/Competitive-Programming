class Solution {
private:
    long long computePrefSum(long long n){
        return n * (n + 1) / 2;
    }
    
public:
    int maxProfit(vector<int>& inventory, int orders) {
        const int N = inventory.size();
        const int MODULO = 1e9 + 7;
        
        sort(inventory.rbegin(), inventory.rend());
        
        inventory.push_back(0);
        
        long long answer = 0;
        for(long long i = 0; i < N; ++i){
            if(inventory[i] > inventory[i + 1]){
                if((i + 1) * (inventory[i] - inventory[i + 1]) <= orders){
                    answer += (i + 1) * (computePrefSum(inventory[i]) - computePrefSum(inventory[i + 1]));
                    answer %= MODULO;
                    orders -= (i + 1) * (inventory[i] - inventory[i + 1]);
                }else{
                    long long q = orders / (i + 1);
                    long long rem = orders % (i + 1);
                    answer += (i + 1) * (computePrefSum(inventory[i]) - computePrefSum(inventory[i] - q));
                    answer += rem * (inventory[i] - q);
                    answer %= MODULO;
                    orders = 0;
                    break;
                }
            }
        }
        
        inventory.pop_back();
        
        return answer;
    }
};