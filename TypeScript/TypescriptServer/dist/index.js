"use strict";
const readEquation = (equation) => {
    const equationChars = equation.replace(/\s/g, '').split("");
    let lastParIndex = [];
    let i;
    equationChars.forEach((e, index) => {
        if (e == "(") {
            lastParIndex = lastParIndex.concat(index);
        }
        else if (e == ")") {
            console.log("Parentheses");
            for (i = lastParIndex[lastParIndex.length - 1]; i <= index; i++) {
                console.log(equationChars[i]);
            }
            lastParIndex.pop();
        }
    });
    console.log(lastParIndex);
    return "a";
};
readEquation(" (a + b (e-f))(c * d)");
