package id_631;

import java.awt.*;
import java.io.*;
import java.util.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int n = Integer.parseInt(in.readLine());
            StringTokenizer st = new StringTokenizer(in.readLine());

            int[] a = new int[n];
            for(int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(st.nextToken());
            }

            boolean[] works = new boolean[n];
            HashSet<Integer> uniques = new HashSet<>();
            int max = 0;

            for(int i = 0; i < n; i++){
                if(uniques.contains(a[i])){
                    break; // duplicate in range
                }else{
                    uniques.add(a[i]);
                }
                max = Math.max(max, a[i]);

                if(i < n-1 && uniques.size() == max){
                    works[i+1] = true;
                }
            }

            uniques.clear();
            max = 0;
            ArrayList<Integer> valids = new ArrayList<>();
            for(int i = n-1; i >= 0; i--){
                if(uniques.contains(a[i])){
                    break; // duplicate in range
                }else{
                    uniques.add(a[i]);
                }
                max = Math.max(max, a[i]);

                if(uniques.size() == max && works[i]){
                    valids.add(i);
                }
            }

            System.out.println(valids.size());
            for(int i: valids){
                System.out.println(i+" "+(n-i));
            }
        }
    }

    public static boolean okcheck(){
        return true;
    }
}
