import java.io.*;
import java.util.*;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            int n = Integer.parseInt(in.readLine());
            char[] str = in.readLine().toCharArray();
            HashMap<HPoint,Integer> map = new HashMap<>();
            int l = -1;
            int r = 0;
            HPoint curr = new HPoint(0,0);
            map.put(curr, 0);
            for(int i = 1; i <= n; i++){
                HPoint tmp = new HPoint(curr.x, curr.y);
                if(str[i-1] == 'U'){
                    tmp.y++;
                }else if(str[i-1] == 'D'){
                    tmp.y--;
                }else if(str[i-1] == 'R'){
                    tmp.x++;
                }else{
                    tmp.x--;
                }
                if(map.containsKey(tmp)){
                    if(l == -1 || i-map.get(tmp) < r-l){
                        l = map.get(tmp);
                        r = i;
                    }
                }
                map.put(tmp,i);
                curr = tmp;
            }
            System.out.println((l!=-1) ? String.format("%d %d", l+1,r): "-1");
        }
    }

    public static class HPoint {
        int x;
        int y;
        HPoint(int x, int y){
            this.x = x;
            this.y = y;
        }

        @Override
        public int hashCode(){
            return (x*31 + y);
        }

        @Override
        public boolean equals(Object o){
            if(o instanceof HPoint){
                HPoint p = (HPoint) o;
                return p.x == this.x && p.y == this.y;
            }
            return false;
        }
    }
}
