package cf_654;

import java.io.*;
import java.util.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            String ans = solve(n,a,b);
            System.out.println(ans);
        }
    }

    public static String solve(int n, int a, int b){
        StringBuilder result = new StringBuilder();
        String pattern = "abcdefghijklmnopqrstuvwxyz".substring(0,b);

        while(result.length()<n){
            result.append(pattern);
        }
        return result.substring(0,n);
    }
}
