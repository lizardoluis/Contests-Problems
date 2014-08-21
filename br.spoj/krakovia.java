import java.math.BigInteger;
import java.util.Scanner;
import java.lang.String;

class krakovia
{
	public static void main(String args[])
	{
		int N, F, test=1;
		BigInteger item;		
		Scanner sc = new Scanner(System.in);
				
		//System.out.println("Teste "+N+" e "+F);

		N = sc.nextInt();
		F = sc.nextInt();		
		while(N>0 && F>0){			
			BigInteger bill = new BigInteger ("0");
			
			for(int i=0; i<N; i++){
				item = sc.nextBigInteger();
			    	bill = bill.add( item );		
			}

			System.out.println("Bill #"+ test++ +" costs "+ bill +": each friend should pay "+ bill.divide(BigInteger.valueOf(F)));
			System.out.println();
			
			N = sc.nextInt();
			F = sc.nextInt();
		}
		
	}
}


