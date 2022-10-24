import java.util.*;
public class Main
{
    public static void pascal(int n, int[][] arr) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || i == j) {
                    arr[i][j] = 1;
                } else {
                    arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
                }
            }
        }
    }
	public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] arr = new int[n][n];
        pascal(n, arr);
        for (int[] i: arr) {
            for (int j: i) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
	}
}