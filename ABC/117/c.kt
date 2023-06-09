import java.util.Scanner
import java.util.Arrays

fun main(args: Array<String>) {
    val scanner = Scanner(System.`in`)

    val numPieces = scanner.nextInt()
    val numTargets = scanner.nextInt()

    val targets = IntArray(numTargets)
    for (i in 0 until numTargets) {
        targets[i] = scanner.nextInt()
    }

    Arrays.sort(targets)

    val distances = IntArray(numTargets - 1)
    for (i in 0 until numTargets - 1) {
        distances[i] = targets[i + 1] - targets[i]
    }

    Arrays.sort(distances)

    var minMoves: Long = 0
    for (i in 0 until numTargets - numPieces) {
        minMoves += distances[i].toLong()
    }

    println(minMoves)
}
