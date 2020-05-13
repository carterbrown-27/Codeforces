package notsure3;

import java.io.*;
import java.util.*;

public class D {

    public static long MOD = 998244353;

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            if(n==2){
                System.out.println(m);
                continue;
            }

            long center = sum(m-1);
            long total = 0;
            int mm3 = m-3;
            long[] chooseKs = new long[mm3];
            chooseKs[0] = 1;
            for(int i = 1; i < mm3; i++){
                // some choose k, but that num is way large.
            }
        }
    }



    public static int sum(int i){
        return i*(i+1)/2;
    }
}
