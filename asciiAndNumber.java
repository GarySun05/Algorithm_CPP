//assii and number how to convert each other.
public class asciiAndNumber{  
   
    // convert a letter to a number(1)
    public static String t1(String input) {  
        String reg = "[a-zA-Z]";  
        StringBuffer strBuf = new StringBuffer();  
        input = input.toLowerCase();  
        if (null != input && !"".equals(input)) {  
            for (char c : input.toCharArray()) {  
                if (String.valueOf(c).matches(reg)) {  
                    strBuf.append(c - 96);  
                } else {  
                    strBuf.append(c);  
                }  
            }  
            return strBuf.toString();  
        } else {  
            return input;  
        }  
    }  
   
    //convert a letter to a number. 
    public static void letterToNum(String input) {  
        for (byte b : input.getBytes()) {  
            System.out.print(b - 96);  
        }  
    }  
   
    // convert a number to a letter.
    public static void numToLetter(String input) {  
        for (byte b : input.getBytes()) {  
            System.out.print((char) (b + 48));  
        }  
    }  
   
    public static void main(String[] args) {  
        String i1 = "abcdef";  
        String i2 = "123456";  
        letterToNum(i1);  
        System.out.println();  
        numToLetter(i2);  
    }  
}