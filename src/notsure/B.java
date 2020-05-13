package notsure;

import java.io.*;
import java.util.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int n = Integer.parseInt(in.readLine());
            StringTokenizer sta = new StringTokenizer(in.readLine());
            StringTokenizer stb = new StringTokenizer(in.readLine());

            boolean negativeOne = false;
            boolean positiveOne = false;

            boolean works = true;
            for(int i = 0; i < n; i++){
                int a = Integer.parseInt(sta.nextToken());
                int b = Integer.parseInt(stb.nextToken());

                if((a>b && !negativeOne) || (a<b && !positiveOne)){
                    works = false;
                    break;
                }

                negativeOne = negativeOne || (a==-1);
                positiveOne = positiveOne || (a==1);
            }

            System.out.println(works ? "YES" : "NO");
        }
    }

    public static boolean okcheck(){
        return true;
    }
}
