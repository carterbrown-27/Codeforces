package id_631;

import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(in.readLine());
        int[] l = new int[m];
        long sum = 0;
        for(int i = 0; i < m; i++){
            l[i] = Integer.parseInt(st.nextToken());
            sum += l[i];
        }

        if(sum < n){
            System.out.println("-1");
            return;
        }

        int end = 0;
        long overlapGoal = sum - n;
        ArrayList<Integer> ps = new ArrayList<>();
        for(int start = 0; start < m; start++){
            int o = (int) Math.min(overlapGoal, end-start); // safe int conversion from min
            overlapGoal -= o;
            int p = end - o;
            end = p + l[start];
            if(end > n){
                break;
            }else{
                ps.add(p);
                if(ps.size() == m) break;
            }
        }

        // sanity check
        if(ps.size() == m){
            System.out.println(ps.stream().map(x->Integer.valueOf(x+1).toString()).collect(Collectors.joining(" ")));
        }else{
            System.out.println("-1");
        }
    }

    public static boolean okcheck(){
        return true;
    }
}
