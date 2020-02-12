import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        BigInteger ans = BigInteger.ZERO, add = BigInteger.ONE;
        BigInteger m36 = BigInteger.valueOf(36);
        for (int i = s.length() - 1; i >= 0; i--) {
            int j;
            char now = s.charAt(i);
            if ('0' <= now && now <= '9') j = now - '0';
            else j = now - 'A' + 10;
            ans = ans.add(add.multiply(BigInteger.valueOf(j)));
            add = add.multiply(m36);
        }
        System.out.println(ans);
    }
}