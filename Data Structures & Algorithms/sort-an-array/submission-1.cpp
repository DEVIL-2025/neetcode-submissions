class Solution {
public:

    void merge(vector<int> &nums, int s, int e){
        int mid = s + (e - s)/2;

        int len1 = mid - s + 1;
        int len2 = e - mid;

        int *first = new int[len1];
        int *second = new int[len2];

        int mainArrayIndex = s;

        for(int i = 0 ;  i < len1 ; i++){
            first[i] = nums[mainArrayIndex++];
        }

        mainArrayIndex = mid + 1;
        for(int i = 0 ; i < len2 ; i++){
            second[i] = nums[mainArrayIndex++];
        }

        int index1 = 0;
        int index2 = 0;
        mainArrayIndex = s;
        while(index1 < len1 && index2 < len2){
            if(first[index1] < second[index2]){
                nums[mainArrayIndex++] = first[index1++];
            }
            else{
                nums[mainArrayIndex++] = second[index2++];
            }
        }

        while(index1 < len1){
            nums[mainArrayIndex++] = first[index1++];
        }

        while(index2 < len2){
            nums[mainArrayIndex++] = second[index2++];
        }

        delete[]first;
        delete[]second;

    }

    void mergeSort(vector<int> &nums, int s, int e){
        if(s >= e){
            return;
        }

        int mid = s + (e - s)/2;

        mergeSort(nums, s, mid);

        mergeSort(nums, mid + 1, e);

        merge(nums, s, e);
    }

    vector<int> sortArray(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        mergeSort(nums, s, e);

        return nums;
    }
};