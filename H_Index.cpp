#include <vector>
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h = 0;

        sort(citations.begin(), citations.end(), greater<>());

        for(int i = 0; i < citations.size(); i++){
            if(citations[i] > i){
                h++;
            }
        }
        return h;
    }
};