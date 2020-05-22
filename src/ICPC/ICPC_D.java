package ICPC;

import java.io.*;

public class ICPC_D {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("ICPC_D_IN.txt"));
        int beers = 0;
        long bill = 0;
        String line = in.readLine();
        while(line!=null){
            if(line.charAt(0) == '|'){
                beers+=line.length();
            }else{
                String[] sp = line.split(",-");
                int p = Integer.parseInt(sp[0]);
                int l = sp[1].length();
                bill += p*l;
            }
            line = in.readLine();
        }

        bill += beers*42;
        bill = (long) Math.ceil((double) bill / 10);
        bill = Math.round(bill);
        bill *= 10;
        System.out.println(bill+",-");
    }
}
