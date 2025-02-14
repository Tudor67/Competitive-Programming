class ProductOfNumbers {
private:
    vector<int> prefProd;
    int lastZeroIndex;

public:
    ProductOfNumbers() {
        prefProd = {1};
        lastZeroIndex = 0;
    }
    
    void add(int num) {
        if(num == 0){
            prefProd.push_back(1);
            lastZeroIndex = (int)prefProd.size() - 1;
        }else{
            prefProd.push_back(prefProd.back() * num);
        }
    }
    
    int getProduct(int k) {
        int l = (int)prefProd.size() - k;
        int r = (int)prefProd.size() - 1;

        if(l <= lastZeroIndex){
            return 0;
        }

        return prefProd[r] / prefProd[l - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */