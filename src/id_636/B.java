package id_636;

import java.io.*;
import java.util.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int n = Integer.parseInt(in.readLine());

            if((n/2)%2 != 0){
                System.out.println("NO");
                continue;
            }

            ArrayList<Integer> li = new ArrayList<>(n);
            for(int i = 1; i <= n+1; i++){
                if(i == (n/2) + 1) continue;
                li.add(i);
            }

            int[] sol = new int[n];
            int ap = 0;
            int bp = n/2;
            for(int i = 0; i < n; i++){
                int val = li.get(i);
                if(val%2==0){
                    sol[ap++] = val;
                }else{
                    sol[bp++] = val;
                }
            }

            StringBuilder sb = new StringBuilder();
            for(int i: sol){
                sb.append(i+" ");
            }

            System.out.println("YES");
            System.out.println(sb);
        }
    }

    public static int solve(){
        return 0;
    }
}
