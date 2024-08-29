/**
 * @param {number[][]} bookings
 * @param {number} n
 * @return {number[]}
 */
var corpFlightBookings = function(bookings, n) {
   
    let diff = new Array(n + 1).fill(0);

    for (let [start, end, seats] of bookings) {
        diff[start - 1] += seats;
        if (end < n) {
            diff[end] -= seats;
        }
    }


    let result = new Array(n);
    result[0] = diff[0];
    for (let i = 1; i < n; i++) {
        result[i] = result[i - 1] + diff[i];
    }

    return result;
};

