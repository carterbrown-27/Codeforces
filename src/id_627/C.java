package id_627;

import java.io.*;

public class C {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine());
        for(int t = 0; t < T; t++){
            String s = in.readLine();
            char[] list = s.toCharArray();

            int maxdist = 0;
            int dist = 0;
            int pos = 0;
            while(pos < list.length){
                dist++;
                if(list[pos] == 'R'){
                    maxdist = Math.max(maxdist,dist);
                    dist = 0;
                }
                pos++;
            }

            // end space
            dist++;
            maxdist = Math.max(maxdist,dist);

            System.out.println(maxdist);
        }
        in.close();
    }
}
