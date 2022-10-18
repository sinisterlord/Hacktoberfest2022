// Sajanjit Singh Brar 
// 20124087
// OS Lab - 5
// Producer Consumer Problem

import java.lang.Thread;

class S {
    public static int n = 5;
    public static int Sema_mutex = 1;
    public static int Sema_empty = n;
    public static int Sema_full = 0;

    static void enter_mutex() {
        while (Sema_mutex <= 0) {
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                System.out.println("Thread Interrupted");
            }
        }
        Sema_mutex--;
    }

    static void exit_mutex() {
        Sema_mutex++;
    }

    static void enter_empty() {
        while (Sema_empty <= 0) {
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                System.out.println("Thread Interrupted");
            }
        }
        Sema_empty--;
    }

    static void exit_empty() {
        Sema_empty++;
    }

    static void enter_full() {
        while (Sema_full <= 0) {
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                System.out.println("Thread Interrupted");
            }
        }
        Sema_full--;
    }

    static void exit_full() {
        Sema_full++;
    }
}

class BufferStack {
    public static int stck[] = new int[5];
    public static int tos = -1;

    static void push(int item) {
        if (tos == stck.length - 1)
            System.out.println("Stack Overflow.");
        else
            stck[++tos] = item;
    }

    static int pop() {
        if (tos < 0) {
            System.out.println("Stack Underflow.");
            return 0;
        } else
            return stck[tos--];
    }
}

class Producer implements Runnable {
    String name;
    Thread p;
    int counter;

    Producer(String threadname) {
        name = threadname;
        p = new Thread(this, name);
        System.out.println("Process: " + p);
        p.start();
    }

    public void run() {
        for (int i = 0; i < 10; i++) {
            S.enter_empty();
            S.enter_mutex();
            System.out.println("Pushing: " + (i + 1));
            BufferStack.push(i + 1);
            S.exit_mutex();
            S.exit_full();
        }
    }

    void Completion() {
        System.out.println(name + ": Process Complete");
    }
}

class Consumer implements Runnable {
    String name;
    Thread c;
    int counter;

    Consumer(String threadname) {
        name = threadname;
        c = new Thread(this, name);
        System.out.println("Process: " + c);
        c.start();
    }

    public void run() {
        for (int i = 0; i < 10; i++) {
            S.enter_full();
            S.enter_mutex();
            int popped = BufferStack.pop();
            System.out.println("Popped: " + popped);
            S.exit_mutex();
            S.exit_empty();
        }
    }

    void Completion() {
        System.out.println(name + ": Process Complete");
    }
}

class ProdConsProb {
    public static void main(String args[]) {
        System.out.println("Sajanjit Singh Brar\n20124087\nProducer Consumer Problem\n");
        Producer P1 = new Producer("Producer_Process");
        Consumer P2 = new Consumer("Consumer_Process");
        try {
            P1.p.join();
            P1.Completion();
            P2.c.join();
            P2.Completion();
        } catch (InterruptedException e) {
            System.out.println("Thread Interrupted");
        }
    }
}