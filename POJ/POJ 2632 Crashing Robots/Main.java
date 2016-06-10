import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Map;

/**
 * Created by crazyacking on 2016/6/9.
 */
// poj 2632 Crashing Robots
class Pos{
    int x,y;
    char c;
    Pos(int x,int y,char c){
        this.x=x;
        this.y=y;
        this.c=c;
    }
}

class Instruction{
    int robot;
    char action;
    int repeat;
    Instruction(int a,char b,int c){
        this.robot=a;
        this.action=b;
        this.repeat=c;
    }
}

public class Main {
    static int xlen=0,ylen=0;
    static int[][] grid=new int[110][110];
    static char[] coordinate=new char[4];

    public static void main(String[] args) throws IOException {
        Scanner in=new Scanner(new BufferedInputStream(System.in));

        coordinate[0]='N';
        coordinate[1]='E';
        coordinate[2]='S';
        coordinate[3]='W';

        int Cas;
        Cas=in.nextInt();
        while((Cas--)!=0){
            xlen=in.nextInt();
            ylen=in.nextInt();

            for(int i=1;i<=ylen;++i){
                for(int j=1;j<=xlen;++j){
                    grid[i][j]=-1;
                }
            }

            int robotsNum=in.nextInt();
            int instructionsNum=in.nextInt();

            // 输入机器人的位置、方向
            HashMap<Integer,Pos> robotPos=new HashMap<>();
            for(int i=1;i<=robotsNum;++i){
                int x=in.nextInt();
                int y=in.nextInt();
                char c=in.next().charAt(0);
                robotPos.put(i,new Pos(x,y,c));
                grid[ylen-x][y]=i;
            }

//            debug(robotPos);

            // 输入指令：<robot #>  <action>  <repeat>
            ArrayList<Instruction> instructions=new ArrayList<>();
            for(int i=0;i<instructionsNum;++i){
                int robot=in.nextInt();
                char action=in.next().charAt(0);
                int repeat=in.nextInt();
                instructions.add(new Instruction(--robot,action,repeat));
            }

//            System.out.println("----------------------");
//            System.out.println(instructions.get(0).robot);
//            System.out.println(instructions.get(0).action);
//            System.out.println(instructions.get(0).repeat);
//            System.out.println("----------------------");

            // 逐条指令进行判断
            boolean isCrash=false;
            for(int i=0;i<instructionsNum;++i){
                Instruction ins=instructions.get(i);
                if(isCrash=(checkCrash(Map,ins,robotPos)==true)){
                   break;
                }
            }
            if(!isCrash) System.out.println("OK");
        }
    }


    static boolean checkCrash(int[][] map, Instruction ins, HashMap<Integer,Pos> robotPos){
        int robot=ins.robot;
        int rep=ins.repeat;
        int sx=robotPos.get(ins.robot).x;
        int sy=robotPos.get(ins.robot).y;
        char dir=robotPos.get(ins.robot).c;

        switch (ins.action){
            case 'L':{
                int robotDir=0;
                for(int i=0;i<4;++i){
                    if(dir==coordinate[i]){
                        robotDir=i;
                        break;
                    }
                }
                for(int i=0;i<rep;++i){
                    robotDir++;
                    if(robotDir==4) robotDir=0;
                }
                robotPos.put(robot,new Pos(sx,sy,coordinate[robotDir]));
//                System.out.println("改变后的方向为:"+coordinate[robotDir]);
                break;
            }
            case 'R':{
                int robotDir=0;
                for(int i=0;i<4;++i){
                    if(dir==coordinate[i]){
                        robotDir=i;
                        break;
                    }
                }
                for(int i=0;i<rep;++i){
                    robotDir--;
                    if(robotDir==-1) robotDir=3;
                }
                robotPos.put(robot,new Pos(sx,sy,coordinate[robotDir]));
//                System.out.println("改变后的方向为:"+coordinate[robotDir]);
                break;
            }
            default:{
                if(goForward(dir,rep,sx,sy,robot,map,robotPos))
                    return true;
                break;
            }
        }
        return false;
    }

    static boolean check(int[][] map,int sx,int sy,int robot){
        if(!(sx>=0 && sx<xlen && sy>=0 && sy<ylen)){
            System.out.println("Robot "+(robot+1)+" crashes into the wall");
            return true;
        }
        if(map[sx][sy]!=-1){
            // debug
//            System.out.println("check:"+map[sx][sy]+"机器人到达位置:"+sx+" "+sy);
//            //
            System.out.println("Robot "+(robot+1)+" crashes into robot "+(map[sx][sy]+1));
            return true;
        }
        return false;
    }

    static boolean goForward(char dir,int time,int sx,int sy,int robot,int[][] map, HashMap<Integer,Pos> robotPos){
        map[sx][sy]=-1;
        switch(dir){
            case 'N':{
                while((time--)!=0){
                    sx--;
                    if(check(map,sx,sy,robot))
                        return true;
                }
                map[sx][sy]=robot;
                robotPos.put(robot,new Pos(sx,sy,dir));
                // debug
//                System.out.println(map[sx][sy]+"机器人到达位置:"+sx+" "+sy);
                //
                break;
            }
            case 'E':{
                while((time--)!=0){
                    sy++;
                    if(check(map,sx,sy,robot))
                        return true;
                }
                map[sx][sy]=robot;
                robotPos.put(robot,new Pos(sx,sy,dir));
                // debug
//                System.out.println(map[sx][sy]+"机器人到达位置:"+sx+" "+sy);
                //

                break;
            }
            case 'S':{
                while((time--)!=0){
                    sx++;
                    if(check(map,sx,sy,robot))
                        return true;
                }
                map[sx][sy]=robot;
                robotPos.put(robot,new Pos(sx,sy,dir));
                // debug
//                System.out.println(map[sx][sy]+"机器人到达位置:"+sx+" "+sy);
                //
                break;
            }
            case 'W':{
                while((time--)!=0){
                    sy--;
                    if(check(map,sx,sy,robot))
                        return true;
                }
                map[sx][sy]=robot;
                robotPos.put(robot,new Pos(sx,sy,dir));
                // debug
//                System.out.println(map[sx][sy]+"机器人到达位置:"+sx+" "+sy);
                //
                break;
            }
        }
        return false;
    }

    static void debug(Map map){
        System.out.println("begin debug:*************************************************");
        for(Object m : map.entrySet()){
            Map.Entry me=(Map.Entry)m;
            System.out.println("robot:"+me.getKey()+
                    "    pos:"+((Pos)me.getValue()).x+","+
                    ((Pos)me.getValue()).y+","+
                    ((Pos)me.getValue()).c);
        }
        System.out.println("end debug:***************************************************");
    }

}