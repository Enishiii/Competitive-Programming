fun main() {
    val input = readLine()!!.split(" ").map { it.toInt() }
    val numBalls = input[0]
    val numColors = input[1]

    var totalWays = numColors.toLong()

    repeat(numBalls - 1) {
        totalWays *= (numColors - 1)
    }

    println(totalWays)
}
