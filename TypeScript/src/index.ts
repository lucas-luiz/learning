const readEquation = (equation: string): string => {
    const equationChars: string[] = equation.replace(/\s/g, '').split("")
    let lastParIndex: number[] = []
    let i: number
    equationChars.forEach((e: string, index: number) => {
        if (e == "(") {
            lastParIndex = lastParIndex.concat(index);
        } else if (e == ")") {
            console.log("Parentheses")
            for (i = lastParIndex[lastParIndex.length - 1]; i <= index; i++) {
                console.log(equationChars[i])
            }
            lastParIndex.pop()
        }

    })
    console.log(lastParIndex)
    return "a"
}

readEquation(" (a + b (e-f))(c * d)")