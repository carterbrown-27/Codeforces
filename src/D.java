import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class D {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int points = 0;
        ArrayList<Integer> turnsNeeded = new ArrayList<>();
        st = new StringTokenizer(in.readLine());
        for (int i = 0; i < n; i++) {
            int h = Integer.parseInt(st.nextToken());
            int left = h % (a+b);
            if(left == 0) {
                int val = (int) Math.ceil((double) b / a);
                if (val <= k) turnsNeeded.add(val);
            }else {
                if (a >= left) {
                    points++; // avoids adding to list
                    continue;
                }
                int val = (int) Math.ceil((double) left / a) - 1;
                if (val <= k) turnsNeeded.add(val);
            }
        }

        Collections.sort(turnsNeeded);
        //System.out.println(turnsNeeded.toString());
        for (int i = 0; i < turnsNeeded.size() && k > 0; i++) {
            k -= turnsNeeded.get(i);
            if(k>=0) points++;
        }

        System.out.println(points);
    }
    public static boolean okcheck(int[] a){
        return true;
    }
}
