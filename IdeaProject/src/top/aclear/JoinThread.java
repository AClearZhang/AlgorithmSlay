package top.aclear;

public class JoinThread {
    public static void main(String[] args) throws Exception{
        SumThread t1 = new SumThread(10);
        System.out.println(t1.sum);
        t1.start();
        t1.join();
        System.out.println(t1.sum);
    }
}

class SumThread extends Thread{
    int sum;
    int i;
    public SumThread(int i){
        this.i = i;
    }

    public void run(){
        for (int j = 0; j < i ;j ++){
            sum += j;
        }
    }
}

