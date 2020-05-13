package id_638;

import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.Collectors;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            st = new StringTokenizer(in.readLine());
            int[] m = new int[n];
            for(int i = 0; i < n; i++){
                m[i] = Integer.parseInt(st.nextToken());
            }

            boolean works = true;
            ArrayList<Integer> sol = new ArrayList<>();
            ArrayList<Integer> period = new ArrayList<>(k);
            for(int i = 0; i < n; i++){
                if(!period.contains(m[i])){
                    if(period.size() < k){
                        period.add(m[i]);
                    }else{
                        works = false;
                        break;
                    }
                }
            }

            int last = period.get(period.size()-1);
            while(period.size()<k){
                period.add(last);
            }

            for(int i = 0; i < n; i++){
                sol.addAll(period);
            }

//            boolean works = true;
//            int lastPos = 0;
//            for(int i = k; i < n; i++){
//                if(!period.contains(m[i])){
//                    works = false;
//                    break;
//                }
//
//                while(m[i] != period.get(lastPos)){
//                    sol.add(period.get(lastPos));
//                    lastPos++;
//                }
//
//                sol.add(period.get(lastPos));
//                lastPos++;
//                lastPos%=k;
//            }


            if(!works){
                System.out.println("-1");
            }else{
                System.out.println(sol.size());
                System.out.println(sol.stream().map(x->x.toString()).collect(Collectors.joining(" ")));
            }
        }
    }

    public static boolean okcheck(){
        return true;
    }
}
