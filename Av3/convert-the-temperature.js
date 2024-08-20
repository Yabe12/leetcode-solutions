/**
 * @param {number} celsius
 * @return {number[]}
 */
var convertTemperature = function (celsius) {
  const kelvin = celsius + 273.15;
  const fahrenheit = celsius * 1.8 + 32;
  return [kelvin, fahrenheit];
};
console.log(convertTemperature(36.5));
console.log(convertTemperature(122.11));
