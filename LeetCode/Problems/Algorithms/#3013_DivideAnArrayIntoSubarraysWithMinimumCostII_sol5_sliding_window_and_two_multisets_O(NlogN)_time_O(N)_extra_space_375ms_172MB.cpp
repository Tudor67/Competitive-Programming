class TopKSmallestSumHelper{
private:
    const int K;
    multiset<int> lMS;
    multiset<int> rMS;
    long long lSum;

    void adjustSize(){
        while((int)lMS.size() > K){
            rMS.insert(*prev(lMS.end()));
            lSum -= *prev(lMS.end());
            lMS.erase(prev(lMS.end()));
        }
        while(!rMS.empty() && (int)lMS.size() < K){
            lSum += *rMS.begin();
            lMS.insert(*rMS.begin());
            rMS.erase(rMS.begin());
        }
    }

public:
    TopKSmallestSumHelper(const int K): K(K) {
        lSum = 0;
    }

    void add(int num){
        if(!rMS.empty() && *rMS.begin() <= num){
            rMS.insert(num);
        }else{
            lSum += num;
            lMS.insert(num);
        }
        adjustSize();
    }

    void remove(int num){
        if(!rMS.empty() && *rMS.begin() <= num){
            rMS.erase(rMS.find(num));
        }else{
            lSum -= num;
            lMS.erase(lMS.find(num));
        }
        adjustSize();
    }

    long long getTopKSmallestSum(){
        return lSum;
    }
};

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        const int N = nums.size();
        const int WINDOW_SIZE = dist + 1;

        long long minCost = accumulate(nums.begin(), nums.begin() + k, (long long)0);
        TopKSmallestSumHelper helper(k - 1);

        for(int i = N - 1; i >= 1; --i){
            helper.add(nums[i]);
            if(i + WINDOW_SIZE < N){
                helper.remove(nums[i + WINDOW_SIZE]);
            }
            if(N - i >= k - 1){
                long long currCost = nums[0] + helper.getTopKSmallestSum();
                minCost = min(minCost, currCost);
            }
        }

        return minCost;
    }
};