class SlidingWindow{
private:
    vector<int> cnt;
    int distinctElementsCnt;
    
public:
    SlidingWindow(const int& MAX_ELEM){
        cnt.resize(MAX_ELEM + 1, 0);
        distinctElementsCnt = 0;
    }
    
    void add(const int& ELEM){
        distinctElementsCnt += (cnt[ELEM] == 0);
        cnt[ELEM] += 1;
    }
    
    void remove(const int& ELEM){
        cnt[ELEM] -= 1;
        distinctElementsCnt -= (cnt[ELEM] == 0);
    }
    
    int distinctElements(){
        return distinctElementsCnt;
    }
};

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        const int N = A.size();
        int answer = 0;
        
        SlidingWindow window1(N);
        SlidingWindow window2(N);
        for(int l1 = 0, l2 = 0, r = 0; r < N; ++r){
            window1.add(A[r]);
            window2.add(A[r]);
            
            while(window1.distinctElements() > K){
                window1.remove(A[l1++]);
            }
            while(window2.distinctElements() >= K){
                window2.remove(A[l2++]);
            }
            
            answer += (l2 - l1);
        }
        
        return answer;
    }
};