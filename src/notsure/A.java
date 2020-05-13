package notsure;

import java.io.*;
import java.util.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            for(int x = 0; x < n; x++){
                StringBuilder sb = new StringBuilder();
                for(int y = 0; y < m; y++){
                    sb.append((x==0 && y==0) ? "W" : "B");
                }
                System.out.println(sb);
            }
        }
    }

    public static boolean okcheck(){
        return true;
    }
}
