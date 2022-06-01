/* Create a function called map that takes two inputs:

-An array of numbers (a list of numbers);

-A 'callback' function - a function that is applied to each element of the array (inside of the function 'map');

Have map return a new array filled with numbers that are the result of using the 'callback' function on each element of the input array.
 */
const map = (array, callback) => {
    let newArray = []
    for (let i = 0; i < array.length; i++) {
        newArray[i] = callback(array[i])
    }
    return newArray
}
const addTwo = n => n + 2

let array = [1, 2, 3, 4, 5]
console.log(map(array, addTwo))