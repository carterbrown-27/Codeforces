package ICPC;

import java.io.*;
import java.util.*;

public class ICPC_C {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(in.readLine());
        int[][] grid = new int[N][2];
        for(int i = 0; i < M; i++){
            grid[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())] = Integer.parseInt(st.nextToken());
        }

        int[] max = new int[3];
        int[] min = new int[3];
        int[] must = new int[3];
        Arrays.fill(must,-1);
        int wild = 0;
        for(int i = 0; i < N; i++){
            if(grid[i][0] != 0 && grid[i][1] != 0){
                must[i%3] = grid[i][0] + grid[i][1];
            }else if(grid[i][0] == 0 && grid[i][1] == 0){
                wild++;
            }else{
                min[i%3] = Math.min(min[i%3], Math.min(grid[i][0],grid[i][1]));
                max[i%3] = Math.max(max[i%3], Math.max(grid[i][0],grid[i][1]) + 9);
            }
        }

        long ways = 0;
        // combinatorics etc. (with first sixpack, rest are just *= 1 or *=(#vals) for wilds)
    }
}
