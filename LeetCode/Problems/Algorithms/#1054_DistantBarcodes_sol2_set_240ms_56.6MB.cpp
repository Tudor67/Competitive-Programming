class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        const int MIN_BARCODE = *min_element(barcodes.begin(), barcodes.end());
        const int MAX_BARCODE = *max_element(barcodes.begin(), barcodes.end());
        
        vector<int> cnt(MAX_BARCODE + 1, 0);
        for(int barcode: barcodes){
            cnt[barcode] += 1;
        }
        
        set<pair<int, int>> cntBarcodeSet;
        for(int barcode = MIN_BARCODE; barcode <= MAX_BARCODE; ++barcode){
            if(cnt[barcode] > 0){
                cntBarcodeSet.insert({cnt[barcode], barcode});
            }
        }
        
        vector<int> answer;
        int prevBarcode = -1;
        int barcode;
        while(!cntBarcodeSet.empty()){
            set<pair<int, int>>::iterator it = prev(cntBarcodeSet.end());
            if(prevBarcode == it->second){
                it = prev(it);
            }
            
            barcode = it->second;
            answer.push_back(barcode);
            cnt[barcode] -= 1;
            cntBarcodeSet.erase(it);
            if(cnt[barcode] > 0){
                cntBarcodeSet.insert({cnt[barcode], barcode});
            }
            
            prevBarcode = barcode;
        }
        
        return answer;
    }
};