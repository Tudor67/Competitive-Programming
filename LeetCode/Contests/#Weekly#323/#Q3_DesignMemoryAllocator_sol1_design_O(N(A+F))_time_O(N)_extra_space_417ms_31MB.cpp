class Allocator {
private:
    int N;
    vector<int> mIDAt;
    
public:
    Allocator(int N) {
        this->N = N;
        mIDAt.resize(N);
    }
    
    int allocate(int size, int mID) {
        int consecutiveFree = 0;
        for(int i = 0; i < N; ++i){
            if(mIDAt[i] == 0){
                consecutiveFree += 1;
            }else{
                consecutiveFree = 0;
            }
            if(consecutiveFree == size){
                fill(mIDAt.begin() + i - size + 1, mIDAt.begin() + i + 1, mID);
                return i - size + 1;
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int mIDCount = 0;
        for(int i = 0; i < N; ++i){
            if(mIDAt[i] == mID){
                mIDCount += 1;
                mIDAt[i] = 0;
            }
        }
        return mIDCount;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */