class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        const int N = gifts.size();
        
        long long res = accumulate(gifts.begin(), gifts.end(), 0LL);
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());
        for(int i = 1; i <= k && maxHeap.top() > 1; ++i){
            int num = maxHeap.top();
            maxHeap.pop();

            int newNum = sqrt(num);
            maxHeap.push(newNum);

            res -= num;
            res += newNum;
        }

        return res;
    }
};