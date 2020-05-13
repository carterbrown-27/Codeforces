package id_627;

import java.io.*;
import java.util.*;

public class D {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        int[] net = new int[n];
        StringTokenizer sta = new StringTokenizer(in.readLine());
        StringTokenizer stb = new StringTokenizer(in.readLine());

        for(int i = 0; i < n; i++){
            net[i] = Integer.parseInt(sta.nextToken()) - Integer.parseInt(stb.nextToken());
        }

        ArrayList<Integer> good = new ArrayList<>();
        ArrayList<Integer> bad = new ArrayList<>();
        for(int i = 0; i < n; i++){
            if(net[i] > 0){
                good.add(net[i]);
            }else{
                bad.add(net[i]);
            }
        }

        Collections.sort(good);
        Collections.sort(bad,Collections.reverseOrder());

        long count = 0;

        // good with every other good = good (for future ref. mistake made here was not casting size to long)
        count += ((long) (good.size()-1) * good.size()) / 2; // (sigma to size-1)

        // good in increasing order means that every next good has at minimum b, plus any more it can add.
        int b = 0;
        for(Integer a: good){
            while(b < bad.size() && a + bad.get(b) > 0){
                b++;
            }
            count+=b;
        }

        System.out.println(count);
    }
}
