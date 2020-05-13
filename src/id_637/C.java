package id_637;

import javax.print.DocFlavor;
import java.io.*;
import java.util.*;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int n = Integer.parseInt(in.readLine());
            StringTokenizer st = new StringTokenizer(in.readLine());

            int[] ppos = new int[n+1];
            ppos[0] = -1;
            for(int i = 0; i < n; i++){
                ppos[Integer.parseInt(st.nextToken())] = i;
            }

            // System.out.println(Arrays.toString(ppos));

            int[] count = new int[n];
            Arrays.fill(count,1);
            int max = 1;

            boolean flag = true;
            for(int i = 1; i <= n; i++){
                int pos = ppos[i];
                if(count[pos] == max){
                    if(pos < n-1){
                        for(int j = pos+1; j < n; j++){
                            if(count[j] > 0){
                                count[j]+=count[pos];
                                max = Math.max(max, count[j]);
                                //System.out.println(max);
                                break;
                            }else if(j == n-1){
                                max = 1;
                                //System.out.println(max);
                            }
                        }
                    }else{
                        max = 1;
                        //System.out.println(max);
                    }
                    count[pos] = 0;
                }else{
                    flag = false;
                    break;
                }

                // System.out.println("count = "+Arrays.toString(count));
            }

            System.out.println(flag ? "Yes": "No");
        }
    }

    public static boolean okcheck(){
        return true;
    }
}
