package id_1334;

import java.io.*;
import java.util.*;

public class A_LevelStatistics {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		
		int T = Integer.parseInt(in.nextLine());
		
		for(int t = 0; t < T; t++) {
			boolean works = true;
			int n = Integer.parseInt(in.nextLine());
			
			int last_p = 0;
			int last_c = 0;
			
			StringTokenizer st;
			for(int i = 0; i < n; i++) {
				st = new StringTokenizer(in.nextLine());
				
				int p = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());
				
				if(c < last_c || p < last_p || c-last_c > p-last_p) {
					works = false;
				}else {
					last_c = c;
					last_p = p;
				}
			}
			
			System.out.println(works ? "YES" : "NO");
		}
		
		in.close();
	}
}
