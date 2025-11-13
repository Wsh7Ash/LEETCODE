class Solution {
    public:
        int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
            sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b){
                return a[1] > b[1];
            });
    
            int totalUnits = 0;
            int boxesLoaded = 0;
            for(const auto& boxType : boxTypes){
                int numOfBoxes = boxType[0];
                int unitsPerBox = boxType[1];
                if(boxesLoaded + numOfBoxes <= truckSize){
                    boxesLoaded += numOfBoxes;
                    totalUnits += numOfBoxes * unitsPerBox;
                }else{
                    int remSpace = truckSize - boxesLoaded;
                    totalUnits += remSpace * unitsPerBox;
                    break;
                }
            }
            return totalUnits;
        }
    };