class mythread implements Runnable
{
    public void run()
    {
        for(int i=1;i<=10;i++)
            System.out.println("My Thread");
    }
}
public class Multithreading 
{
    public static void main(String[] args) 
    {
        mythread s=new mythread();
        Thread t=new Thread(s);
        t.start();
        for(int i=1;i<=10;i++)
            System.out.println("Main Thread");
    }
}