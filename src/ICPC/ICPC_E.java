package ICPC;

import java.io.*;
import java.nio.file.NotLinkException;
import java.util.*;

public class ICPC_E {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(in.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(in.readLine());

        // 4MB
        ArrayList<Integer> arr = new ArrayList<>(N);
        for(int i = 0; i < N; i++){
            int val = Integer.parseInt(st.nextToken());
            arr.add(val);
        }

        Collections.sort(arr);

        // not correct
        // int a = calc(arr, N, K);
        // System.out.println(f(arr,a,K));

        // correct iff. N is even or middle value is "correct" (I believe, as 3 2 | 2 5 6  = 1, while this outputs 0).
        long ans = 0;
        for(int i = 0; i < N/2; i++){
            int first = arr.get(i);
            int second = arr.get(N-i-1);
            ans += Math.abs(second-first-((N-(2*i)-1)*K));
        }

        System.out.println(ans);

        // super close
        if(N%2==1){
//            int v = arr.get(0) + arr.get(N-1);
//            int u = v - ((arr.get(0) + arr.get(N-1))%K * (v>0 ? 1 : -1));
//            ans += Math.abs(a.get(N/2) - u/2 - u%2);
            int l = arr.get(N/2 - 1);
            int r = arr.get(N/2 + 1);
            // 3 options, move to l + K, move to r - K, or stay.
        }

    }

//    public static int calc(ArrayList<Integer> arr, int n, int k){
//        // ternary search? logn*2n = feasible
//        int m1 = -1000000;
//        int m2 = 1000000; // could bound at 1e6
//        while(true){
//            // System.out.println(m1+" "+m2);
//            if(m2-m1<=2){
//                return (m1+m2)/2;
//            }
//            int lt = m1 + (m2 - m1) / 3;
//            int rt = m2 - (m2 - m1) / 3;
//            if(f(arr,lt,k) >= f(arr,rt,k)){
//                m1 = lt;
//            }else{
//                m2 = rt;
//            }
//        }
//    }
//
//    public static long f(ArrayList<Integer> arr, int a, int k){
//        long sum = 0;
//        for(int i: arr){
//            sum+=Math.abs(i-a);
//            a+=k;
//        }
//        return sum;
//    }
}
