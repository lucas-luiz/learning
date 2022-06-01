function method(seconds, res) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve(res)
        }, seconds * 1000)
    })
}

//promise that waits 2 seconds
method(2, 2).then((res) => {
    console.log(`Returning ${res}, The next .then() will take ${res} seconds`)//1
    //returning another promisse, the resolve will be the parameter in the second then
    return method(res, 4)
}).then((res) => {
    console.log(`Returning ${res} after waiting`)//4,
})