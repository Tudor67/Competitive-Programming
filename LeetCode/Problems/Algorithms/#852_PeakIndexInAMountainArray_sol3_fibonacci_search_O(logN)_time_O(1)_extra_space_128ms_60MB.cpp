class Solution {
private:
    void fibBack(int& fib1, int& fib2, int& fib3){
        if(fib1 > 0){
            fib3 = fib2;
            fib2 = fib1;
            fib1 = fib3 - fib2;
        }
    }

public:
    int peakIndexInMountainArray(vector<int>& arr) {
        const int N = arr.size();

        int fib1 = 0;
        int fib2 = 1;
        int fib3 = fib1 + fib2;
        while(fib3 < N){
            fib1 = fib2;
            fib2 = fib3;
            fib3 = fib1 + fib2;
        }

        int index = 1;
        while(fib1 > 0){
            int i = min(index + fib1 - 1, N - 2);
            if(arr[i] < arr[i + 1]){
                index = i + 1;
                fibBack(fib1, fib2, fib3);
            }else{
                fibBack(fib1, fib2, fib3);
                fibBack(fib1, fib2, fib3);
            }
        }

        return index;
    }
};