/**
 * @param {number[]} nums
 * @param {number[][]} requests
 * @return {number}
 */
var maxSumRangeQuery = function(nums, requests) {
    const MOD = 1e9 + 7;
    const n = nums.length;
    const frequency = new Array(n).fill(0);
    

    for (const [start, end] of requests) {
        frequency[start] += 1;
        if (end + 1 < n) {
            frequency[end + 1] -= 1;
        }
    }
   
    for (let i = 1; i < n; i++) {
        frequency[i] += frequency[i - 1];
    }
    
   
    nums.sort((a, b) => b - a);
    frequency.sort((a, b) => b - a);
    
  
    let result = 0;
    for (let i = 0; i < n; i++) {
        result = (result + nums[i] * frequency[i]) % MOD;
    }
    
    return result;
};
