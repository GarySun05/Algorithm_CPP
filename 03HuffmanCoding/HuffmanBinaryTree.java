import java.io.PrintWriter;

public class HuffmanBinaryTree {
	
	listBinTreeNode root;
	
	public listBinTreeNode constructHuffmanBinTree(HuffmanLinkedList hfm,PrintWriter pw5){
		listBinTreeNode dummy = new listBinTreeNode("dummy",0);
		hfm.oldListHead = dummy;
		hfm.oldListHead.next = hfm.listHead.next;
		
		root = hfm.listHead.next;
		
		pw5.println("\n");
		while(root.next != null) {
			listBinTreeNode newNode = new listBinTreeNode("", 0);
			newNode.prob = root.prob + root.next.prob;
			newNode.chStr = root.chStr + root.next.chStr;			
			newNode.left = root;
			newNode.right = root.next;
			
			newNode.printNode(newNode, pw5);
			
			listBinTreeNode spot = hfm.findSpot(newNode.prob);
			hfm.listInsert(spot,newNode);
		
			hfm.listHead = root.next.next;
			root = hfm.listHead;
			
			hfm.printList(pw5);
			
		}
		
		return root;	
	}
	
	HuffmanBinaryTree(){}
	
	public void constructCharCode(listBinTreeNode T, String code, PrintWriter pw) {

        if(T == null) {
        	System.out.println("This is an empty tree!");
        	return;
        }else if(isLeaf(T)){
            pw.println(T.chStr + "\t" + code);
        }else {        
	        constructCharCode (T.left, code + "0", pw);
	        constructCharCode (T.right, code + "1", pw); 
        }
	}
	
	public void preOrderTraversal(PrintWriter pw2, listBinTreeNode root) {

		if(root == null) {
			return;
		}else{	
			root.printNode(root, pw2);
			preOrderTraversal(pw2,root.left);
			preOrderTraversal(pw2,root.right);
		}
	}
	
	public void inOrderTraversal(PrintWriter pw3, listBinTreeNode root) {	
		
		if(root == null) {
			return;
		}else{				
			preOrderTraversal(pw3,root.left);
			root.printNode(root, pw3);
			preOrderTraversal(pw3,root.right);
		}
	}
	
	public void postOrderTraversal(PrintWriter pw4, listBinTreeNode root) {	
		
		if(root == null) {
			return;
		}else{				
			preOrderTraversal(pw4,root.left);
			preOrderTraversal(pw4,root.right);
			root.printNode(root, pw4);
		}
	}
	
	public boolean isLeaf(listBinTreeNode root) {
		if(root.left == null && root.right == null) {
			return true;
		}else
			return false;
	}		
		

}
