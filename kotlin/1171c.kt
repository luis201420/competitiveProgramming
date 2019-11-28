import java.util.Scanner
import java.util.Arrays

fun main(args: Array<String>) {
    val reader = Scanner(System.`in`)

    var t:Int = reader.nextLine().trim().toInt()

    while(t>0){

    	var s:String = reader.nextLine().trim().toString()
    	val l = s.toCharArray()
    	l.sort()
    	val ans = StringBuilder()
    	for( e in l){
       		ans.append(e)
    	}
    	var s2:String = ans.toString()
	var s3:String = s.reversed()
    	if(s2 != s || (s2==s && s!=s3)){
       		println(s2)
    	}
    	else{
       		println("-1")
    	}
	t--
    }
}
