package id_636;

import java.io.*;
import java.util.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int n = Integer.parseInt(in.readLine());
            int divis = 3;
            int c = 2;
            while(true){
                if(n%divis==0){
                    System.out.println(n/divis);
                    break;
                }else{
                    divis += Math.pow(2,c);
                    c++;
                }
            }
        }
    }

    public static int solve(){
        return 0;
    }
}
