package id_1334;

import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.*;
public class C_MonsterCircle {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(in.readLine());
		for(int t = 0; t < T; t++) {
			int n = Integer.parseInt(in.readLine());
			
			long[] a = new long[n];
			long[] b = new long[n];
			
			StringTokenizer st;
			for(int i = 0; i < n; i++) {
				st = new StringTokenizer(in.readLine());
				a[i] = Long.parseLong(st.nextToken());
				b[i] = Long.parseLong(st.nextToken());
			}
			
			long bulletsOnFirst = Long.MAX_VALUE;
			long bullets = 0;
			for(int i = 0; i < n; i++) {
				int next = (i+1) % n;
				
				// if not killed by previous explosion, will be > 0.
				bullets += Math.max(a[next] - b[i],0);
				
				// smallest health.
				bulletsOnFirst = Math.min(bulletsOnFirst, Math.min(a[next], b[i]));
			}
			
			System.out.println(bullets + bulletsOnFirst);
		}
		
		in.close();
	}
}
