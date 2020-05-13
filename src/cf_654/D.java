package cf_654;

import java.io.*;
import java.util.*;

public class D {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int[][] board = new int[9][9];

            ArrayList<Set<Integer>> rows = new ArrayList<>();
            ArrayList<Set<Integer>> cols = new ArrayList<>();
            ArrayList<ArrayList<Set<Integer>>> boxes = new ArrayList<>();

            for(int y = 0; y < 9; y++){
                String[] str = in.readLine().split("");
                rows.add(y, new HashSet<>());
                for(int x = 0; x < 9; x++){
                    int val = Integer.parseInt(str[x]);
                    board[y][x] = val;

                    // add to row
                    rows.get(y).add(val);

                    // add to col
                    if(x >= cols.size() || cols.get(x) == null) cols.add(x, new HashSet<>());
                    cols.get(x).add(val);

                    // add to box
                    int boxy = y/3;
                    int boxx = x/3;
                    if(boxy >= boxes.size() || boxes.get(boxy) == null) boxes.add(boxy, new ArrayList<>());
                    if(boxx >= boxes.get(boxy).size() || boxes.get(boxy).get(boxx) == null) boxes.get(boxy).add(boxx, new HashSet<>());
                    boxes.get(boxy).get(boxx).add(val);
                }
            }

            for(int boxy = 0; boxy < 3; boxy++){
                for(int boxx = 0; boxx < 3; boxx++){
                    int x = boxx*3+boxy;
                    int y = boxy*3+boxx;

                    for(int newn = 1; newn <=9; newn++){
                        if(board[y][x] == newn) continue;
                        if(rows.get(y).contains(newn) && cols.get(x).contains(newn) && boxes.get(boxy).get(boxx).contains(newn)){
                            board[y][x] = newn;
                            break;
                        }
                    }
                }
            }

            for(int y = 0; y < 9; y++){
                StringBuilder sb = new StringBuilder();
                for(int x = 0; x < 9; x++){
                    sb.append(board[y][x]);
                }
                System.out.println(sb.toString());
            }
        }
    }
}
