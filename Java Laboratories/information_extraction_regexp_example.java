package lab3;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.*;

public class Main {

    static String returnMoreFile(String[] args1) throws IOException {
        String str1 = "";

        for (int h = 0; h < args1.length; h++) {
            File file = new File(args1[h]);
            BufferedReader reader = new BufferedReader(new FileReader(file));
            String line = "", oldtext = "";
            while ((line = reader.readLine()) != null) {
                oldtext += line + "\r\n";
            }
            reader.close();
            str1 += oldtext;
        }
        return str1;
    }
    static List < String > upperCase(String str1) {
        Pattern p = Pattern.compile("([A-Z]{2,})");
        Matcher m = p.matcher(str1);
        List < String > uppercase = new ArrayList < String > ();
        while (m.find()) {
            uppercase.add(m.group());
        }
        int marimea = uppercase.size();
        System.out.println(marimea);
        return uppercase;
    }

    static List < String > numePersonalitati(String str1) {
        Pattern p = Pattern.compile("\\W([A-Z]\\.\\s?){1,}[A-Z][a-zA-Z]+");
        Matcher m = p.matcher(str1);
        List < String > Personalitate = new ArrayList < String > ();
        while (m.find()) {
            Personalitate.add(m.group());
        }
        int marime = Personalitate.size();
        System.out.println(marime);
        return Personalitate;
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        List < String > uppercase = new ArrayList < String > ();
        List < String > personalitate = new ArrayList < String > ();
        String str1;
        String[] args1 = {
            "D:/var12/10Aug2000politica.txt",
            "D:/var12/10Aug2001politica.txt",
            "D:/var12/10Dec2000politica.txt",
            "D:/var12/10Feb2001politica.txt",
            "D:/var12/10Jan2001politica.txt",
            "D:/var12/10Jul2000politica.txt",
            "D:/var12/10Jul2001politica.txt",
            "D:/var12/10Mar2001politica.txt",
            "D:/var12/10May2001politica.txt",
            "D:/var12/10Nov2000politica.txt",
        };
        try {
            str1 = returnMoreFile(args1);
            uppercase = upperCase(str1);
            System.out.println(uppercase);
            personalitate = numePersonalitati(str1);
            System.out.println(personalitate);
        } catch (IOException e) {
            System.out.println("Atentie, eroare!");
            e.printStackTrace();
        }
    }
}
