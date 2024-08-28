/**
 * @param {number[]} nums
 * @param {number} pivot
 * @return {number[]} 
 */
var pivotArray = function(nums, pivot) {

    let lessThanPivot = [];
    let equalToPivot = [];
    let greaterThanPivot = [];

    for (let num of nums) {
        if (num < pivot) {
            lessThanPivot.push(num);
        } else if (num === pivot) {
            equalToPivot.push(num);
        } else {
            greaterThanPivot.push(num);
        }
    }

    return lessThanPivot.concat(equalToPivot, greaterThanPivot);
};
