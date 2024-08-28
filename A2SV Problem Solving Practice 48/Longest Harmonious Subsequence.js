/**
 * @param {number[]} nums
 * @return {number}
 */
var findLHS = function(nums) {
  
    const frequencyMap = new Map();
    for (const num of nums) {
        frequencyMap.set(num, (frequencyMap.get(num) || 0) + 1);
    }

    let maxLength = 0;

    for (const num of frequencyMap.keys()) {
        if (frequencyMap.has(num + 1)) {
        
            const length = frequencyMap.get(num) + frequencyMap.get(num + 1);
            maxLength = Math.max(maxLength, length);
        }
    }

    return maxLength;
};
