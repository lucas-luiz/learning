//generates a new id for every call
const sequence = {
    _id: 1,
    get id() { return this._id++ }
}

const data = {}

function saveElement(element) {
    if (!element.id) { element.id = sequence.id }
    data[element.id] = element
    return element
}

function getElementById(id) {
    return data[id] || {}
}

function getAllElements() {
    return Object.values(data)
}

module.exports = { saveElement, getElementById, getAllElements }
