import java.util.Scanner
import java.util.Arrays

fun main(args: Array<String>) {
	val reader = Scanner(System.`in`)

	var x:Int = reader.nextInt()
    	var y:Int = reader.nextInt()
    	var z:Int = reader.nextInt()
    
    	var g:Int = reader.nextInt()
    	var p:Int = reader.nextInt()
    	var b:Int = reader.nextInt()
	
	var aux:Int 

    	if(g>=x){
		g-=x
		aux=g+p
		if(aux>=y){
			aux-=y
			aux+=b
			if(aux>=z){
				println("YES")
			}
			else{
				println("NO")
			}
		}
		else{
			println("NO")
		}
    	}
	else{
		println("NO")
	}
}
