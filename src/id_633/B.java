package id_633;

import java.io.*;
import java.util.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int n = Integer.parseInt(in.readLine());
            ArrayList<Integer> a = new ArrayList<>(n);
            StringTokenizer st = new StringTokenizer(in.readLine());
            for(int i = 0; i < n; i++){
                a.add(Integer.parseInt(st.nextToken()));
            }
            Collections.sort(a);
            ArrayList<Integer> sol = new ArrayList<>(n);

            int mid = n/2;
            sol.add(a.get(mid));

            for(int d = 1; d <= n/2; d++){
                if(mid-d >= 0){
                    sol.add(a.get(mid-d));
                }
                if(mid+d < a.size()){
                    sol.add(a.get(mid+d));
                }
            }

            String str = sol.toString();
            System.out.println(str.substring(1,str.length()-1).replaceAll(",",""));
        }
    }
}
