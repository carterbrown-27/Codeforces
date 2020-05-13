package id_631;

import java.io.*;
import java.util.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(in.readLine());
            boolean[] places = new boolean[201];
            for(int i = 0; i < n; i++){
                places[Integer.parseInt(st.nextToken())] = true;
            }

            int ans = 1;
            for(int i = 1; i <= 200; i++){
                if(!places[i]){
                    x--;
                    if(x>=0){
                        ans = i;
                    }else{
                        break;
                    }
                }else{
                    ans = i;
                }
            }

            System.out.println(ans);
        }
    }

    public static boolean okcheck(){
        return true;
    }
}
