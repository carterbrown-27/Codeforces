package id_637;

import java.io.*;
import java.util.*;

public class E {
    public static class Quartet {
        int a;
        long time;
        int i;
        int leftover;

        Quartet(int a, long time, int i, int leftover){
            this.a = a;
            this.time = time;
            this.i = i;
            this.leftover = leftover;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(in.readLine());
        ArrayList<Integer> d = new ArrayList<>(m);
        for (int i = 0; i < m; i++) {
            d.add(Integer.parseInt(st.nextToken()));
        }

        st = new StringTokenizer(in.readLine());
        int g = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());

        Collections.sort(d);

        Queue<Quartet> q = new LinkedList<>();
        q.add(new Quartet(0, 0, 0,g));

        // dont do for every a, BFS.
        long ans = -1;
        while (!q.isEmpty()) {
            Quartet curr = q.poll();
            int a = curr.a;
            long time = curr.time;
            if (a == n) {
                ans = time;
                break;
            }
            int index = curr.i;
            int leftover = curr.leftover;
            // System.out.println(curr.a+" "+time);
            for (int j = index + 1; j < d.size(); j++) {
                int b = d.get(j);
                if (b > a + leftover) break;
                if(b == n){
                    q.add(new Quartet(b, time+(b-a), j,g));
                }else{
                    for (int k = index + 1; k <= j; k++) {
                        int c = d.get(k);
                        if (b - a + b - c < leftover) {
                            q.add(new Quartet(c, time + g, k, g-(b-a + b-c)));
                        }else if (b - a + b - c == leftover){
                            q.add(new Quartet(c, time + g + r, k, g));
                        }
                    }
                }
            }
        }

        System.out.println(ans);
    }

    public static boolean okcheck(){
        return true;
    }
}
