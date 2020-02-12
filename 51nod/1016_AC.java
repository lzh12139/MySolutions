import java.io.FileNotFoundException;
import java.util.*;
import java.math.*;
import java.io.FileOutputStream;
import java.io.PrintStream;

public class Main {
    static int num[], ansnum;
    static BigInteger w[][], ans[];

    public static void dfs(int curnum, int less, int n, BigInteger cur) {
        //System.out.println(curnum + " " + less + " " + cur);
        if (curnum == 10 && less != 0) return;
        if (less == 0) {
            int tmp[] = new int[15];
            String curans = cur.toString();
            for (int i = 0; i <= 9; i++) tmp[i] = num[i];
            for (int i = 0; i < curans.length(); i++)
                tmp[curans.charAt(i) - '0']--;
            for (int i = 0; i <= 9; i++)
                if (tmp[i] != 0) return;
            ans[ansnum++] = cur;
            System.out.println("ans[" + ansnum + "]=new BigInteger(\"" + cur + "\");");
            return;
        }
        num[curnum] = 0;
        dfs(curnum + 1, less, n, cur);
        BigInteger add = cur;
        for (int i = 1; i <= less; i++) {
            num[curnum] = i;
            add = add.add(w[curnum][n]);
            dfs(curnum + 1, less - i, n, add);
            num[curnum] = 0;
        }
    }

    public static void get() {
        for (int j = 1; j <= 9; j++)
            w[j][2] = BigInteger.valueOf(j).pow(2);
        for (int i = 3; i <= 60; i++) {
            for (int j = 1; j <= 9; j++) {
                w[j][i] = BigInteger.valueOf(j).multiply(w[j][i - 1]);
                num[j] = 0;
            }
            w[0][i] = BigInteger.ZERO;
            num[0] = 0;
            dfs(0, i, i, BigInteger.ZERO);
        }

    }

    public static void main(String[] args) throws FileNotFoundException {
        ans = new BigInteger[1010];
        num = new int[15];
        w = new BigInteger[15][70];
        ansnum = 0;
        //PrintStream ps = new PrintStream("out.txt");
        //System.setOut(ps);
        //get();

        Scanner in = new Scanner(System.in);

        ans[0] = new BigInteger("153");
        ans[1] = new BigInteger("370");
        ans[2] = new BigInteger("371");
        ans[3] = new BigInteger("407");
        ans[4] = new BigInteger("1634");
        ans[5] = new BigInteger("8208");
        ans[6] = new BigInteger("9474");
        ans[7] = new BigInteger("54748");
        ans[8] = new BigInteger("92727");
        ans[9] = new BigInteger("93084");
        ans[10] = new BigInteger("548834");
        ans[11] = new BigInteger("1741725");
        ans[12] = new BigInteger("4210818");
        ans[13] = new BigInteger("9800817");
        ans[14] = new BigInteger("9926315");
        ans[15] = new BigInteger("24678050");
        ans[16] = new BigInteger("24678051");
        ans[17] = new BigInteger("88593477");
        ans[18] = new BigInteger("146511208");
        ans[19] = new BigInteger("472335975");
        ans[20] = new BigInteger("534494836");
        ans[21] = new BigInteger("912985153");
        ans[22] = new BigInteger("4679307774");
        ans[23] = new BigInteger("32164049650");
        ans[24] = new BigInteger("32164049651");
        ans[25] = new BigInteger("40028394225");
        ans[26] = new BigInteger("42678290603");
        ans[27] = new BigInteger("44708635679");
        ans[28] = new BigInteger("49388550606");
        ans[29] = new BigInteger("82693916578");
        ans[30] = new BigInteger("94204591914");
        ans[31] = new BigInteger("28116440335967");
        ans[32] = new BigInteger("4338281769391370");
        ans[33] = new BigInteger("4338281769391371");
        ans[34] = new BigInteger("21897142587612075");
        ans[35] = new BigInteger("35641594208964132");
        ans[36] = new BigInteger("35875699062250035");
        ans[37] = new BigInteger("1517841543307505039");
        ans[38] = new BigInteger("3289582984443187032");
        ans[39] = new BigInteger("4498128791164624869");
        ans[40] = new BigInteger("4929273885928088826");
        ans[41] = new BigInteger("63105425988599693916");
        ans[42] = new BigInteger("128468643043731391252");
        ans[43] = new BigInteger("449177399146038697307");
        ans[44] = new BigInteger("21887696841122916288858");
        ans[45] = new BigInteger("27879694893054074471405");
        ans[46] = new BigInteger("27907865009977052567814");
        ans[47] = new BigInteger("28361281321319229463398");
        ans[48] = new BigInteger("35452590104031691935943");
        ans[49] = new BigInteger("174088005938065293023722");
        ans[50] = new BigInteger("188451485447897896036875");
        ans[51] = new BigInteger("239313664430041569350093");
        ans[52] = new BigInteger("1550475334214501539088894");
        ans[53] = new BigInteger("1553242162893771850669378");
        ans[54] = new BigInteger("3706907995955475988644380");
        ans[55] = new BigInteger("3706907995955475988644381");
        ans[56] = new BigInteger("4422095118095899619457938");
        ans[57] = new BigInteger("121204998563613372405438066");
        ans[58] = new BigInteger("121270696006801314328439376");
        ans[59] = new BigInteger("128851796696487777842012787");
        ans[60] = new BigInteger("174650464499531377631639254");
        ans[61] = new BigInteger("177265453171792792366489765");
        ans[62] = new BigInteger("14607640612971980372614873089");
        ans[63] = new BigInteger("19008174136254279995012734740");
        ans[64] = new BigInteger("19008174136254279995012734741");
        ans[65] = new BigInteger("23866716435523975980390369295");
        ans[66] = new BigInteger("1145037275765491025924292050346");
        ans[67] = new BigInteger("1927890457142960697580636236639");
        ans[68] = new BigInteger("2309092682616190307509695338915");
        ans[69] = new BigInteger("17333509997782249308725103962772");
        ans[70] = new BigInteger("186709961001538790100634132976990");
        ans[71] = new BigInteger("186709961001538790100634132976991");
        ans[72] = new BigInteger("1122763285329372541592822900204593");
        ans[73] = new BigInteger("12639369517103790328947807201478392");
        ans[74] = new BigInteger("12679937780272278566303885594196922");
        ans[75] = new BigInteger("1219167219625434121569735803609966019");
        ans[76] = new BigInteger("12815792078366059955099770545296129367");
        ans[77] = new BigInteger("115132219018763992565095597973971522400");
        ans[78] = new BigInteger("115132219018763992565095597973971522401");

        BigInteger s = in.nextBigInteger();
        int hasout = 0;
        for (int i = 0; i < 79; i++)
            if (s.compareTo(ans[i]) <= 0) {
                System.out.println(ans[i]);
                hasout++;
                break;
            }
        if (hasout == 0)
            System.out.println("No Solution");
    }
}