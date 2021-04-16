class Solution {
private:
    long long getSum(long long i){
        // return (1 + 2 + 3 + ... + i)
        return i * (i + 1) / 2;
    }
    
    long long getTotalSum(long long i){
        // return (getSum(1) + getSum(2) + getSum(3) + ... + getSum(i))
        return (i * (i + 1) * (2 * i + 1) / 6 + i * (i + 1) / 2) / 2;
    }
    
public:
    int minimumBoxes(int N) {
        long long l = 1;
        long long r = min(1820, N);
        while(l != r){
            long long mid = (l + r) / 2;
            if(getTotalSum(mid) < N){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        
        int answer = getSum(r - 1);
        long long prevTotalSum = getTotalSum(r - 1);
        long long ll = 1;
        long long rr = r;
        while(ll != rr){
            long long mid = (ll + rr) / 2;
            if(prevTotalSum + getSum(mid) < N){
                ll = mid + 1;
            }else{
                rr = mid;
            }
        }
        answer += rr;
        
        return answer;
    }
};