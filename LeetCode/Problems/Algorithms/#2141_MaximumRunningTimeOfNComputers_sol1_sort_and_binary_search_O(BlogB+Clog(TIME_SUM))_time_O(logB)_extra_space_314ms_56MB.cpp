class Solution {
private:
    long long need(vector<int>& sortedBatteries, const int& C, const long long& MIN_TIME){
        long long needSum = 0;
        for(int i = 0; i < C; ++i){
            if(sortedBatteries[i] < MIN_TIME){
                needSum += (MIN_TIME - sortedBatteries[i]);
            }
        }
        return needSum;
    }
    
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        const int C = n;
        const int B = batteries.size();
        
        sort(batteries.rbegin(), batteries.rend());
        
        long long sumC = accumulate(batteries.begin(), batteries.begin() + C, 0LL);
        long long sumB = accumulate(batteries.begin(), batteries.begin() + B, 0LL);
        
        long long l = batteries[C - 1];
        long long r = sumB / C;
        while(l != r){
            long long mid = (l + r + 1) / 2;
            if(need(batteries, C, mid) <= sumB - sumC){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        return r;
    }
};