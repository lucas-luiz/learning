const stories = {
    storyA: {
        chapters: ["Chapter 1: Lorem Ipsum",
            "Chapter 2: Lorem Ipsum sit Amet",
            "Chapter 3: Lorem Ipsum",
            "Chapter 4: Lorem Amet"]
    }
}

function getStories(stories) {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            if (stories) {
                resolve(stories)
            } else {
                reject("Error")
            }
        }, 1000)
    })
}

getStories(stories).then((stories) => {
    console.log('Stories found')
    console.log(stories.chapters.reduce(function (sequence, chapter) {
        //retornar a sequencia de .then() para cada capítulo
    }))
}).catch((err) => {
    console.log(err)
})