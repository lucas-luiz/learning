/* Promise.all takes a series of promises and creates a promise 
that is fulfilled the moment all others are successfully completed. 
You receive an array of results (regardless of the results of each promise) 
in the ***same order**** as the promises you received. */

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

    //MAKING MULTIPLE REQUESTS FOR MULTIPLE CHAPTERS MULTI THREAD AND ASYNC
    Promise.all(story.chapters.map((chapter) => {
        return (
            get(chapter)
                .then((res) => {
                    console.log(res)
                })
        )
    }))

}).catch((err) => {
    console.log(err)
})