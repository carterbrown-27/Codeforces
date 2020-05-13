package id_624;

import java.io.*;
import java.util.*;

public class D {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for (int t = 0; t < T; t++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());

            int res = Integer.MAX_VALUE;
            int[] best = new int[3];
            for(int a = 1; a <= C; a++){
                for(int k = 1; a*k <= C*2; k++){
                    int b = a*k;
                    int cost = Math.abs(A-a) + Math.abs(B-b);
                    if(cost > res) continue;
                    for(int j = 1; b*j <= C*2; j++){
                        int c = b*j;
                        int ccost = cost + Math.abs(C-c);
                        if(ccost < res){
                            res = ccost;
                            best = new int[] {a,b,c};
                        }
                    }
                }
            }

            System.out.println(res);
            System.out.printf("%d %d %d\n", best[0], best[1], best[2]);
        }
    }
}
