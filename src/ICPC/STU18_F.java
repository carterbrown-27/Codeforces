package ICPC;

import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class STU18_F {
    // correct (to the best of my knowledge)
    public static class HPoint implements Comparable<HPoint> {
        long x;
        long y;
        HPoint(long x, long y){
            this.x = x;
            this.y = y;
        }

        // auto-gen
        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            HPoint hPoint = (HPoint) o;
            return x == hPoint.x &&
                    y == hPoint.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }

        @Override
        public int compareTo(HPoint b){
            if(this.x == b.x){
                return -Long.valueOf(this.y).compareTo(b.y);
            }else{
                return -Long.valueOf(this.x).compareTo(b.x);
            }
        }

        public double getLengthFromOrigin(){
            return Math.pow(Math.sqrt(x*x + y*y),2);
        }

        @Override
        public String toString(){
            return String.format("(%d,%d)",x,y);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(in.readLine());
        HashSet<HPoint> pts = new HashSet<>();
        StringTokenizer st;
        for(int i = 0; i < 4*N; i++){
            st = new StringTokenizer(in.readLine());
            pts.add(new HPoint(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }

        double ans = 0;
        while(!pts.isEmpty()){
            HPoint m = new HPoint(Integer.MAX_VALUE,Integer.MAX_VALUE);
            for(HPoint p: pts){
                if(p.compareTo(m) > 0){
                    m = p;
                }
            }
            pts.remove(m);
            Set<HPoint[]> cands = new HashSet<>();
            for(HPoint b: pts){
                HPoint side = new HPoint(m.x-b.x,m.y-b.y);
                HPoint pPlusSide = new HPoint(m.x-side.y,m.y+side.x);
                if(pts.contains(pPlusSide)){
                    HPoint bPlusSide = new HPoint(b.x-side.y,b.y+side.x);
                    if(pts.contains(bPlusSide)){
                        cands.add(new HPoint[] {side, m, b, pPlusSide, bPlusSide});
                    }
                }

                HPoint pMinusSide = new HPoint(m.x+side.y,m.y-side.x);
                if(pts.contains(pMinusSide)){
                    HPoint bMinusSide = new HPoint(b.x+side.y,b.y-side.x);
                    if(pts.contains(bMinusSide)){
                        cands.add(new HPoint[] {side, m, b, pMinusSide, bMinusSide});
                    }
                }
            }

            HPoint[] min = null;
            for(HPoint[] cand: cands){
                if(min==null || cand[0].getLengthFromOrigin() < min[0].getLengthFromOrigin()){
                    min = cand;
                }
            }

            // System.out.println(Arrays.toString(min));
            ans += min[0].getLengthFromOrigin();
            for(int i = 2; i < min.length; i++){
                pts.remove(min[i]);
            }
        }

        System.out.println(ans);
    }
}
