package id_629;

import java.io.*;
import java.util.*;

public class D {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int x = 0; x < T; x++) {
            int n = Integer.parseInt(in.readLine());
            int[] t = new int[n];
            StringTokenizer st = new StringTokenizer(in.readLine());
            for (int i = 0; i < n; i++) {
                t[i] = Integer.parseInt(st.nextToken());
            }
            boolean allsame = true;
            for(int i = 0; i < n; i++){
                if(t[i] != t[0]){
                    allsame = false;
                    break;
                }
            }

            if (allsame) {
                System.out.println(1);
                StringBuilder sb = new StringBuilder();
                for(int i = 0; i < n; i++){
                    sb.append(1+ " ");
                }
                System.out.println(sb);
            } else {
                int[] c = new int[n];
                int start = -1;
                for (int i = 1; i <= n; i++) {
                    if (t[i % n] == t[i - 1]) {
                        start = i;
                        break;
                    }
                }

                int colours;
                if (start == -1) {
                    colours = Math.min(2+n%2, n);
                    c[0] = 1;
                    for (int i = 1; i < n; i++) {
                        c[i] = 1 + (n % 2) + i % 2;
                    }
                } else {
                    colours = 2;
                    c[start % n] = 1;
                    c[start - 1] = 1;
                    for (int i = start + 1; i <= start + n - 1; i++) {
                        c[i % n] = 1 + (i - start) % 2;
                    }
                }
                System.out.println(colours);
                StringBuilder sb = new StringBuilder();
                for (int i : c) {
                    sb.append(i + " ");
                }
                System.out.println(sb);
            }
        }
    }
}
