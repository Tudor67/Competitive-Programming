class Solution {
private:
    bool isValid(vector<int>& v, int r, int k, const long long& MIN_THRESHOLD){
        const int N = v.size();
        
        deque<long long> dq;
        long long sum = 0;
        for(int i = 0; i < r; ++i){
            dq.push_back(v[i]);
            sum += v[i];
        }
        
        for(int i = r; i < N && k >= 0; ++i){
            dq.push_back(v[i]);
            sum += v[i];
            
            if((int)dq.size() > 2 * r + 1){
                sum -= dq.front();
                dq.pop_front();
            }
            
            if(sum < MIN_THRESHOLD){
                dq.back() += (MIN_THRESHOLD - sum);
                k -= (MIN_THRESHOLD - sum);
                sum += (MIN_THRESHOLD - sum);
            }
        }
        
        while((int)dq.size() >= r + 2 && k >= 0){
            sum -= dq.front();
            dq.pop_front();
            
            if(sum < MIN_THRESHOLD){
                dq.back() += (MIN_THRESHOLD - sum);
                k -= (MIN_THRESHOLD - sum);
                sum += (MIN_THRESHOLD - sum);
            }
        }
        
        return (k >= 0);
    }
    
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        const int N = stations.size();
        const long long TOTAL_SUM = accumulate(stations.begin(), stations.end(), 0LL);

        long long left = 0;
        long long right = TOTAL_SUM + k;
        while(left != right){
            long long mid = (left + right + 1) / 2;
            if(isValid(stations, r, k, mid)){
                left = mid;
            }else{
                right = mid - 1;
            }
        }
        
        return right;
    }
};