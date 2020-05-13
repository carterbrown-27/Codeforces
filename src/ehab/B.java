package ehab;

import java.io.*;
import java.util.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int n = Integer.parseInt(in.readLine());

            Set<Integer> uniques = new HashSet<>();
            StringTokenizer st = new StringTokenizer(in.readLine());

            for(int i = 0; i < n; i++){
                uniques.add(Integer.parseInt(st.nextToken()));
            }

            System.out.println(uniques.size());
        }
    }

    public static int solve(){
        return 0;
    }
}