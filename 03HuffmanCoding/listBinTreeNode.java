import java.io.*;

//to create a listBinTreeNode class
public class listBinTreeNode {
	public String chStr;
	public int prob;
	public listBinTreeNode next;
	public listBinTreeNode left;
	public listBinTreeNode right;
	

	listBinTreeNode(){}
	
//		to create a constructor
	listBinTreeNode(String chStr, int prob){
		this.chStr = chStr;
		this.prob = prob;
		this.next = null;
		this.left = null;
		this.right = null;
	}
	
//		to create a 'printNode' to print all node
	public void printNode(listBinTreeNode T, PrintWriter pw){
	      if(T.next == null && T.left == null && T.right == null){
	            pw.println(T.chStr + "\t\t" + T.prob + "\t\t"+ "NULL"+"\t\t"+"NULL"+"\t\t"+"NULL");
	      }else if(T.next == null){
	            pw.println(T.chStr + "\t\t" + T.prob + "\t\t" + "NULL" + "\t\t" + T.left.chStr+"\t\t" + T.right.chStr);
	      }else if(T.left == null && T.right == null){
	            pw.println(T.chStr + "\t\t" + T.prob + "\t\t" + T.next.chStr + "\t\t"+ "NULL" + "\t\t" + "NULL\t");
	        }
	        else{
	            pw.println(T.chStr + "\t\t" + T.prob + "\t\t"+ T.next.chStr + "\t\t"+ T.left.chStr + "\t\t" + T.right.chStr);
	        }
	}

}
