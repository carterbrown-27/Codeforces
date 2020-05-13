package id_1334;

import java.io.*;
import java.util.*;

public class B_MiddleClass {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		
		int T = Integer.parseInt(in.nextLine());
		for(int t = 0; t < T; t++) {
			StringTokenizer st = new StringTokenizer(in.nextLine());
			int n = Integer.parseInt(st.nextToken());
			int x = Integer.parseInt(st.nextToken());
			
			st = new StringTokenizer(in.nextLine());
			long surplus = 0;
			int amt = 0;
			ArrayList<Integer> poors = new ArrayList<>();
			for(int i = 0; i < n; i++) {
				int w = Integer.parseInt(st.nextToken());
				if(w>=x) {
					surplus += w-x;
					amt++;
				}else{
					poors.add(w);
				}
			}
			
			if(surplus > 0) {
				Collections.sort(poors, Collections.reverseOrder());
				for(int p: poors) {
					if(surplus >= x-p) {
						surplus -= (x-p);
						amt++;
					} else {
						break;
					}
				}
			}
			
			System.out.println(amt);
		}
		
		in.close();
	}
}
