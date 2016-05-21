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
public class Main {
    public static void main(String[] args){
        Scanner in=new Scanner(new BufferedInputStream(System.in));
        while(in.hasNext()){
            int a=in.nextInt();
            int b=in.nextInt();
            int c=in.nextInt();
            if(c==0){
                System.out.println(a==b?"YES":"NO");
                continue;
            }
            else if(a>b && c>0){
                System.out.println("NO");
                continue;
            }
            else if(a<b && c<0){
                System.out.println("NO");
                continue;
            }
            if((b-a)%c==0)
                System.out.println("YES");
            else System.out.println("NO");
        }
    }
}
