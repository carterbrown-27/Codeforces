package ehab;

import java.io.*;
import java.util.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int x = Integer.parseInt(in.readLine());
            System.out.printf("%d %d\n", 1, x-1);
        }
    }
}