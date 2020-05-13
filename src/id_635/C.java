package id_635;

import java.io.*;
import java.util.*;

public class C {
    public static class Pair {
        long x;
        long y;
        Pair(long _x, long _y){
            x = _x;
            y = _y;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        HashMap<Integer,Set<Integer>> adj = new HashMap<>();
        for(int i = 0; i < n-1; i++){
            // System.out.println(i);
            st = new StringTokenizer(in.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            if(adj.get(u) == null){
                adj.put(u, new HashSet<>());
            }

            if(adj.get(v) == null){
                adj.put(v, new HashSet<>());
            }

            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        in.close();

        sp = new Pair[n+1];
        calc(1,adj, new HashSet<>());

        ArrayList<Pair> sl = new ArrayList<>();
        for(int x = 1; x < sp.length; x++){
            sl.add(sp[x]);
        }

        Collections.sort(sl, (Pair a, Pair b) -> {
            return Long.valueOf(b.y - b.x).compareTo(a.y - a.x);
        });

        long ans = 0;
        for(int i = 0; i < k; i++){
            // System.out.println(pl.get(i));
            ans += sl.get(i).y - sl.get(i).x;
        }

        System.out.println(ans);
    }

    public static Pair[] sp;
    public static void calc(int curr, HashMap<Integer,Set<Integer>> adj, Set<Integer> path){
        path.add(curr);
        long ans = 1;
        for(int i: adj.get(curr)){
            if(path.contains(i)) continue;
            if(sp[i] == null) calc(i, adj, path);
            ans += sp[i].x;
        }
        sp[curr] = new Pair(ans,(long) path.size());
        path.remove(curr);
    }

}
