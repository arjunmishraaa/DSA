class Solution {
public:
    void nextPermutation(vector<int>&nums) {
         int n=nums.size();
    int idx=-1;

    for(int i=n-2; i>=0 ; i--){
        if(nums[i]<nums[i+1]){
            idx=i;
            break;
        }
    }
    if(idx==-1){
        reverse(nums.begin(),nums.end());
    }
    int temp=nums[idx];
    nums[idx]=nums[idx+1];
    nums[idx+1]=temp;
    
    reverse(nums.begin()+idx+1,nums.end());
    }
   
};