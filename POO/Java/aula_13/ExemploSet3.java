import java.util.Date;
import java.util.HashSet;
import java.util.Iterator;

public class ExemploSet3 {
    public static void main(String[] args) {
        HashSet<Object> set = new HashSet<Object>();
        
        set.add(new Integer(123));
        set.add(123);
        set.add("ABC");
        set.add("ABC");
        set.add(new Date());

        Iterator<Object> i = set.iterator();
        
        while (i.hasNext()) {
            Object o = i.next();
        
            if (o instanceof Integer)
                System.out.println("Achei um Integer:" + o);
        }
        // Achei um Integer:123
    }
}
