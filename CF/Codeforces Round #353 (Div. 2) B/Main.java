/*
 * Copyright (c) 2016. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
 * Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
 * Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
 * Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
 * Vestibulum commodo. Ut rhoncus gravida arcu.
 */

import java.io.BufferedInputStream;
import java.util.Scanner;

/**
 * Created by crazyacking on 2016/5/17.
 */
import java.util.Scanner;

public class Main {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int n,a,b,c,d;
        long ans=0;

        n=sc.nextInt();
        a=sc.nextInt();
        b=sc.nextInt();
        c=sc.nextInt();
        d=sc.nextInt();

        for(int i=1;i<=n;i++)
        {
            if((i+b-c)>0 && (i+a-d)>0 && (i+a+b-c-d)>0 && (i+b-c)<=n && (i+a-d)<=n && (i+a+b-c-d)<=n)
                ans=ans+(long)n;
        }

        System.out.println(ans);
        sc.close();
    }
}
