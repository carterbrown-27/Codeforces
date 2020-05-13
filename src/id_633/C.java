package id_633;

import java.io.*;
import java.util.*;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int n = Integer.parseInt(in.readLine());

            int max = Integer.MIN_VALUE;
            int maxdiff = 0;
            StringTokenizer st = new StringTokenizer(in.readLine());
            for(int i = 0; i < n; i++){
                int val = Integer.parseInt(st.nextToken());
                max = Math.max(max,val);
                if(val < max) maxdiff = Math.max(maxdiff, max-val);
            }

            int ans = Math.max((int) (Math.log(maxdiff) / Math.log(2)), -1) + 1;
            System.out.println(ans);
        }
    }
}
