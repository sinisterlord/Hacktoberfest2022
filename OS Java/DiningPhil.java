// Sajanjit Singh Brar 
// 20124087
// OS Lab - 7.2
// Dining Philosopher Problem

import java.lang.Thread;

class Se {
    static int chopstick[] = new int[5];

    static void enter_mutex(int a) {
        while (chopstick[a] <= 0) {
            try {
                Thread.sleep(10);
            } catch (InterruptedException e) {
                System.out.println("Thread Interrupted");
            }
        }
        chopstick[a]--;
    }

    static void exit_mutex(int a) {
        chopstick[a]++;
    }
}

class Philosopher implements Runnable {
    String name;
    Thread ph;
    int a;

    Philosopher(String threadname, int a) {
        name = threadname;
        ph = new Thread(this, name);
        System.out.println("Process: " + ph);
        ph.start();
    }

    public void run() {
        for (int i = 0; i < 2; i++) {
            Se.enter_mutex(a);
            Se.enter_mutex((a + 1) % 5);
            System.out.println(name + " Eating: " + i);
            Se.exit_mutex(a);
            Se.exit_mutex((a + 1) % 5);
            System.out.println(name + " Thinking: " + i);
        }
    }

    void Completion() {
        System.out.println(name + ": Process Complete");
    }
}

class DiningPhil {
    public static void main(String args[]) {
        System.out.println("Sajanjit Singh Brar\n20124087\nDining Philosopher Problem\n");
        for (int i = 0; i < 5; i++) {
            Se.chopstick[i] = 1;
        }
        Philosopher Ph1 = new Philosopher("Ph1", 0);
        Philosopher Ph2 = new Philosopher("Ph2", 1);
        Philosopher Ph3 = new Philosopher("Ph3", 2);
        Philosopher Ph4 = new Philosopher("Ph4", 3);
        Philosopher Ph5 = new Philosopher("Ph5", 4);

        try {
            Ph1.ph.join();
            Ph1.Completion();
            Ph2.ph.join();
            Ph2.Completion();
            Ph3.ph.join();
            Ph3.Completion();
            Ph4.ph.join();
            Ph4.Completion();
            Ph5.ph.join();
            Ph5.Completion();
        } catch (InterruptedException e) {
            System.out.println("Thread Interrupted");
        }
    }
}