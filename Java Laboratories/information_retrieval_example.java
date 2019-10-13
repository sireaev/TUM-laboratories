package information_retrieval;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.StringTokenizer;
public class Main {
	static String[] returnMoreFile(String[] args1) throws IOException
	{
		String str1 = "";
		HashMap<String, Integer> dic = new HashMap<String, Integer>();
		for(int h = 0; h < args1.length; h++)
		{
			File file = new File(args1[h]);
			BufferedReader reader = new BufferedReader(new FileReader(file));
			String line = "", oldtext = "";
			while((line = reader.readLine()) != null)
            {
				oldtext += line + "\r\n";
            }
			reader.close();	
       str1 += oldtext;
       str1 = str1.toLowerCase();
       str1 = str1.replaceAll("\\p{P}","");
       str1.trim();
		}
       StringTokenizer st = new StringTokenizer (new String (str1));
       String word;
       while ( st.hasMoreTokens())
       {
       		word = st.nextToken();
       		Integer nrap = (Integer) dic.get(word);
       		if (nrap == null)
       		{
       			dic.put (word,1);
       		}
       		else
       		{
       			dic.put (word, new Integer (nrap.intValue()+1));
       		}
       }
		 
	   String[] str5 = dic.keySet().toArray(new String[dic.size()]);
	   return str5;	
	}
	static Integer[] returnValues(String args1) throws IOException

	{
		String str1 = "";
		HashMap<String, Integer> dic = new HashMap<String, Integer>();
			File file = new File(args1);
			BufferedReader reader = new BufferedReader(new FileReader(file));
			String line = "", oldtext = "";
			while((line = reader.readLine()) != null)
            {
				oldtext += line + "\r\n";
            }
			reader.close();
		
       str1 += oldtext;
       str1 = str1.toLowerCase();
       str1 = str1.replaceAll("\\p{P}","");
       str1.trim();
		
       StringTokenizer st = new StringTokenizer (new String (str1));
       String word;
       while ( st.hasMoreTokens())
       {
       		word = st.nextToken();
       		Integer nrap = (Integer) dic.get(word);
       		if (nrap == null)
       		{
       			dic.put (word,1);
       		}
       		else
       		{
       			dic.put (word, new Integer (nrap.intValue()+1));
       		}
       		
       		
       }
   Integer[] str6 = dic.values().toArray(new Integer[dic.size()]);
	return str6;
	}
	static String[] returnFile(String args1) throws IOException
	{
		String str1 = "";
		HashMap<String, Integer> dic = new HashMap<String, Integer>();

			File file = new File(args1);
			BufferedReader reader = new BufferedReader(new FileReader(file));
			String line = "", oldtext = "";
			while((line = reader.readLine()) != null)
            {
				oldtext += line + "\r\n";
            }
			reader.close();
		
       str1 += oldtext;
       str1 = str1.toLowerCase();
       str1 = str1.replaceAll("\\p{P}","");
       str1.trim();
		
       StringTokenizer st = new StringTokenizer (new String (str1));
       String word;
       while ( st.hasMoreTokens())
       {
       		word = st.nextToken();
       		Integer nrap = (Integer) dic.get(word);
       		if (nrap == null)
       		{
       			dic.put (word,1);
       		}
       		else
       		{
       			dic.put (word, new Integer (nrap.intValue()+1));
       		}
       }
	   String[] str5 = dic.keySet().toArray(new String[dic.size()]);
	   return str5;	
	}			
    public static void printGrid(double[][] matrix, String matrice[][],int n, int m)
	{
		System.out.println(" doc1   doc2   doc3   doc4   doc5   doc6   doc7   doc8   doc9   do10   do11   do12   do13   do14   do15   do16   do17   do18   do19   do20   do21   do22   do23   do24   do25   do26   do27   do28   do29   do30   do31   do32   do33   do34   do35   do36   do37   do38   do39   do40   do41   do42   do43   do44   do45   do46   do47   do48   do49   do50   do51   do52   do53   do54   do55   do56   do57   do58   do59   do60   do61   do62   do63   do64   do65   do66   do67   do68   do69   do70");
	   for(int i = 0; i < n; i++)
	   {
	      for(int j = 0; j < m; j++)
	      {
	         System.out.printf("%5.0f  ", matrix[i][j]);
	      }
	      System.out.printf("   %-15s", matrice[i][0]);
	      System.out.println();
	   }
	}
	
	public static void main(String[] args) {
		String[] args1 = {
				
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Aug2000baniafaceri.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Aug2000cotidian.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Aug2000editorial.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Aug2000inlume.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Aug2000investigatii.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Aug2000politica.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Aug2000sport.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Aug2001baniafaceri.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Aug2001cotidian.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Aug2001editorial.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Aug2001inlume.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Aug2001investigatii.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Aug2001politica.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Aug2001sport.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Dec2000baniafaceri.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Dec2000cotidian.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Dec2000editorial.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Dec2000inlume.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Dec2000investigatii.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Dec2000politica.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Dec2000sport.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Feb2001baniafaceri.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Feb2001cotidian.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Feb2001editorial.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Feb2001inlume.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Feb2001investigatii.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Feb2001politica.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Feb2001sport.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jan2001baniafaceri.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jan2001cotidian.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jan2001editorial.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jan2001inlume.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jan2001investigatii.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jan2001politica.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jan2001sport.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jul2000baniafaceri.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jul2000cotidian.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jul2000editorial.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jul2000inlume.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jul2000investigatii.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jul2000politica.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jul2000sport.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jul2001baniafaceri.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jul2001cotidian.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jul2001editorial.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jul2001inlume.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jul2001investigatii.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jul2001politica.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Jul2001sport.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Mar2001baniafaceri.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Mar2001cotidian.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Mar2001editorial.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Mar2001inlume.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Mar2001investigatii.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Mar2001politica.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Mar2001sport.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10May2001baniafaceri.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10May2001cotidian.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10May2001editorial.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10May2001inlume.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10May2001investigatii.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10May2001politica.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10May2001sport.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Nov2000baniafaceri.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Nov2000cotidian.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Nov2000editorial.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Nov2000inlume.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Nov2000investigatii.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Nov2000politica.txt",
        "/Users/admin/Documents/Semestru4/ASDS/Lab2/var12/10Nov2000sport.txt",
	};	
// DECLARAREA DATELOR.		
		String [][] matrice;
		double [][] matrix;
		double [][] matrixe;
		double [][] matrLog;
		String[] allWords ;
		double[] sum;
	    double suma;
	    double[] log;
	    double[] log1;

		 try
	        {	
// INITIALIZAREA TUTUROR DATELOR SI METODELOR
			 
			 allWords= returnMoreFile(args1);
	         matrice = new String[allWords.length][];
	         matrix = new double [allWords.length][];
	         matrixe = new double [allWords.length][];
	         matrLog = new double [allWords.length][];
	         sum = new double [70];
	         log = new double[allWords.length];
	         log1 = new double[allWords.length];
	         for (int i=0; i<allWords.length; i++)
                {
            	   matrice[i] = new String[1];
           		   matrice[i][0] = allWords[i];
                }
	         for (int i = 0; i < allWords.length; i++)
	        	 for(int j = 0; j < 70; j++)
	        	 {
	        		 matrix[i] = new double[70];
    			 	 matrix[i][j] = 0;
	        	 }
	         for (int i = 0; i < allWords.length; i++)
	        	 for(int j = 0; j < 70; j++)
	        	 {
	        		 matrixe[i] = new double[70];
    			 	 matrixe[i][j] = 0;	 
	        	 }
	         for (int i = 0; i < allWords.length; i++)
	        	 for(int j = 0; j < 70; j++)
	        	 {
	        		 matrLog[i] = new double[70];
    			 	 matrLog[i][j] = 0;	 
	        	 }
	         
//INSCRIEREA IN MATRIX(DOUBLE) A VALORILOR TUTUROR CUVINTELOR.
	    
	         for(int g = 0;g < args1.length; g++)
	         {
	        	 String[] fileWords = returnFile(args1[g]);
	        	 Integer[] fileValues = returnValues(args1[g]);

	        	 for(int i = 0; i < allWords.length; i++)
	        	 {
	        		 for(int j = 0; j < fileWords.length; j++ )
	        		 {
	        			 if(matrice[i][0].equals(fileWords[j]) == true)
	        			 {
	        				 matrix[i][g] = 1;	 
	        			 }			 
	        	     }	 
	         }
	         }
	         printGrid(matrix,matrice,allWords.length, args1.length);
	        }
		 catch (IOException ioe)
		    {
		        ioe.printStackTrace();
		    }
	}
}
