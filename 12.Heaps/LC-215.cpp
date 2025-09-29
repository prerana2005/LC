class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size()-1;
        while(true){
            int pivot_index = rand()%(right-left+1)+ left;
            int new_pivot_ind = partition(nums,left,right,pivot_index);
            if(new_pivot_ind == nums.size()-k){
                return nums[new_pivot_ind];
            }
            else if(new_pivot_ind>nums.size()-k){
                right = new_pivot_ind-1;
            }
            else{
                left = new_pivot_ind+1;
            }
        }
    }
private:
    int partition(vector<int>& nums, int left, int right, int pivot_index){
        int pivot = nums[pivot_index];
        swap(nums[pivot_index],nums[right]);
        int stored_ind = left;
        for(int i = left; i<right; i++){
            if(nums[i]<pivot){
                swap(nums[i], nums[stored_ind]);
                stored_ind++;
            }
        }
        swap(nums[right], nums[stored_ind]);
        return stored_ind;
    }
};