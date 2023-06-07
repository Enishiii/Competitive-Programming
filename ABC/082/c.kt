import java.util.*

fun main() {
    val scanner = Scanner(System.`in`)
    val arrayLength = scanner.nextInt();

    val numCountMap = mutableMapOf<Int, Int>()
    for (i in 0 until arrayLength) {
        val inputNum = scanner.nextInt()
        numCountMap[inputNum] = numCountMap.getOrDefault(inputNum, 0) + 1
    }

    var minRemovals = 0
    for ((num, count) in numCountMap) {
        minRemovals += if (count < num) count else count - num
    }

    println(minRemovals)
}
