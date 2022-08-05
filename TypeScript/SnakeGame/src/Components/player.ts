class Player {
    name: string
    width: number
    height: number
    position: {
        x: number
        y: number
    }
    placeholderColorRGB: number
    scale(n: number) {
        this.position.x *= n
        this.position.y *= n
    }
    /* constructor(name: string) */
}
export default Player

