package id_624;

import java.io.*;
import java.util.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            int ans = -1;
            if(a==b){
                ans = 0;
            }else if(a<b){
                ans = (b-a) % 2 == 1 ? 1 : 2;
            }else{
                ans = (a-b) % 2 == 0 ? 1 : 2;
            }

            System.out.println(ans);
        }
    }

    public static int solve(){
        return 0;
    }
}
