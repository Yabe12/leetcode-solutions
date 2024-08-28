/**
 * @param {string[]} nums
 * @param {string} target
 * @return {number}
 */
var numOfPairs = function(nums, target) {
    const frequencyMap = new Map();
    let count = 0;

    
    for (const num of nums) {
        frequencyMap.set(num, (frequencyMap.get(num) || 0) + 1);
    }


    for (const num of nums) {
        const numLen = num.length;
        const targetLen = target.length;

        if (target.startsWith(num)) {
            const suffix = target.slice(numLen);
            if (frequencyMap.has(suffix)) {
                count += frequencyMap.get(suffix);
          
                if (suffix === num) {
                    count -= 1;
                }
            }
        }

    
        if (target.endsWith(num)) {
            const prefix = target.slice(0, targetLen - numLen);
            if (frequencyMap.has(prefix)) {
                count += frequencyMap.get(prefix);
         
                if (prefix === num) {
                    count -= 1;
                }
            }
        }
    }


    return count / 2;
};
