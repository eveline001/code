import java.io.*;  
import java.math.BigDecimal;
import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner cin = new Scanner(System.in);
        int T;
        BigDecimal B2 = new BigDecimal(2.0), B4 = new BigDecimal(4.0), Br = new BigDecimal(-1.0);
        String s;
        
        T = cin.nextInt();

        for(int cas = 1; cas <= T; cas++){
            s = cin.next();
            BigDecimal x0 = new BigDecimal(s);
            s = cin.next();
            BigDecimal y0 = new BigDecimal(s);
            s = cin.next();
            BigDecimal x1 = new BigDecimal(s);
            s = cin.next();
            BigDecimal y1 = new BigDecimal(s);
            s = cin.next();
            BigDecimal x2 = new BigDecimal(s);
            s = cin.next();
            BigDecimal y2 = new BigDecimal(s);
            s = cin.next();
            BigDecimal x3 = new BigDecimal(s);
            s = cin.next();
            BigDecimal y3 = new BigDecimal(s);

            BigDecimal detX12 = x0.subtract(x1),
                   detY12 = y0.subtract(y1),
                   detX13 = x0.subtract(x2),
                   detY13 = y0.subtract(y2);
            BigDecimal C12 = (((x0.multiply(x0)).subtract(x1.multiply(x1))).add(y0.multiply(y0))).subtract(y1.multiply(y1)),
                   C13 = (((x0.multiply(x0)).subtract(x2.multiply(x2))).add(y0.multiply(y0))).subtract(y2.multiply(y2));
            BigDecimal D = ((C12.multiply(detY13)).subtract(C13.multiply(detY12))).divide((detX13.multiply(detY12)).subtract(detX12.multiply(detY13)));
            BigDecimal E = ((C12.multiply(detX13)).subtract(C13.multiply(detX12))).divide((detY13.multiply(detX12)).subtract(detY12.multiply(detX13)));
            BigDecimal F = (((x0.multiply(x0).add(y0.multiply(y0))).add(D.multiply(x0))).add(E.multiply(y0))).multiply(Br);
            BigDecimal x = D.divide(B2).multiply(Br), y = E.divide(B2).multiply(Br);
            BigDecimal rr = (((D.multiply(D)).subtract(F.multiply(B4))).add(E.multiply(E))).divide(B4);

            if((x3.subtract(x)).multiply(x3.subtract(x)).add((y3.subtract(y)).multiply(y3.subtract(y))).compareTo(rr) >= 1) System.out.println("Accepted");
            else System.out.println("Rejected");
        }
        cin.close();
    }
}  