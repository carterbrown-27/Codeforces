package cf_654;

import java.io.*;
import java.util.*;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int n = Integer.parseInt(in.readLine());

            HashMap<Integer,Integer> tally = new HashMap<>();
            StringTokenizer st = new StringTokenizer(in.readLine());

            for(int i = 0; i < n; i++){
                int x = Integer.parseInt(st.nextToken());
                if(tally.containsKey(x)){
                    tally.put(x, tally.get(x)+1);
                }else{
                    tally.put(x,1);
                }
            }

            int max = 0;
            for(Integer k: tally.keySet()){
                max = Math.max(max, tally.get(k));
            }

            int distinct = tally.keySet().size();
            int ans = Math.min(distinct,max);
            if(distinct==max){
                ans-=1;
            }
            System.out.println(ans);
        }
    }
}
