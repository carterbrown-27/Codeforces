package id_1334;
import java.io.*;
import java.util.*;

public class F_StrangeFunc {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int N = Integer.parseInt(in.nextLine());
		int[] a = new int[N];
		StringTokenizer st = new StringTokenizer(in.nextLine());
		for(int i = 0; i < N; i++) {
			a[i] = Integer.parseInt(st.nextToken());
		}
		
		int[] p = new int[N];
		st = new StringTokenizer(in.nextLine());
		for(int i = 0; i < N; i++) {
			p[i] = Integer.parseInt(st.nextToken());
		}
		
		int M = Integer.parseInt(in.nextLine());
		int[] b = new int[M];
		st = new StringTokenizer(in.nextLine());
		for(int i = 0; i < M; i++) {
			b[i] = Integer.parseInt(st.nextToken());
		}
		
		in.close();
		
		if(!possible(a,b)) {
			System.out.println("NO");
		}else {
			int ans = solve(a,b,p,0,0);
			System.out.println("YES");
			System.out.println(ans);
		}
	}
	
	public static boolean possible(int[] a, int[] b) {
		int pos = 0;
		for(int x: a) {
			if(x==b[pos]) {
				pos++;
				if(pos>=b.length) return true;
			}
		}
		return false;
	}
	
	// DP This! but how?
	public static final int LARGE = 1000000000;
	public static int solve(int[] a, int[] b, int[] p, int pos, int last) {
		int[] fa = func(a);
		if(Arrays.equals(fa,b)) {
			return 0;
		}
		
		if(pos>=a.length) {
			return LARGE;
		}
		
		// included in seq.
		int noRemove = solve(a,b,p,pos+1,Math.max(last,a[pos]));
		int remove = LARGE;
		if(a[pos] != -1 && (a[pos] > last || p[pos] < 0)) {
			int[] a_temp = a.clone();
			a_temp[pos] = -1;
			remove = solve(a_temp,b,p,pos+1,last) + p[pos];
		}
		
		// if(remove < noRemove) System.out.printf("Cut %d, cost = %d: else = %d\n", pos, remove, noRemove);
		
		return Math.min(Math.min(noRemove,remove), LARGE);
	}
	
	public static int[] func(int[] a){
		ArrayList<Integer> fa = new ArrayList<>();
		for(int x: a) {
			if(x >= 1 && x > (fa.size() == 0 ? 0 : fa.get(fa.size()-1))) {
				fa.add(x);
			}
		}
		
		int[] arr = new int[fa.size()];
		for(int i = 0; i < fa.size(); i++) {
			arr[i] = fa.get(i);
		}
		
		return arr;
	}
}
