class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        const int MIN_BARCODE = *min_element(barcodes.begin(), barcodes.end());
        const int MAX_BARCODE = *max_element(barcodes.begin(), barcodes.end());
        
        vector<int> cnt(MAX_BARCODE + 1, 0);
        for(int barcode: barcodes){
            cnt[barcode] += 1;
        }
        
        priority_queue<pair<int, int>> maxHeap;
        for(int barcode = MIN_BARCODE; barcode <= MAX_BARCODE; ++barcode){
            if(cnt[barcode] > 0){
                maxHeap.push({cnt[barcode], barcode});
            }
        }
        
        vector<int> answer;
        int prevBarcode = -1;
        int barcode;
        while(!maxHeap.empty()){
            int temp = -1;
            if(prevBarcode == maxHeap.top().second){
                temp = maxHeap.top().second;
                maxHeap.pop();
            }
            
            barcode = maxHeap.top().second;
            answer.push_back(barcode);
            cnt[barcode] -= 1;
            maxHeap.pop();
            if(cnt[barcode] > 0){
                maxHeap.push({cnt[barcode], barcode});
            }
            if(temp != -1){
                maxHeap.push({cnt[temp], temp});
            }
            
            prevBarcode = barcode;
        }
        
        return answer;
    }
};