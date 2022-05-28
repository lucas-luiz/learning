const res = process.argv.indexOf('-a') !== -1
process.stdout.write('how much is 2 + 2?: ')
process.stdin.on('data', (data) => {
    if (data == 4) {
        process.stdout.write(`You're right!`)
    } else {
        process.stdout.write(`You're wrong!`)
    }
    process.exit()

})

