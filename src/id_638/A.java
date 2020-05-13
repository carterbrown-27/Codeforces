package id_638;

import java.io.*;
import java.util.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int n = Integer.parseInt(in.readLine());
            long total = 0;
            long group1 = 0;
            for(int i = 1; i <= n; i++){
                total += Math.pow(2,i);
                if(i < n/2 || i == n) group1 += Math.pow(2,i);
            }

            System.out.println(2*group1-total);
        }
    }

    public static boolean okcheck(){
        return true;
    }
}
