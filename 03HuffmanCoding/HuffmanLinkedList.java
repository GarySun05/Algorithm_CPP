import java.io.PrintWriter;

public class HuffmanLinkedList {

	listBinTreeNode listHead;
	listBinTreeNode oldListHead;
	
	HuffmanLinkedList(){
		listHead = new listBinTreeNode("dummy", 0);
		oldListHead = listHead;
	}
	
	public void constructHuffmanLList(String chStr, int prob) {
		
		listBinTreeNode spot = findSpot(prob);
		
		//make a new node with chStr and probability
		listBinTreeNode newNode = new listBinTreeNode(chStr, prob);

		//inserting newNode between spot and spot.next;
		listInsert(spot, newNode);	
	}
	
	public listBinTreeNode findSpot(int prob) {	
		
		listBinTreeNode temp = listHead;
		
		if(temp.prob >= prob) {
			return temp;
		}
		
		while(temp.next != null && temp.next.prob < prob) {	
			temp = temp.next;	
		}
		
		return temp;
	}
	
	public void listInsert(listBinTreeNode spot, listBinTreeNode newNode) {

		if(spot.prob == 0) {
			newNode.next = listHead.next;
			listHead.next = newNode;
		}else if(spot != null && spot.prob < newNode.prob) {
			newNode.next = spot.next;
			spot.next = newNode;
		}
	}
	
	public boolean isEmpty(){
		if(listHead == null)
			return true;
		else
			return false;
	}
	
	public void printList(PrintWriter pw){

		listBinTreeNode tempNode = listHead;
		pw.write("listHead -->" + "(\"" +tempNode.chStr + "\"," + tempNode.prob + ",");

		while (tempNode.next != null) {
			tempNode = tempNode.next;
			pw.write("\""+ tempNode.chStr + "\")-->(\"" + tempNode.chStr + "\"," + tempNode.prob + ",");
		} 
		
		pw.write("NULL)" + "-->" + "NULL");
		pw.println("");
	}
		

}
