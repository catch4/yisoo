package a210630;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.stream.Stream;

public class BOJ1461 {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        String[] input = reader.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);

        int[] bookPosition = Stream.of(reader.readLine().split(" ")).mapToInt(Integer::parseInt).sorted().toArray();
        long count = Arrays.stream(bookPosition).filter(a -> a < 0).count();

        int sum = 0;

        for (int i = 0; i < count; i += m) {
            sum -= bookPosition[i] * 2;
        }

        for (int i = n - 1; i >= count; i -= m) {
            sum += bookPosition[i] * 2;
        }

        sum -= Math.max(Math.abs(bookPosition[0]), Math.abs(bookPosition[n - 1]));

        System.out.println(sum);

    }

}
