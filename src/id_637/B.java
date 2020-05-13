package id_637;

import java.io.*;
import java.util.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            int[] a = new int[n];
            st = new StringTokenizer(in.readLine());
            for(int i = 0; i < n; i++){
                a[i] = Integer.parseInt(st.nextToken());
            }

            boolean[] peaks = new boolean[n];
            for(int i = 1; i < n-1; i++){
                if(a[i-1] < a[i] && a[i] > a[i+1]) peaks[i] = true;
            }

            //System.out.println(Arrays.toString(peaks));

            int sum = 0;
            for(int i = 1; i < k-1; i++){
                if(peaks[i]) sum++;
            }

            // System.out.println(sum);
            int max = sum;
            int maxpos = 0;

            for(int start = 1; start <= n-k; start++){
                if(peaks[start]) sum--;
                if(peaks[start+k-2]) sum++;
                if(sum > max){
                    max = sum;
                    maxpos = start;
                }
                //System.out.println(sum+" "+start);
            }

            System.out.printf("%d %d\n", max+1, maxpos+1);
        }
    }

    public static boolean okcheck(){
        return true;
    }
}
