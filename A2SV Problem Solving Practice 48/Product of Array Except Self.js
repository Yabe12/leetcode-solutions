/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    const n = nums.length;
    const prefixProducts = new Array(n).fill(1);
    const suffixProducts = new Array(n).fill(1);
    const result = new Array(n);


    for (let i = 1; i < n; i++) {
        prefixProducts[i] = prefixProducts[i - 1] * nums[i - 1];
    }

    
    for (let i = n - 2; i >= 0; i--) {
        suffixProducts[i] = suffixProducts[i + 1] * nums[i + 1];
    }

 
    for (let i = 0; i < n; i++) {
        result[i] = prefixProducts[i] * suffixProducts[i];
    }

    return result;
};
