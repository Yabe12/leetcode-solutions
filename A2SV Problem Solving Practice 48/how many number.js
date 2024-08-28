/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function(nums) {
    const maxVal = 100; 
    const counts = new Array(maxVal + 1).fill(0);

   
    for (let num of nums) {
        counts[num]++;
    }


    const prefixSums = new Array(maxVal + 1).fill(0);
    for (let i = 1; i <= maxVal; i++) {
        prefixSums[i] = prefixSums[i - 1] + counts[i - 1];
    }


    const result = new Array(nums.length);
    for (let i = 0; i < nums.length; i++) {
        result[i] = prefixSums[nums[i]];
    }

    return result;
};
