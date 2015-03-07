import java.math.BigInteger;
import java.util.Scanner;
public class  ConnectionPku2084
{
	BigInteger   f[]=new BigInteger[101];
	static final BigInteger b1=new BigInteger("1");
	static final BigInteger b0=new BigInteger("0");
BigInteger solve(int n)
{
	if(n==0)return b1;
	if(n==1)return b1;
	if(f[n]!=null)return f[n];
	int i;
	f[n]=b0;
	for(i=0;i<n;i++)
	{
		f[n]=f[n].add(solve(i).multiply(solve(n-1-i)));
	}
	return f[n];
}
	public static void main(String[] args) 
	{
		 ConnectionPku2084 c=new ConnectionPku2084();
		Scanner sc=new Scanner(System.in);
		int n=0;
		while(-1!=(n=sc.nextInt()))
		{
			System.out.println(c.solve(n));
		}
		sc.close();
	}
}
