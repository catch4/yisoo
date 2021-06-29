package a210630;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class BOJ2655 {

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(reader.readLine());
        List<Brick> bricks = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            String[] input = reader.readLine().split(" ");
            bricks.add(new Brick(i + 1, Integer.parseInt(input[0]), Integer.parseInt(input[1]),
                    Integer.parseInt(input[2])));
        }

        Stacker stacker = new Stacker(bricks);
        stacker.stack();
        stacker.trace();

    }

    static class Brick implements Comparable<Brick> {
        private int index;
        private int underSide;
        private int height;
        private int weight;

        public Brick(int index, int underSide, int height, int weight) {
            this.index = index;
            this.underSide = underSide;
            this.height = height;
            this.weight = weight;
        }

        public boolean canStackOn(Brick brick) {
            return brick.getUnderSide() >= this.underSide && brick.getWeight() >= this.weight;
        }

        @Override
        public int compareTo(Brick brick) {
            return brick.getUnderSide() - this.underSide;
        }

        public int getIndex() {
            return this.index;
        }

        public int getUnderSide() {
            return this.underSide;
        }

        public int getHeight() {
            return this.height;
        }

        public int getWeight() {
            return this.weight;
        }
    }

    static class Stacker {
        private int[] prevIndex;
        private int[] height;
        private int maxHeight;
        private int maxIndex;
        private List<Brick> bricks;

        public Stacker(List<Brick> bricks) {
            this.bricks = bricks;

            Collections.sort(this.bricks, (a, b) -> {
                return a.compareTo(b);
            });
        }

        public void stack() {
            int size = bricks.size();
            maxHeight = 0;
            maxIndex = 0;
            prevIndex = new int[size];
            height = new int[size];

            for (int i = 0; i < size; i++) {
                height[i] = bricks.get(i).getHeight();
                prevIndex[i] = -1;
                for (int j = 0; j < i; j++) {
                    Brick underBrick = bricks.get(j);
                    Brick upperBrick = bricks.get(i);
                    if (upperBrick.canStackOn(underBrick) && height[j] + upperBrick.getHeight() > height[i]) {
                        height[i] = height[j] + upperBrick.getHeight();
                        prevIndex[i] = j;
                    }
                }
                if (maxHeight < height[i]) {
                    maxHeight = height[i];
                    maxIndex = i;
                }
            }
        }

        public void trace() {
            List<Integer> result = new ArrayList<>();

            write(result, maxIndex);

            System.out.println(result.size());

            for (Integer idx : result) {
                System.out.println(idx);
            }

            return;
        }

        private void write(List<Integer> array, int cur) {
            if (cur == -1)
                return;
            array.add(bricks.get(cur).getIndex());
            write(array, prevIndex[cur]);
        }

    }

}
