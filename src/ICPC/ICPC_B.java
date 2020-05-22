package ICPC;

import java.awt.*;
import java.io.*;
import java.util.*;

public class ICPC_B {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int X = Integer.parseInt(st.nextToken());
        int Y = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());
        Point A = new Point(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
        Point B = new Point(Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));

        Random rng = new Random();
        final int PREC = 100000000;
        int intersect = 0;

        // generates a close approximation. not precise enough for many cases... correct implementation likely uses many cases & integration
        int x_side = Math.abs(B.x-A.x);
        int x_min  = Math.min(A.x,B.x);
        int y_side = Math.abs(B.y-A.y);
        int y_min  = Math.min(A.y,B.y);
        int r_sq   = R*R;

        for(int i = 0; i < PREC; i++){
            double x = rng.nextDouble()*x_side + x_min - X;
            double y = rng.nextDouble()*y_side + y_min  - Y;

            if(x*x + y*y <= r_sq){
                intersect++;
            }
        }

        int rect_area = Math.abs(B.x-A.x)*Math.abs(B.y-A.y);
        double ans = (double) intersect / PREC * rect_area;

        System.out.println(ans);
    }
}
