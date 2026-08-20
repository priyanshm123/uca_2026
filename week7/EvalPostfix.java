import java.util.*;

public class EvalPostfix {

    public static int evalPostfix(String s) {

        Stack<Integer> result = new Stack<>();

        String[] expression = s.trim().split("\\s+");

        for (String exp : expression) {

            if (!(exp.equals("+") || exp.equals("-") ||
                    exp.equals("*") || exp.equals("/"))) {

                result.push(Integer.parseInt(exp));

            } else {

                int b = result.pop();
                int a = result.pop();
                int res = 0;

                switch (exp) {
                    case "+":
                        res = a + b;
                        break;

                    case "-":
                        res = a - b;
                        break;

                    case "*":
                        res = a * b;
                        break;

                    case "/":
                        res = a / b;
                        break;
                }

                result.push(res);
            }
        }

        return result.pop();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
	System.out.println("Enter the string: ");
	String s = sc.nextLine();

        System.out.println(evalPostfix(s));
	sc.close();
    }
}
