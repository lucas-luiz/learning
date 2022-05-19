const map = (array, callback) => {
    let newArray = []
    for(let i=0 ; i < array.length ; i++){
        newArray[i] = callback(array[i])
    }
    return newArray
}
const addTwo = n => n + 2

let array = [1,2,3,4,5]
console.log( map(array, addTwo) )