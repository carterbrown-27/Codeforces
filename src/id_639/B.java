package id_639;

import java.io.*;
import java.util.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        ArrayList<Integer> cards = new ArrayList<>();
        int total = 0;
        int h = 0;
        while(total <= 1000000000) {
            h++;
            total += 3 * h - 1;
            cards.add(total);
        }

        for(int t = 0; t < T; t++){
            int n = Integer.parseInt(in.readLine());
            int c = 0;
            while(n>=2){
                int pos = Collections.binarySearch(cards, n);
                if(pos<0) {
                    pos *= -1;
                    pos -= 2;
                }
                //System.out.println(cards[pos]);
                n-=cards.get(pos);
                //System.out.println(n);
                c++;
            }
            System.out.println(c);
        }
    }
}
