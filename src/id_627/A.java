package id_627;

import java.io.*;
import java.util.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int n = Integer.parseInt(in.readLine());
            StringTokenizer st = new StringTokenizer(in.readLine());
            int fmod = Integer.parseInt(st.nextToken()) % 2;
            boolean works = true;
            for(int x = 1; x < n; x++){
                if(Integer.parseInt(st.nextToken()) % 2 != fmod){
                    works = false;
                    break;
                }
            }
            System.out.println(works ? "YES" : "NO");
        }
        in.close();
    }
}
