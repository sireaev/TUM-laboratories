package aes;

import java.nio.file.Files;
import java.nio.file.Paths;
import javax.crypto.*;

public class Main {

    public static void main(String[] args) throws Exception {
        //INDICAREA FISIERELOR DE SALVARE A DATELOR DE CRIPTARE SI DECRIPTARE
        String FileName = "encryptedtext.txt";
        String FileName2 = "decryptedtext.txt";
        //FUNCTIA IMPLICITA DE ALEGERE A INSTANTEI DE CRIPTARE AES
        KeyGenerator KeyGen = KeyGenerator.getInstance("AES");
        //BLOCUL AES DE 128 BITI
        KeyGen.init(128);
        //GENERAREA CHEII
        SecretKey SecKey = KeyGen.generateKey();
        //CREAREA OBIECTULUI DE CRIPTARE AES
        Cipher AesCipher = Cipher.getInstance("AES");

        //TRANSFORMAREA TEXTULUI DIN TEXT ALFANUMERIC IN BITI 
        //FOLOSIREA FUNCTIEI getBytes()
        byte[] byteText = "Your Plain Text Here".getBytes();
        //INITIEREA MODULUI DE CRIPTARE CU AJUTORUL FUNCTIEI init()
        //CREAREA OBIECTULUI PENTRU CRIPTAREA TEXTULUI
        //INSCRIEREA TEXTULUI CRIPTAT IN PRIMUL FISIER FileName
        AesCipher.init(Cipher.ENCRYPT_MODE, SecKey);
        byte[] byteCipherText = AesCipher.doFinal(byteText);
        Files.write(Paths.get(FileName), byteCipherText);

        //CREAREA OBIECTULUI PENTRU DECRIPTARE, CITIREA BITILOR DIN PRIMUL FISIER
        byte[] cipherText = Files.readAllBytes(Paths.get(FileName));
        //ACTIVAREA FUNCTIEI init CU MODUL DE DECRIPTARE AES
        //DECRIPTAREA TEXTULUI
        //INSCRIEREA IN AL 2-LEA FISIER
        AesCipher.init(Cipher.DECRYPT_MODE, SecKey);
        byte[] bytePlainText = AesCipher.doFinal(cipherText);
        Files.write(Paths.get(FileName2), bytePlainText);
    }
}
