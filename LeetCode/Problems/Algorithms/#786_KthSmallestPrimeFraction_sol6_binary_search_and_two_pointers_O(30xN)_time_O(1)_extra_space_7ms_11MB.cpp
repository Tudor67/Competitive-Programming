class Solution {
private:
    int countLess(vector<int>& arr, long double threshold){
        const int N = arr.size();

        int c = 0;
        for(int i = 0, j = 0; i < N - 1; ++i){
            j = max(j, i + 1);
            while(j < N && arr[i] >= threshold * arr[j]){
                j += 1;
            }
            c += (N - j);
        }

        return c;
    }

public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        const int N = arr.size();
        const long double EPS = 1e-8;

        long double l = 0;
        long double r = 1;
        while(r - l > EPS){
            long double mid = (l + r) / 2;
            if(countLess(arr, mid) < k){
                l = mid;
            }else{
                r = mid;
            }
        }

        long double threshold = l;
        int a = 1;
        int b = 1;
        for(int i = 0, j = 0; i < N - 1; ++i){
            j = max(j, i + 1);
            while(j < N && arr[i] >= threshold * arr[j]){
                if(arr[i] * b <= a * arr[j]){
                    a = arr[i];
                    b = arr[j];
                }
                j += 1;
            }
        }

        return {a, b};
    }
};