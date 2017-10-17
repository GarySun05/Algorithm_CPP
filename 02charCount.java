import java.io.*;
import java.util.*;

public class main {
public static int[] charCounts = new int[256];
    
//to cast char to integer 
    public static void charIn(char charWord) {
    	int index = (int)charWord;
    	charCounts[index]++;
    }
    
//cast index to charactor
    public static void printAry(PrintWriter pw){
    	for(int index = 0; index < charCounts.length; index++) {
    		if(charCounts[index] > 0) {
    			pw.println((char)index + "  "+ charCounts[index]);
    			
    		}
    	}
    }
   
    public static void main(String[] args) {  
//to initialize the char array
    	for(int i = 0; i < charCounts.length; i++) {
    		charCounts[i] = 0;
    	}
    	
    	try {
    		File myFile = new File(args[0]);
    		FileReader fr = new FileReader(myFile);
    		
    		FileWriter fw = new FileWriter(args[1]);
    		PrintWriter pw = new PrintWriter(fw);
    		
    		Scanner sn = new Scanner(fr);  		
    		
    		while(sn.hasNext()) {
    			String word = sn.next();
    			
    			//convert a word to a number
    	        for (byte b : word.getBytes()) {  
    	            char charWord = (char)b;
    	            charIn(charWord);
    	        }    	        
    		}
    		
    		printAry(pw);
    		
    		fr.close();
    		fw.close();
    		pw.close();
    		sn.close();
    		
    	}catch(Exception e) {}
    	
    }
}
