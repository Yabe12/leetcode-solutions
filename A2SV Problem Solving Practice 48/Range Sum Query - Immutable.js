/**
 * @param {number[]} nums
 */
var NumArray = function(nums) {
   
    this.prefixSum = new Array(nums.length);
    
  
    this.prefixSum[0] = nums[0];
    for (let i = 1; i < nums.length; i++) {
        this.prefixSum[i] = this.prefixSum[i - 1] + nums[i];
    }
};


NumArray.prototype.sumRange = function(left, right) {
   
    if (left === 0) {
        return this.prefixSum[right];
    } else {
        return this.prefixSum[right] - this.prefixSum[left - 1];
    }
};
