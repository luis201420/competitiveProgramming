import java.util.Scanner
import java.util.Arrays

fun main(args: Array<String>) {
	val reader = Scanner(System.`in`)

	var n:Int = reader.nextLine().trim().toInt()
	var s:String = reader.nextLine().trim().toString()

	val cont = IntArray(26){0}

	var ver:Int=0

	for(e in s){
		cont[e-'a']++
		if(cont[e-'a']>1){
			ver=1
			break
		}
	}
	if(ver==1 || n==1){
		println("Yes")
	}
	else{
		println("No")
	}
}
