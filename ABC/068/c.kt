import java.util.*

fun main(args: Array<String>) {
    val scanner = Scanner(System.`in`)

    val numIslands = scanner.nextInt()
    val numRoutes = scanner.nextInt()

    val graph = Array(numIslands) { mutableListOf<Int>() }
    repeat(numRoutes) {
        val a = scanner.nextInt() - 1
        val b = scanner.nextInt() - 1
        graph[a].add(b)
        graph[b].add(a)
    }

    var routeExists = false
    for (island in graph[0]) {
        if (numIslands - 1 in graph[island]) {
            routeExists = true;
            break;
        }
    }

    if (routeExists) println("POSSIBLE")
    else println("IMPOSSIBLE")
}
