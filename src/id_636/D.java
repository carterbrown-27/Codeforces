package id_636;

import java.awt.*;
import java.io.*;
import java.util.*;

public class D {
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

            int[] costs = new int[2*k + 1];
            for(int i = 0; i < n/2; i++){
                int b = a[n-i-1];
                int sum = a[i] + b;
                int min = sum + 1 - Math.max(a[i],b);
                int max = sum + k - Math.min(a[i],b);
            }
        }
    }

}
