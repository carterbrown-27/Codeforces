package notsure;

import java.io.*;
import java.util.*;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        StringTokenizer st = new StringTokenizer(in.readLine());

        long ans = 0;
        long sum = 0;
        int pos = 0;
        HashMap<Long,Integer> map = new HashMap<>();

        map.put((long) 0, 1);
        for(int i = 1; i <= n; i++) {
            int a = Integer.parseInt(st.nextToken());
            sum += a;
            pos = Math.max(pos, map.getOrDefault(sum,0));
            map.put(sum, i+1);
            ans += (i-pos);
        }

        System.out.println(ans);
    }

    public static boolean okcheck(){
        return true;
    }
}
