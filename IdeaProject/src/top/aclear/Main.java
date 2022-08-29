package top.aclear;

import java.util.Scanner;

class SuperClass{
    int i;
    public SuperClass(){}
    public SuperClass(int i){
        this.i = i;
        System.out.println("The constructor of A is invoked.");
    }

}


class SubClass extends SuperClass{
    public SubClass(int i){
        System.out.println("The constructor of B is invoked.");
    }
}

class A{
    public A(){
        System.out.println("The constructor of A is invoked.");
    }

}


class B extends A{
    public B(){
        System.out.println("The constructor of B is invoked.");
    }
}

public class Main {

    public static void main(String[] args) {
	// write your code here
//        B b = new B();
//        System.out.println("Where ");
//        System.out.println("Next function.");
//
//        StaticAndInstance obj = new StaticAndInstance(1, 2.0);
//        System.out.println(obj.i);
//        System.out.println(obj.d);
//        System.out.println(StaticAndInstance.d);
//        System.out.println(StaticAndInstance.i);


//        // 测试连续输入字符串
//        Scanner scan = new Scanner(System.in);
//        while(scan.hasNext()){
////            String str1 = scan.nextLine();
////            System.out.println("接收到的字符为:" + str1);
//            String[] str2 = scan.nextLine().split(" ");
//            for (String i:str2) {
//                System.out.println("字符串切割：" + i);
//            }
//        }


    }
}
