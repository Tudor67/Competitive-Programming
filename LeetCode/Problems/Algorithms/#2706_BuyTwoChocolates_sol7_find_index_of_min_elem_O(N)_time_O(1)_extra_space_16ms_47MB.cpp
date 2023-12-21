class Solution {
private:
    int getIndexOfMinElem(vector<int>& v, int excludedIndex){
        const int N = v.size();
        int minElem = INT_MAX;
        int minElemIndex = -1;
        for(int i = 0; i < N; ++i){
            if(i != excludedIndex && minElem > v[i]){
                minElem = v[i];
                minElemIndex = i;
            }
        }
        return minElemIndex;
    }

public:
    int buyChoco(vector<int>& prices, int money) {
        int i = getIndexOfMinElem(prices, -1);
        int j = getIndexOfMinElem(prices, i);

        if(prices[i] + prices[j] <= money){
            return money - (prices[i] + prices[j]);
        }

        return money;
    }
};