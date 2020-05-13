package id_627;

import java.io.*;
import java.util.*;

public class E {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());
        int l = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(in.readLine());
        int[] a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }
        // [sleeps][hour]
        int[][] best = new int[n+1][h];
        for(int hr = 1; hr < h; hr++) best[0][hr] = -1;

        for(int i = 1; i <= n; i++){
            for(int hr = 0; hr < h; hr++){
                // ugly variables here because java doesn't do -x % y = y-x
                int prevhr = hr - a[i-1];
                if(prevhr < 0) prevhr += h;
                int prevhrmo = (prevhr + 1) % h;
                int prevBest = Math.max(best[i-1][prevhr],best[i-1][prevhrmo]);
                best[i][hr] = prevBest + ((prevBest >= 0 && l <= hr && hr <= r) ? 1 : 0);
            }
        }

        int max = 0;
        for(int hr = 0; hr < h; hr++){
            max = Math.max(max,best[n][hr]);
        }

        System.out.println(max);
//        for(int[] line: best){
//            System.out.println(Arrays.toString(line));
//        }
    }
}
