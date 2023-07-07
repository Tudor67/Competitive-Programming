class Solution {
private:
    void computeBalance(vector<vector<int>>& requests, int mask, int shift, vector<int>& balance){
        fill(balance.begin(), balance.end(), 0);
        for(int bit = 0; bit + shift < (int)requests.size(); ++bit){
            if((mask >> bit) & 1){
                int a = requests[bit + shift][0];
                int b = requests[bit + shift][1];
                balance[a] -= 1;
                balance[b] += 1;
            }
        }
    }

    struct VectorHash{
        size_t operator()(const vector<int>& V) const {
            string s;
            for(int elem: V){
                s += to_string(elem);
                s += ",";
            }
            return hash<string>()(s);
        }
    };

public:
    int maximumRequests(int N, vector<vector<int>>& requests) {
        const int R = requests.size();

        vector<int> balance(N);
        unordered_map<vector<int>, int, VectorHash> balanceToMaxRequests;
        for(int mask = 0; mask < (1 << (R / 2)); ++mask){
            computeBalance(requests, mask, 0, balance);
            balanceToMaxRequests[balance] = max(balanceToMaxRequests[balance], __builtin_popcount(mask));
        }

        int res = 0;
        for(int mask = 0; mask < (1 << (R - R / 2)); ++mask){
            computeBalance(requests, mask, R / 2, balance);

            for(int& b: balance){
                b = -b;
            }
            
            if(balanceToMaxRequests.count(balance)){
                res = max(res, balanceToMaxRequests[balance] + __builtin_popcount(mask));
            }
        }

        return res;
    }
};