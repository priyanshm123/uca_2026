import java.util.*;

public class clinicsVillages {

    static class Village {
        int population;
        int clinics;

        Village(int population) {
            this.population = population;
            this.clinics = 1;
        }

        double getLoad() {
            return (double) population / clinics;
        }
    }

    public static double solve(int[] population, int k) {
        int n = population.length;

        PriorityQueue<Village> pq = new PriorityQueue<>(
            (a, b) -> Double.compare(b.getLoad(), a.getLoad())
        );

        for (int pop : population) {
            pq.offer(new Village(pop));
        }

        for (int i = n; i < k; i++) {
            Village village = pq.poll();

            village.clinics++;

            pq.offer(village);
        }

        return pq.peek().getLoad();
    }

    public static void main(String[] args) {

	Scanner sc = new Scanner(System.in);

	System.out.println("Enter no. of villages: ");
	int n = sc.nextInt();

	int[] population = new int[n];

	System.out.println("Enter population of each village: ");

	for (int i = 0; i < n; i++) {
		population[i] = sc.nextInt();
	}

	System.out.println("Enter no. of Clinics: ");
	int k = sc.nextInt();

	sc.close();
	


        System.out.printf("%.2f%n", solve(population, k));
    }
}

