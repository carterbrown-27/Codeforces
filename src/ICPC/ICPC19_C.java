package ICPC;

import java.io.*;
import java.util.*;

// correct
public class ICPC19_C {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        char[][] board = new char[n][n];
        int kingX = -1, kingY = -1;
        for(int i = 0; i < n; i++){
            String s = in.readLine();
            board[i] = s.toCharArray();
            int ind = s.indexOf('K');
            if(ind != -1){
                kingX = ind;
                kingY = i;
            }
        }

        long ans = 0;
        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                if(board[y][x] == '*'){
                    if(Math.abs(kingY-y)<=1 && Math.abs(kingX-x)<=1) {
                        board[y][x] = '-';
                        continue;
                    } else if(y+1>=n || ((x-1 < 0 || board[y+1][x-1] == '*') && (x+1 >= n || board[y+1][x+1] == '*'))) {
                        // if pawn can't be attacked (i.e. next row dne or is full at diagonal positions)
                        System.out.println(-1);
                        return;
                    } else {
                        board[y][x] = '-';
                        if(x+2 < n && board[y][x+2] == '*') board[y][x+2] = '-';
                        ans++;
                    }
                }
            }
        }

        System.out.println(ans);
    }
}
