import java.util.*;
//http://coj.uci.cu/24h/problem.xhtml?abb=1625
class Main {
	
	public static String outWeekDay[]={"","SUNDAY","MONDAY","TUESDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY"};
	public static HashMap<String,Integer> inMonth=new HashMap<String,Integer>();
	
	public static void main(String[] args) {
		int cases;
		Scanner input=new Scanner(System.in);
		cases=input.nextInt();
		Calendar calendar = Calendar.getInstance();
		inMonth.put("JANUARY",0);
		inMonth.put("FEBRUARY",1);
		inMonth.put("MARCH",2);
		inMonth.put("APRIL",3);
		inMonth.put("MAY",4);
		inMonth.put("JUNE",5);
		inMonth.put("JULY",6);
		inMonth.put("AUGUST",7);
		inMonth.put("SEPTEMBER",8);
		inMonth.put("OCTOBER",9);
		inMonth.put("NOVEMBER",10);
		inMonth.put("DECEMBER",11);
		for(int i=0;i<cases;i++){
			calendar.set(Calendar.YEAR, input.nextInt());
			calendar.set(Calendar.MONTH, inMonth.get(input.next()));
			calendar.set(Calendar.DAY_OF_MONTH, input.nextInt());
			System.out.println(outWeekDay[calendar.get(Calendar.DAY_OF_WEEK)]);
		}
	}	
}
/*

3
2011 NOVEMBER 21
2006 OCTOBER 31
1800 JANUARY 1


*/