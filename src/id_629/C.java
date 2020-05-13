package id_629;

import java.io.*;
import java.util.*;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int n = Integer.parseInt(in.readLine());
            String s = in.readLine();
            int firstOne = s.indexOf('1');
            String a;
            String b;
            if(firstOne != -1){
                String firstHalf = s.substring(0,firstOne).replaceAll("2","1");
                String secondHalf = s.substring(firstOne);

                String a_secondHalf = secondHalf
                        .replaceAll("2","0")
                        .replaceAll("1", "0")
                        .replaceFirst("0","1");

                String b_secondHalf = secondHalf.replaceFirst("1","0");

                a = firstHalf + a_secondHalf;
                b = firstHalf + b_secondHalf;
            }else{
                a = b = s.replaceAll("2","1");
            }

            System.out.println(a);
            System.out.println(b);
        }
    }
}
