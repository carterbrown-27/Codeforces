package notsure2;

import java.io.*;
import java.util.*;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            long n = Integer.parseInt(st.nextToken());
            long m = Integer.parseInt(st.nextToken());

            if(m == 0){
                System.out.println(0);
            }else if(m==n){
                System.out.println(func(n));
            }else if(2*m - 1 >= n){
                System.out.println(func(n)-(n-m));
            }else{
                long lc = 2*m - 1;
                long lr = (n-lc)/2;
                long ll = n-lc-lr; // bigger
                long z = m-1;

                long lcSum = func(lc) - z;
                long llSum = ll*(n-ll);
                long lrSum = lc*lr;

                System.out.println(lcSum+llSum+lrSum);
            }
        }
    }

    public static long func(long i){
        return i*(i+1)/2;
    }
}
