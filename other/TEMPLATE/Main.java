/*
* -----------------------------------------------------------------
* Copyright (c) 2015 crazyacking All rights reserved.
* -----------------------------------------------------------------
*       Author: crazyacking
*       Mail:   crazyacking@gmail.com
*/

import java.io.*;
import java.lang.*;
import java.util.Arrays;
import javax.swing.JOptionPane;

public class Main {
    /***********************************************************************************************************
     * 首先申明数组，请求资源，尚需资源，可用资源，已得到分配的资源
     * 1.首先判断请求是否小于尚需资源
     * 2.判断请求资源是否小于现有资源
     * 3.分配资源给进程，改变值，尚需资源减去请求资源，可用资源减去请求资源，已得到的资源加上请求资源
     * 4.安全性检测
     *
     * 安全性检查:
     * 首先设置两个向量，work和finish，向量work的值等于可用资源的值
     * 判断当前进程的need是否小于work，是，就finish置为true
     * 改变work的值，继续下一个进程的判断，判断完成后生成一个安全序列，这样按照安全序列进行分配资源，每分配一个进程，就进行安全序列检测，这样每次分配的都是安全序列的第一个
     * 直到完成
     ************************************************************************************************************/
    public static int p[];              // 进程数量
    public static int Source[];         // 系统各种资源的总量
    public static int Max[][];          // 最大需求矩阵
    public static int Allocation[][];   // 每个进程拥有各种资源的数量
    public static int Available[];      // 现有可用资源的数量
    public static int Need[][];         // 每个进程目前尚需资源
    public static int Work[];           // 系统可供给进程的各类资源数量(中间变量)
    public static int _Work[][];        // 存放每一次分配资源前的Work，在没有改变前的资源
    public static boolean Finish[];     // 标志一个进程是否可以得到所需资源
    public static int Request[];        // 进程对每个资源的请求数量
    public static int flag = 0;         // 标志变量

    /***
     * 初始化各类资源
     *****/
    void InitVar() {
        // 假设有3类资源,5个进程
        Source = new int[]{10, 5, 7};
        Max = new int[][]
                {
                        {7, 5, 3},
                        {3, 2, 2},
                        {9, 0, 2},
                        {2, 2, 2},
                        {4, 3, 3}
                };
        Allocation = new int[][]
                {
                        {0, 1, 0},
                        {2, 0, 0},
                        {3, 0, 2},
                        {2, 1, 1},
                        {0, 0, 2}
                };
    }

    public Main() {
        InitVar();
        /******     source.length=3，代表资源的种类      **********/
        Available = new int[Source.length];
        Need = new int[Max.length][Source.length];
        /** 各种资源的剩余量 **/
        for (int m = 0; m < 3; m++)
            Available[m] = Source[m] - Allocation[0][m] - Allocation[1][m] -
                    Allocation[2][m] - Allocation[3][m] - Allocation[4][m];
        /** 计算尚需的资源 **/
        for (int i = 0; i < 5; i++)         // 第i个进程
            for (int j = 0; j < 3; j++)     // 第j个资源
                Need[i][j] = Max[i][j] - Allocation[i][j];
        int MAXN = 100;
        p = new int[MAXN];
        Work = new int[MAXN];
        _Work = new int[MAXN][MAXN];
        Request = new int[MAXN];
        Finish = new boolean[MAXN];
        // 初始资源分配完毕，输出初始值
        Main.Print(-1);
    }

    public static void Print(int p) {
        if (p == -1) // 输出初始值
        {
            System.out.println("---------------------初始资源分配--------------------------");
            System.out.println("          Max        Allocation      Need        Available");
            System.out.println("       A   B   C     A   B   C     A   B   C     A   B   C");
            System.out.print("P[0]   ");
            for (int j = 0; j < 3; j++)
                System.out.print(Max[0][j] + "   ");
            System.out.print("  ");
            for (int j = 0; j < 3; j++)
                System.out.print(Allocation[0][j] + "   ");
            System.out.print("  ");
            for (int j = 0; j < 3; j++)
                System.out.print(Need[0][j] + "   ");
            System.out.print("  ");
            for (int j = 0; j < 3; j++)
                System.out.print(Available[j] + "   ");
            System.out.println();
            for (int i = 1; i < 5; i++) {
                System.out.print("P[" + i + "]   ");
                for (int j = 0; j < 3; j++)
                    System.out.print(Max[i][j] + "   ");
                System.out.print("  ");
                for (int j = 0; j < 3; j++)
                    System.out.print(Allocation[i][j] + "   ");
                System.out.print("  ");
                for (int j = 0; j < 3; j++)
                    System.out.print(Need[i][j] + "   ");
                System.out.println();
            }
        } else {
            if (flag == 0) {
                System.out.println("---------------------请求资源后分配--------------------------");
                System.out.println("         Work          Need       Allocation  Work+Allocation  Finish");
                System.out.println("       A   B   C     A   B   C     A   B   C     A   B   C");
                flag = 1;
            }
            if (flag == 1) {
                System.out.print("P[" + p + "]   ");
                for (int j = 0; j < 3; j++)
                    System.out.print(_Work[p][j] + "   ");
                System.out.print("  ");
                for (int j = 0; j < 3; j++)
                    System.out.print(Need[p][j] + "   ");
                System.out.print("  ");
                for (int j = 0; j < 3; j++)
                    System.out.print(Allocation[p][j] + "   ");
                System.out.print("  ");
                for (int j = 0; j < 3; j++)
                    System.out.print((_Work[p][j] + Allocation[p][j]) + "   ");
                System.out.print("    " + Finish[p]);
                System.out.println();
            }
        }
    }

    /**
     * 检测请求是不是小于最大需求
     * × 判断第i个进程的所需的资源是否大于目前系统所剩的资源
     **/
    public static boolean Judge(int a[][], int i, int b[]) {
        for (int j = 0; j < Source.length; j++) {
            if (a[i][j] > b[j])
                return false;
        }
        return true;
    }

    /***
     * 安全性序列检测
     ****/
    public static boolean Security_check()  // 安全状态检查
    {
        boolean run = true;
        /**   Max.lemgth是5，source.length是3     **/
        int count = 0, procedure = 0;
        for (int j = 0; j < Source.length; j++)//对work进行初始化
            Work[j] = Available[j];
        for (int m = 0; m < Max.length; m++)//对finish进行初始化
            Finish[m] = false;


        while (run) {
            for (int i = 0; i < Max.length; i++) {
                count++; //当所有的都为false，则不需进入if，表示全部都以分配完成
                if (Finish[i] == false && Judge(Need, i, Work) == true) {
                    count--;//从i开始
                    Finish[i] = true;
                    p[procedure] = i;
                    procedure += 1;
                    for (int j = 0; j < Source.length; j++)
                        _Work[i][j] = Work[j];
                    for (int j = 0; j < Source.length; j++) {
                        Work[j] = Work[j] + Allocation[i][j];
                    }
                }
            }


            if (count == Max.length) {
                run = false; //已经走到最后，结束检查程序
            } else    //没有找到安全序列，count置为0，从新来进行安全性序列检测
            {
                run = true; //继续循环
                count = 0;  //重新计数，放在while下面也可以
            }
        }//end of while

        for (int i = 0; i < Max.length; i++)
            if (Finish[i] == false) {
                System.out.println("找不到一个安全序列,系统处于不安全状态,分配失败");
                return false;
            }
        System.out.println("存在一个安全序列，系统处于安全状态，可为其分配资源。安全序列是:\n" + Arrays.toString(p));
        return true;
    }

    public static void SourseRequest() {
        int run = 1;
        int run1 = 1;
        while (run == 1) {
            String str = JOptionPane.showInputDialog("请输入需要申请资源的进程号");
            int id = Integer.parseInt(str) - 1;
            System.out.println("正在为进程[" + id + "]分配资源");

            if (id < 0 || id >= Max.length) {
                JOptionPane.showInputDialog("输入的进程号不存在！请重新输入。");
            } else {
                boolean Is_Ok = true;
                int count = 0;
                for (int i = 0; i < Source.length; i++) {
                    String str1 = JOptionPane.showInputDialog("请输入此进程所请求的第" + "[" + i + "]" + "类资源数");

                    Request[i] = Integer.parseInt(str1);
                }

                for (int i = 0; i < Source.length; i++) {
                    if (Request[i] > Need[id][i]) {
                        JOptionPane.showInputDialog("第" + (i + 1) + "类资源请求量超出最大值！无效。");
                        Is_Ok = false;
                    }
                }

                if (!Is_Ok)
                    run = 0;
                else  // 未大于尚需资源
                {
                    run = 0;
                    for (int k = 0; k < Source.length; k++) {
                        Available[k] = Available[k] - Request[k];            //可用资源减少
                        Allocation[id][k] = Allocation[id][k] + Request[k];  //拥有资源增加
                        Need[id][k] = Need[id][k] - Request[k];              //还需要的资源减少
                    }
                }
                String str1 = JOptionPane.showInputDialog("是否继续，按1继续，按0退出");
                run = Integer.parseInt(str1);
            }
        } //end of while
    }

    /**
     * 进行分配
     ***/
    public static void Distribution() {
        if (Security_check())
            for (int i = 0; i < Max.length; i++)
                Main.Print(p[i]);
    }

    public static void show() {
        String a = JOptionPane.showInputDialog("请输入你要查看的资源1：分配前2：分配后");
        int s1 = Integer.parseInt(a);
        if (s1 == 1) {
            Print(-1);
        } else if (s1 == 2) {
            if (Security_check())
                for (int i = 0; i < Max.length; i++)
                    Main.Print(p[i]);
        }
    }

    public static void RecycleResource() // 资源回收函数
    {
        if (Security_check()) {

            for (int d = 0; d < Max.length; d++) {
                for (int k = 0; k < Source.length; k++) {
                    Distribution();// 每次回收一个资源都进行安全状态检查，然后输出当前状态
                    Available[k] = Available[k] + Request[k]; // 可用资源增加
                    Allocation[d][k] = Allocation[d][k] - Request[k];   //每个进程拥有资源减少
                    Need[d][k] = Need[d][k] + Request[k];   //每个进程需要的资源增加
                }
                Main.Print(p[d]);
            }
        } else {
            return;
        }
    }

    public static void exit() {
        System.exit(0);
    }

    public static void menu() {
        while (true) {
            String str2 = JOptionPane.showInputDialog("银行家算法避免死锁\n    1.分配资源\n    2.回收资源\n    3.查看资源\n    4.退出操作\n");
            int s = Integer.parseInt(str2);
            if (s == 1) {
                SourseRequest();  //请求
                Distribution();   //分配
                continue;
            } else if (s == 2) {
                RecycleResource();
                continue;
            } else if (s == 3) {
                show();
                continue;
            } else if (s == 4) {
                exit();
                continue;
            } else {
                break;
            }
        }
    }

    public static void main(String[] args) {
        Main b = new Main();
        b.menu();
    }
}
