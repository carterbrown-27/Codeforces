package id_629;

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

            int j = 0;
            int i = 1;
            for(; i <= k; i+=j){
                j++;
            }
            // System.out.println(-j+" "+(i-j));
            int firstB = n-j-1;
            int secondB = n-(k-(i-j))-1;

            StringBuilder sb = new StringBuilder();
            for(int x = 0; x < n; x++){
                if(x == firstB || x == secondB){
                    sb.append('b');
                }else{
                    sb.append('a');
                }
            }

            System.out.println(sb);
        }
    }
}
