package id_624;

import java.io.*;
import java.util.*;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());

            char[] s = in.readLine().toCharArray();
            int[][] counts = new int[n+1][26];
            for(int i = 1; i <= s.length; i++){
                System.arraycopy(counts[i-1],0,counts[i],0,26);
                counts[i][s[i-1]-'a']++;
            }

            int[] ans = new int[26];
            st = new StringTokenizer(in.readLine());
            for(int i = 0; i < m; i++){
                int[] c = counts[Integer.parseInt(st.nextToken())];
                for(int x = 0; x < 26; x++){
                    ans[x] += c[x];
                }
            }

            for(int x = 0; x < 26; x++){
                ans[x] += counts[n][x];
            }

            StringBuilder sb = new StringBuilder();
            for(int x = 0; x < 26; x++){
                sb.append(ans[x] +  " ");
            }
            System.out.println(sb);
        }
    }

    public static int solve(){
        return 0;
    }
}
