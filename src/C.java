import java.io.*;
import java.util.*;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int n = Integer.parseInt(in.readLine());
            HashSet<Integer> ppl = new HashSet<>();
            StringTokenizer st = new StringTokenizer(in.readLine());
            boolean works = true;
            for(int i = 0; i < n; i++){
                int shift = Integer.parseInt(st.nextToken());
                int pos = (((i + shift)%n)+n)%n; // modulus
                if(ppl.contains(pos)){
                    works = false;
                    break;
                }else{
                    ppl.add(pos);
                }
            }

            System.out.println(works ? "YES" : "NO");
        }
    }

    public static boolean okcheck(int[] a){
        return true;
    }
}
