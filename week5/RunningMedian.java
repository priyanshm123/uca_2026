import java.util.*;

public class RunningMedian {

    private PriorityQueue<Integer> maxHeap =
            new PriorityQueue<>(Collections.reverseOrder());

    private PriorityQueue<Integer> minHeap =
            new PriorityQueue<>();

    public void insert(int num) {

        if (maxHeap.isEmpty() || num <= maxHeap.peek()) {
            maxHeap.offer(num);
        } else {
            minHeap.offer(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.offer(maxHeap.poll());
        } 
        else if (minHeap.size() > maxHeap.size()) {
            maxHeap.offer(minHeap.poll());
        }
    }

    public float getMedian() {

        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.peek();
        }

        return (maxHeap.peek() + minHeap.peek()) / 2.0f;
    }

    public static void main(String[] args) {

        RunningMedian rm = new RunningMedian();

       int[] numbers = {3, 4, 5, 6, 8, 11, 34, 25};

        for (int num : numbers) {

            rm.insert(num);

            System.out.println(
                "Inserted: " + num +
                "  Median: " + rm.getMedian()
            );
        }
    }
}

