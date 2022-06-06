const port = 3000

const express = require('express')
const app = express()
const bodyParser = require('body-parser')
const db = require('./db')

app.use(bodyParser.urlencoded({ extended: true }))

app.get('/database', (req, res, next) => {
    res.send(db.getAllElements())
})

app.get('/database/:id', (req, res, next) => {
    res.send(db.getElementById(req.params.id))
})

app.post('/database', (req, res, next) => {
    const element = db.saveElement({
        name: req.body.name,
        id: req.body.id,
        price: req.body.price

    })
    res.send(element)
})

app.listen(port, () => {
    console.log(`Server running at: ${port}`)
})