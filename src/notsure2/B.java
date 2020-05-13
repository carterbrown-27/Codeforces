package notsure2;

import java.io.*;
import java.util.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int n = Integer.parseInt(in.readLine());
            int[] a = new int[n+1];
            StringTokenizer st = new StringTokenizer(in.readLine());
            for(int i = 0; i < n; i++){
                a[i] = Integer.parseInt(st.nextToken());
            }

            int max = 0;
            int min = 1000000001;
            int maxAdjDiff = 0;
            for(int i = 0; i < n; i++){
                if(a[i] != -1){
                    if(i >= 1 && a[i-1] != -1){
                        maxAdjDiff = Math.max(maxAdjDiff, Math.abs(a[i]-a[i-1]));
                    }

                    if((i >= 1 && a[i-1] == -1) || a[i+1] == -1){
                        max = Math.max(max, a[i]);
                        min = Math.min(min, a[i]);
                    }
                }
            }

            System.out.print(Math.max(maxAdjDiff,((max-min+1)/2)));
            System.out.println(" "+(max+min)/2);
        }
    }

    public static boolean okcheck(int[] a){
        return true;
    }
}
