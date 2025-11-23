class Solution {
    public:
        int maximumScore(int a, int b, int c) {
            int arr[3] = {a, b, c};
            sort(arr, arr+ 3);
            int minVal = arr[0];
            int midVal = arr[1];
            int maxVal = arr[2];
    
            if(minVal + midVal <= maxVal){
                return minVal + midVal;
            }
    
            return (a + b + c) / 2;
        }
    };