class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int max1 = INT_MIN, min1 = INT_MAX;
        int max2 = INT_MIN, min2 = INT_MAX;
        int max3 = INT_MIN, min3 = INT_MAX;
        int max4 = INT_MIN, min4 = INT_MAX;

        for(int i =0;i<n;i++){
            int v1 = arr1[i] +  arr2[i] + i;
            int v2 = arr1[i] +  arr2[i] - i;
            int v3 = arr1[i] -  arr2[i] + i;
            int v4 = arr1[i] -  arr2[i] - i;
        
            max1 = max(max1, v1);
            min1 = min(min1, v1);
            
            max2 = max(max2, v2);
            min2 = min(min2, v2);
            
            max3 = max(max3, v3);
            min3 = min(min3, v3);

            max4 = max(max4, v4);
            min4 = min(min4, v4);

      }  
    int res = 0;

    res = max(res, max1 - min1);
    res = max(res, max2 - min2);
    res = max(res, max3 - min3);
    res = max(res, max4 - min4);

    return res;
    }
};