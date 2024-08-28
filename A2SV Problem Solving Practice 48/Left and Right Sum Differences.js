/**
 * @param {number[]} nums
 * @return {number[]}
 */
var leftRightDifference = function(nums) {
    const n = nums.length;
    const result = new Array(n);
  
    let totalSum = 0;
    for (let num of nums) {
        totalSum += num;
    }
    
 
    let leftSum = 0;
   
    for (let i = 0; i < n; i++) {
    
        let rightSum = totalSum - leftSum - nums[i];
        
      
        result[i] = Math.abs(leftSum - rightSum);
        
        leftSum += nums[i];
    }
    
    return result;
};
