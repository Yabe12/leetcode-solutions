// Given two binary strings a and b, return their sum as a binary string.

 

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"
 
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
  let num1 = parseInt (a,2)
  let num2 = parseInt (b,2)
  let sum = num1 + num2
  let total = sum . toString (2)
 
  
  return total
};