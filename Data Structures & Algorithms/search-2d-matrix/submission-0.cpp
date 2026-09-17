class Solution {
public:
    bool binarySearch(vector<int> arr, int target){
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(arr[mid] == target){
                return true;
            }
            else if(arr[mid] < target){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> arr;
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                arr.push_back(matrix[i][j]);
            }
        }

        return binarySearch(arr, target);
    }
};
