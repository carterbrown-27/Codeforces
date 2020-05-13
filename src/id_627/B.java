package id_627;

import java.io.*;
import java.util.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int n = Integer.parseInt(in.readLine());
            HashSet<Integer> seen = new HashSet<>();
            StringTokenizer st = new StringTokenizer(in.readLine());
            int[] seq = new int[n];
            boolean works = false;
            for(int x = 0; x < n; x++){
                int val = Integer.parseInt(st.nextToken());
                seq[x] = val;
                if(seen.contains(val)){
                    works = true;
                    break;
                }
                if(x>=1) seen.add(seq[x-1]);
            }

            System.out.println(works ? "YES" : "NO");
        }
    }
}
