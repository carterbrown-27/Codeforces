package id_638;

import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            char[] s = in.readLine().toCharArray();
            ArrayList<Character> sorted = new ArrayList<>();
            for(char c: s){
                sorted.add(c);
            }
            Collections.sort(sorted);

            if(k == 1){
                System.out.println(sorted.stream().map(Object::toString).collect(Collectors.joining("")));
                continue;
            }

            if(sorted.get(k-1) != sorted.get(0)){
                System.out.println(sorted.get(k-1));
                continue;
            }

            StringBuilder sb = new StringBuilder();
            sb.append(sorted.get(0));
            int tiedGroups = 0;
            for(int i = 0; i < k; i++){
                if(sorted.get(i) == sorted.get(0)){
                    tiedGroups++;
                }
            }

            // wrong.
            if(k + tiedGroups == n){
                boolean works = true;
                for(int i = k; i < n; i++){
                    if(sorted.get(i) != sorted.get(k)){
                        works = false;
                    }
                }
                if(works && k < n){
                    sb.append(sorted.get(k));
                }
            }else if(k<n){
                if(sorted.get(k) != sorted.get(sorted.size()-1)){
                    for(int i = k; i < n; i++){
                        sb.append(sorted.get(i));
                    }
                }else{
                    for(int i = k; i < n; i+=tiedGroups){
                        sb.append(sorted.get(i));
                    }
                }
            }


            // now real stuff
            //System.out.println("real case");
            System.out.println(sb);
        }
    }

    public static boolean okcheck(){
        return true;
    }
}
