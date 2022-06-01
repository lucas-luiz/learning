const stories = {
    storyA: {
        chapters: ["Chapter 1: Lorem Ipsum",
            "Chapter 2: Lorem Ipsum sit Amet",
            "Chapter 3: Lorem Ipsum",
            "Chapter 4: Lorem Amet"]
    }
}

function get(e) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            if (e) {
                resolve(e)
            } else {
                reject("Error")
            }
        }, 1000)
    })
}

get(stories.storyA).then((story) => {
    console.log('Story Found: \n')

    //MAKING MULTIPLE REQUESTS FOR MULTIPLE CHAPTERS (*****Appearing one by one, W/O Promise.all()*****)
    story.chapters.reduce(function (sequence, chapter) {
        //return a .then() for each chapter
        //adds to sequence, that have initial value of a Promise.resolve()
        //It will ever resolve and go to the first .then() of the sequence
        return sequence.then(() => {
            return get(chapter)
        }).then((chapter) => {
            console.log(`${chapter}\n`)
        })
    }, Promise.resolve())

}).catch((err) => {
    console.log(err)
})