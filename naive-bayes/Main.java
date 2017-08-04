import java.io.*;
import java.util.*;
public class Main {
	static String arr[][]=new String[30][5];
	public static void main(String[] args)throws IOException {
		Scanner sc=new Scanner(System.in);
		BufferedReader br = new BufferedReader(new FileReader("dataset"));
		String s="";
		int l=0;
		while((s=br.readLine())!=null) {
			StringTokenizer st=new StringTokenizer(s);
			int j=0;
			while(st.hasMoreTokens()) {
				arr[l][j]=st.nextToken();
				j++;	
			}
			l++;
		}
		System.out.println("How's the outlook? ");
		String outlook=sc.nextLine();
		System.out.println("How's the temperature?  ");
		String temp=sc.nextLine();
		System.out.println("How's the humidity? ");
		String humidity=sc.nextLine();
		System.out.println("Is it windy? ");
		String windy=sc.nextLine();		
		System.out.println();
	    	
		double prob_c1=calc_prob("yes",outlook,temp,humidity,windy,l);
	    	System.out.println("Yes -> " +prob_c1);
	    
	    	double prob_c2=calc_prob("no",outlook,temp,humidity,windy,l);
	    	System.out.println("No -> " +prob_c2);
	    	System.out.println();
		if(prob_c1 > prob_c2) {
			System.out.println("Go to play!!!");	
		}
		else if(prob_c2 > prob_c1) {
			System.out.println("It's a bad idea. Don't go to play.");	
		}
		else {
			System.out.println("May or May not play, upto you.");	
		}
	}
	
	public static double calc_prob(String value,String outlook,String temp,String humidity,String windy,int l) {
		int total=0;
		int favourable=0;
		double prob=1;
		
		for(int i=0;i<l;i++) {
			if(value.equals(arr[i][4])) {
			  total++;
			}
			if(outlook.equals(arr[i][0])&&value.equals(arr[i][4])) {
				favourable++;	
			}
		}
		double val=(double)favourable/total;
		prob=prob*val;	
		total=0;
		favourable=0;
		for(int i=0;i<l;i++) {
			if(value.equals(arr[i][4])) {
			  total++;
			}
			if(temp.equals(arr[i][1])&&value.equals(arr[i][4])) {
				favourable++;	
			}
		}
		val=(double)favourable/total;
		prob=prob*val;
		total=0;
		favourable=0;
		for(int i=0;i<l;i++) {
			if(value.equals(arr[i][4])) {
			  total++;
			}
			if(humidity.equals(arr[i][2])&&value.equals(arr[i][4])) {
				favourable++;	
			}
		}
		val=(double)favourable/total;
		prob=prob*val;
		total=0;
		favourable=0;
		for(int i=0;i<l;i++) {
			if(value.equals(arr[i][4])) {
			  total++;
			}
			if(windy.equals(arr[i][3])&&value.equals(arr[i][4]))
			{
				favourable++;	
			}
		}
		val=(double)favourable/total;
		prob=prob*val;
		return prob;
	}	
}
