import java.io.*;
import java.util.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int spent = 0;
            int n = Integer.parseInt(in.readLine());
            while(n>=10){
                int spend = n-(n%10);
                spent+=spend;
                n-=spend;
                n+=spend/10;
            }
            spent += n;
            System.out.println(spent);
        }
    }


    public static boolean okcheck(int[] a){
        return true;
    }
}
