package ICPC;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;

public class STU18_D {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        // all configurations
        String[][] dice = {
                {":::",":o:",":::"},
                {"o::",":::","::o"},
                {"::o",":::","o::"},
                {"o::",":o:","::o"},
                {"::o",":o:","o::"},
                {"o:o",":::","o:o"},
                {"o:o",":o:","o:o"},
                {"ooo",":::","ooo"},
                {"o:o","o:o","o:o"}
        };

        int[] diceN = {1,2,2,3,3,4,5,6,6};

        String[] die = new String[3];
        for(int i = 0; i < 3; i++){
            die[i] = in.readLine();
        }

        for(int i = 0; i < dice.length; i++){
            if(Arrays.deepEquals(die,dice[i]) /* || rotateEquals(die,dice[i]) */){
                System.out.println(diceN[i]);
                return;
            }
        }

        System.out.println("unknown");
    }

    // did this to show a cleaner & more reliable solution
    public static boolean rotateEquals(String[] a, String[] b){
        String[] c = new String[3];
        for(int i = 0; i < 3; i++){
            String t = ""; // String here over SB, because len is very small
            for(int j = 2; j >= 0; j--){
                t += b[j].charAt(i);
            }
            c[i] = t;
        }

        return Arrays.deepEquals(a,c);
    }
}
