package notsure3;

import java.io.*;
import java.util.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int n = Integer.parseInt(in.readLine());
            ArrayList<Integer> a = new ArrayList<>(n);
            StringTokenizer st = new StringTokenizer(in.readLine());
            for(int i = 0; i < n; i++){
                a.add(Integer.parseInt(st.nextToken()));
            }

            Collections.sort(a, Collections.reverseOrder());

            System.out.println(a.stream().map(Object::toString).collect(Collectors.joining(" ")));
        }
    }

    public static boolean okcheck(int[] a){
        return true;
    }
}
