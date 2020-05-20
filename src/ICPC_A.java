import java.awt.*;
import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class ICPC_A {
    public static abstract class Animal {
        Point p;
        int hp;

        Animal(Point p, int hp){
            this.p = p;
            this.hp = hp;
        }

        public abstract void move(int m, int n);
    }

    public static class Wolf extends Animal {
        Wolf(Point p){
            super(p,10);
        }

        public void move(int m, int n){
            p.x++;
            p.x%=n;
        }
    }

    public static class Sheep extends Animal {
        Sheep(Point p){
            super(p,5);
        }

        public void move(int m, int n){
            p.y++;
            p.y%=m;
        }
    }


    public static void main(String[] args) throws  IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int T = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        int[][] board = new int[M][N];
        Set<Sheep> sh = new HashSet<>();
        Set<Wolf> wl = new HashSet<>();

        for(int y = 0; y < M; y++){
            char[] s = in.readLine().toCharArray();
            for(int x = 0; x < N; x++){
                board[y][x] = 3;
                Point p = new Point(x,y);
                if(s[x] == 'S'){
                    sh.add(new Sheep(p));
                }else if(s[x] == 'W'){
                    wl.add(new Wolf(p));
                }
            }
        }

        for(int i = 0; i < T; i++){
            sh.forEach(s -> s.move(M,N));
            wl.forEach(w -> w.move(M,N));

            for(Wolf w: wl){
                Sheep same = null;
                for(Sheep s: sh){
                    if(w.p.equals(s.p)){
                        same = s;
                        break;
                    }
                }
                if(same != null){
                    sh.remove(same);
                    w.hp = 11;
                    board[w.p.y][w.p.x] = -1;
                }
            }

            for(Sheep s: sh){
                if(board[s.p.y][s.p.x] == 0){
                    s.hp = 6;
                    board[s.p.y][s.p.x] = 4;
                }
            }

            for(int y = 0; y < M; y++){
                for(int x = 0; x < N; x++){
                    if(board[y][x] > 0) board[y][x]--;
                }
            }

            Set<Sheep> nsh = new HashSet<>();
            Set<Wolf> nwl = new HashSet<>();
            for(Wolf w: wl){
                if(--w.hp > 0){
                    nwl.add(w);
                }else{
                    board[w.p.y][w.p.x] = -1;
                }
            }

            for(Sheep s: sh){
                if(--s.hp > 0){
                    nsh.add(s);
                }else{
                    board[s.p.y][s.p.x] = -1;
                }
            }

            sh = nsh;
            wl = nwl;
        }

        char[][] out = new char[M][N];
        for(int y = 0; y < M; y++){
            for(int x = 0; x < N; x++){
                if(board[y][x] == 0){
                    out[y][x] = '#';
                }else if(board[y][x] == -1){
                    out[y][x] = '*';
                }else{
                    out[y][x] = '.';
                }
            }
        }

        for(Wolf w: wl){
            out[w.p.y][w.p.x] = 'W';
        }

        for(Sheep s: sh){
            out[s.p.y][s.p.x] = 'S';
        }

        for(char[] s: out){
            StringBuilder sb = new StringBuilder();
            for(char c: s){
                sb.append(c);
            }
            System.out.println(sb);
        }
    }
}
