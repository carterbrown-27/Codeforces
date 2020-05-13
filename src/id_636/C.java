package id_636;

import java.awt.*;
import java.io.*;
import java.util.*;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int n = Integer.parseInt(in.readLine());
            StringTokenizer st = new StringTokenizer(in.readLine());
            int[] a = new int[n];
            for(int i = 0; i < n; i++){
                a[i] = Integer.parseInt(st.nextToken());
            }

            long sum = 0;
            int cand = a[0];
            for(int i = 1; i < n; i++){
                if(a[i] > 0 != cand > 0){
                    // different sign, add candidate to subsequence
                    sum += cand;
                    cand = a[i];
                }else{
                    // same sign, continue to choose biggest
                    cand = Math.max(cand, a[i]);
                }
            }

            sum+=cand;
            System.out.println(sum);
        }
    }
}
