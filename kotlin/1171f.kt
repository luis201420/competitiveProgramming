import java.util.*

class Segment(val a: Int, val b: Int, val index: Int)

fun main() {

    val reader = Scanner(System.`in`)

    val t = reader.nextInt()

    c1@ for (test in 0 until t) {

        val n = reader.nextInt()

        val listS = mutableListOf<Segment>()

        for (i in 0 until n) {
            
            val x = reader.nextInt()
            val y = reader.nextInt()

            listS.add(Segment(x, y, i))
        }

        listS.sortBy { it.a }

        var maxY = 0

        for (i in 0 until listS.size - 1) {

            maxY = maxOf(maxY, listS[i].b)

            if (maxY < listS[i + 1].a) {

                val tag = IntArray(n) { 1 }

                for (j in i + 1 until listS.size) tag[listS[j].index] = 2

                for (ts in tag) print("$ts ")

                println()

                continue@c1
            }
        }

        println(-1)
    }
}
