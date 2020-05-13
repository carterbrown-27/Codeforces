package notsure3;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            long[] a = new long[n];
            st = new StringTokenizer(in.readLine());
            for(int i = 0; i < n; i++){
                a[i] = Long.parseLong(st.nextToken());
            }

            ArrayList<Long> is = new ArrayList<>();
            // System.out.println(Arrays.toString(a));
            for(long i: a){
                is.addAll(calc(i,k));
            }

            Collections.sort(is, Collections.reverseOrder());
            System.out.println(is.stream().map(Object::toString).collect(Collectors.joining(" ")));

            boolean works = true;
            for(int i = 1; i < is.size(); i++){
                if(is.get(i) == is.get(i-1)){
                    works = false;
                    break;
                }
            }

            System.out.println(works ? "YES" : "NO");
        }
    }

    public static ArrayList<Long> calc(long i, long k){
        ArrayList<Long> arr = new ArrayList<>();
        while(i>1){
            long log = (int) ((Math.log(i)/Math.log(k)) + 0.0000000000000001);
            // System.out.println(log);
            i -= Math.pow(k,log);
            //System.out.println(i);
            arr.add(log);
        }
        if(i==1) arr.add((long) 0);
        return arr;
    }
}
