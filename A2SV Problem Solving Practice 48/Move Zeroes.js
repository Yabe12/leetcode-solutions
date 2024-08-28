/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let lastNonZeroFoundAt = 0;  

    for (let current = 0; current < nums.length; current++) {
        if (nums[current] !== 0) {
      
            [nums[lastNonZeroFoundAt], nums[current]] = [nums[current], nums[lastNonZeroFoundAt]];
            lastNonZeroFoundAt++;
        }
    }
};


