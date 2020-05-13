import java.io.*;
import java.util.*;

public class ecoo4 {

    public static long x = 0;
    public static final long MOD = 1000000007;

    public static class Function {
        String name;
        ArrayList<Function> subFuncs = new ArrayList<>();
        ArrayList<String> commands = new ArrayList<>();
        Function parent;

        Function(Function parent, String name){
            this.parent = parent;
            this.name = name;
        }

        public void call(){
            System.out.println("Calling Function: "+ name);
            for(String line: commands){
                executeLine(line);
            }
        }

        public void executeLine(String s){
            System.out.println("Executing Line: " + s);
            String[] sp = s.split(" ");
            String cmd = sp[0];
            if(cmd.equals("CALL")){
                for(Function f: subFuncs){
                    if(f.name.equals(sp[1])) {
                        f.call();
                        return;
                    }
                }
                Function par = parent;
                while(par.parent != null){
                    for(Function f: par.subFuncs){
                        if(f.name.equals(sp[1])) {
                            f.call();
                            return;
                        }
                    }
                }
                return;
            }
            int y = Integer.parseInt(sp[1]);
            if(cmd.equals("MULT")){
                x = (x*y)%MOD;
            }else if(cmd.equals("ADD")){
                x = (x+y)%MOD;
            }else if(cmd.equals("SUB")){
                x = (x-y)%MOD;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new FileReader("DATA.txt"));
        int t = Integer.parseInt(in.readLine());
        for(int i = 0; i < t; i++){
            x = 0;
            lineNo = 0;
            int n = Integer.parseInt(in.readLine());
            Function head = new Function(null, "@%MAIN%@"); // head
            recur(n, in,head);
            head.call();
            System.out.println(x);
        }
    }

    public static int lineNo = 0;
    public static void recur(int n, BufferedReader in, Function parent) throws IOException {
        String line = in.readLine();
        lineNo++;
        while(line != null){
            System.out.println(lineNo+": "+ line);
            String[] sp = line.split(" ");
            if(sp[0].equals("FUN")){
                Function f = new Function(parent,sp[1]);
                parent.subFuncs.add(f);
                recur(n, in, f);
            } else if(sp[0].equals("END")){
                return;
            } else {
                parent.commands.add(line);
            }
            if(lineNo == n) break;
            lineNo++;
            line = in.readLine();
        }
    }
}