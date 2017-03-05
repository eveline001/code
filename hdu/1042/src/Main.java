import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		int n;
		while(cin.hasNextInt()){
			n = cin.nextInt();
			BigInteger ans = BigInteger.valueOf(1);
			for(int i = 1; i <= n; i++){
				ans = ans.multiply(BigInteger.valueOf(i));
			}
			System.out.println(ans);
		}
		return;
	}
}
