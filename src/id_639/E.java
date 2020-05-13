package id_639;

import java.io.*;
import java.util.*;

public class E {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        boolean[] used = new boolean[n+1];
        boolean[] lessThanAll = new boolean[n+1];
        for(int i = 0; i < m; i++){
            st = new StringTokenizer(in.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());

            lessThanAll[x1] = !(used[x1] && !lessThanAll[x1]);
            lessThanAll[x2] = false;

            used[x1] = true;
            used[x2] = true;
        }

        StringBuilder sb = new StringBuilder();
        int ac = 0;
        for(int i = 1; i < n+1; i++){
            if(used[i] && lessThanAll[i]){
                sb.append("A");
                ac++;
            }else{
                sb.append("E");
            }
        }
        if(ac > 0){
            System.out.println(ac);
            System.out.println(sb);
        }else{
            System.out.println(-1);
        }
    }

    public static boolean okcheck(int[] a){
        return true;
    }
}
