package id_637;

import java.io.*;
import java.util.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());

            int min = n * (a-b);
            int max = n * (a+b);

            if((min >= c-d && min <= c+d) || (max >= c-d && max <= c+d) || (min <= c-d && max >= c+d)){
                System.out.println("Yes");
            }else{
                System.out.println("No");
            }
        }
    }

    public static boolean okcheck(){
        return true;
    }
}
