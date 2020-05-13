package cf_654;

import java.io.*;
import java.util.*;

public class E {
    // incomplete
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int n = Integer.parseInt(in.readLine());

            int[] a = new int[n];
            StringTokenizer st = new StringTokenizer(in.readLine());

            for(int i = 0; i < n; i++) {

                int x = Integer.parseInt(st.nextToken());
                a[i] = x;
            }

            // starting points
            for(int s = 0; s < n; s++){

            }
        }
    }

    public static int getScore(int[] a, int s){
        int b = a[s];
        // moves left][moves right
        int[][] dp = new int[a.length-1][a.length-1];
        dp[0][0] = 1;
        for(int l = 0; s-l >= 0; l++){
            for(int r = 0; s+r < a.length; r++){
                // if valid
                int prev = Math.max(dp[l][r-1],dp[l-1][r-1]);
            }
        }
        return 0;
    }

    public static int getBreadScore(int[] a, int s, int e){
        return 0;
    }
}