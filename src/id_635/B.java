package id_635;

import java.io.*;
import java.util.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int x = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            for(int i = 0; i < n && x/2 + 10 <= x; i++){
                x /= 2;
                x += 10;
            }
            for(int j = 0; j < m; j++){
                x -= 10;
                if(x<=0){
                    break;
                }
            }

            System.out.println((x <= 0) ? "YES" : "NO");
        }
    }
}
