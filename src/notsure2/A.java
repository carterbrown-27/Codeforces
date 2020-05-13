package notsure2;

import java.io.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            boolean works = true;
            String a = in.readLine();
            String b = in.readLine();
            String c = in.readLine();
            for(int i = 0; i < a.length(); i++){
                if(a.charAt(i) != c.charAt(i) && b.charAt(i) != c.charAt(i)){
                    works = false;
                    break;
                }
            }

            System.out.println(works ? "YES" : "NO");
        }
    }

    public static boolean okcheck(int[] a){
        return true;
    }
}
