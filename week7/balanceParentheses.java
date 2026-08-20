import java.util.*;

class balanceParentheses {

    public static boolean balancedParentheses(String s) {
        Stack<Character> st = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            if (ch == '[' || ch == '{' || ch == '(') {
                st.push(ch);
            } else if (ch == ']' || ch == '}' || ch == ')') {

                if (st.empty()) {
                    return false;
                }

                char top = st.pop();

                if ((ch == ']' && top != '[') ||
                        (ch == '}' && top != '{') ||
                        (ch == ')' && top != '(')) {
                    return false;
                }
            }
        }

        return st.empty();
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
	
	System.out.println("Enter the string: ");
	String s = sc.nextLine();

        System.out.println(balancedParentheses(s));

	sc.close();

    }
}
