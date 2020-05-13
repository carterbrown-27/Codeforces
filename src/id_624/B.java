package id_624;

import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            ArrayList<Integer> a = new ArrayList<>(n);
            Set<Integer> p = new HashSet<>(m);

            st = new StringTokenizer(in.readLine());
            for(int i = 0; i < n; i++){
               a.add(Integer.parseInt(st.nextToken()));
            }

            st = new StringTokenizer(in.readLine());
            for(int i = 0; i < m; i++){
                p.add(Integer.parseInt(st.nextToken()));
            }

            ArrayList<Integer> sorted = new ArrayList<>(a);
            Collections.sort(sorted);

            boolean works = true;

            for(int x = 0; works && x < n; x++){
                if(sorted.get(x) == a.get(x)) continue;

                for(int j = x; j < n; j++){
                    // swap
                    if(sorted.get(x) == a.get(j)){
                        int val = a.get(j);
                        a.set(j, a.get(x));
                        a.set(x, val);
                        break;
                    }else if(!p.contains(j+1)){
                        works = false;
                        // System.out.println(sorted.get(x));
                        break;
                    }
                }
            }

            System.out.println(works ? "YES" : "NO");
        }
    }

    public static int solve(){
        return 0;
    }
}
