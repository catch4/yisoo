package a210721;

import java.io.*;
import java.util.*;
import java.util.stream.*;

public class BOJ17070 {
    public static void main(String[] args) throws IOException {
        BufferedReader input = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(input.readLine());

        int[][] arr = new int[n][n];

        for (int i = 0; i < n; i++) {
            String[] rows = input.readLine().split(" ");
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(rows[j]);
            }
        }

        System.out.println(dp(arr, n));
    }

    public static int dp(int[][] arr, int n) {
        int[][][] dpArr = new int[n][n][3];

        dpArr[0][1][0] = 1;

        for (int i = 1; i < n; i++) {
            if (arr[0][i] == 1)
                break;
            dpArr[0][i][0] = 1;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                if (arr[i][j] == 1)
                    continue;

                if (arr[i][j - 1] != 1)
                    dpArr[i][j][0] = dpArr[i][j - 1][0] + dpArr[i][j - 1][1];
                if (arr[i - 1][j] != 1)
                    dpArr[i][j][2] = dpArr[i - 1][j][1] + dpArr[i - 1][j][2];
                if (arr[i][j - 1] != 1 && arr[i - 1][j] != 1 && arr[i - 1][j - 1] != 1)
                    dpArr[i][j][1] = dpArr[i - 1][j - 1][0] + dpArr[i - 1][j - 1][1] + dpArr[i - 1][j - 1][2];

            }
        }

        int result = 0;
        for (int i = 0; i < 3; i++) {
            result += dpArr[n - 1][n - 1][i];
        }

        return result;
    }
}
