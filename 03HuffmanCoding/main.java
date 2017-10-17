import java.util.*;
import java.io.*;

public class main {

	public static void main(String[] args) {

		HuffmanLinkedList hfmLinkedList = new HuffmanLinkedList();
		HuffmanBinaryTree hfmBinaryTree = new HuffmanBinaryTree();
		
    	try {
    		File myFile = new File(args[0]);
    		FileReader fr = new FileReader(myFile);
    		
    		FileWriter fw1 = new FileWriter(args[1]);
    		PrintWriter pw1 = new PrintWriter(fw1);
    		
    		FileWriter fw2 = new FileWriter(args[2]);
    		PrintWriter pw2 = new PrintWriter(fw2);
    		
    		FileWriter fw3 = new FileWriter(args[3]);
    		PrintWriter pw3 = new PrintWriter(fw3);
    		
    		FileWriter fw4 = new FileWriter(args[4]);
    		PrintWriter pw4 = new PrintWriter(fw4);
    		
    		FileWriter fw5 = new FileWriter(args[5]);
    		PrintWriter pw5 = new PrintWriter(fw5);

    		Scanner sn = new Scanner(fr);  		
    		
    		while(sn.hasNext()) { 
    			//the first element is 'string'
    			String chStr = sn.next();
    			//the second element is 'integer'
    			int prob = sn.nextInt();
    			
    			//to be called from main() to construct Huffman Linked List.
    			hfmLinkedList.constructHuffmanLList(chStr, prob);
    			
    			hfmLinkedList.printList(pw5);
    		}
    		
    		listBinTreeNode root = hfmBinaryTree.constructHuffmanBinTree(hfmLinkedList,pw5);
    		hfmBinaryTree.constructCharCode(root, "", pw1);

    		pw2.println("T.chStr" + "\t\t" + "T.prob" + "\t\t"+ "T.next.chStr" + "\t"+ "T.left.chStr" + "\t" + "T.right.chStr");
    		pw2.println("-------------------------------------------------------------------------------");
    		hfmBinaryTree.preOrderTraversal(pw2, root);
    		
    		pw3.println("T.chStr" + "\t\t" + "T.prob" + "\t\t"+ "T.next.chStr" + "\t"+ "T.left.chStr" + "\t" + "T.right.chStr");
    		pw3.println("-------------------------------------------------------------------------------");
    		hfmBinaryTree.inOrderTraversal(pw3, root);
    		
    		pw4.println("T.chStr" + "\t\t" + "T.prob" + "\t\t"+ "T.next.chStr" + "\t"+ "T.left.chStr" + "\t" + "T.right.chStr");
    		pw4.println("-------------------------------------------------------------------------------");
    		hfmBinaryTree.postOrderTraversal(pw4, root);
    		
    		fr.close();
    		fw1.close();
    		pw1.close();
    		fw2.close();
    		pw2.close();
    		fw3.close();
    		pw3.close();
    		fw4.close();
    		pw4.close();
    		fw5.close();
    		pw4.close();
    		sn.close();
    		
    	}catch(Exception e) {}
		

	}
	

}
