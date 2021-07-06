package a210707;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.stream.Stream;

public class BOJ13397 {

    private static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(reader.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] arr = Stream.of(reader.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        System.out.println(solve(arr, n, m));

    }

    private static int solve(int[] arr, int n, int m) {
        int left = 0;
        int right = 20001;
        int result = 20001;
        while (left <= right) {
            int mid = (right + left) / 2;

            if (check(arr, m, mid)) {
                right = mid - 1;
                result = Math.min(result, mid);
            } else {
                left = mid + 1;
            }
        }
        return result;
    }

    private static boolean check(int[] arr, int m, int value) {
        int count = 1;
        int minVal = 10001;
        int maxVal = 0;

        for (int score : arr) {
            minVal = Math.min(minVal, score);
            maxVal = Math.max(maxVal, score);

            if (maxVal - minVal > value) {
                count++;
                minVal = maxVal = score;
            }
        }
        return count <= m;
    }

}
