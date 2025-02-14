class ProductOfNumbers {
private:
    vector<int> prefProd;

public:
    ProductOfNumbers() {
        prefProd = {1};
    }
    
    void add(int num) {
        if(num == 0){
            prefProd = {1};
        }else{
            prefProd.push_back(prefProd.back() * num);
        }
    }
    
    int getProduct(int k) {
        int l = (int)prefProd.size() - k;
        int r = (int)prefProd.size() - 1;
        if(l <= 0){
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