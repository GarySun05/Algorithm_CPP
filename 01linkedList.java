import java.io.*;
import java.util.*;

public class linkedList {

	static class listNode{
		public String data;
		public listNode next;
		
		listNode(){
			next = null;
		}
		
		listNode(String ele){
			data = ele;
			next = null;
		}
		
	}

	public listNode listHead = new listNode();
	
	public linkedList(String ele) {
		listHead.data = ele;
	}
	
	public boolean isEmpty() {
        if(listHead == null){
            return true;
        }
        return false;
		
	}
	
	public void listInsert(String ele) {
        listNode curr = listHead.next;
        listNode prev = listHead;
        listNode newNode = new listNode(ele);
        
        if(curr == null){
            newNode.next = curr;
            listHead.next = newNode;
        }else{
            while(curr.next != null) {
            	if(newNode.data.compareToIgnoreCase(curr.data) < 0){
            		newNode.next = curr;
            		prev.next = newNode;
            		return;
            	}else {
            		curr = curr.next;
            		prev = prev.next;
            	}
            }

            if(newNode.data.compareToIgnoreCase(curr.data) < 0) {
	            newNode.next = curr;
	            prev.next = newNode;     
            }else {
            	curr.next = newNode;
            }
        }
        return;
	}
	
	public void listDelete(String ele) {

        listNode curr = listHead.next;
        listNode prev = listHead;

        while((curr != null)&&(curr.data.equals(ele))){
            prev = prev.next;
            curr = curr.next;
        }

        if(curr != null){
            prev.next = curr.next;
            curr.next = null;
        }
        return;
	}
	
	public void printList(String ele, PrintWriter pw) {
		listNode curr = listHead;
		pw.println("Insert (" + ele + "):\n");
		pw.print("listHead-->");

        while(true){
            if(curr.next == null){
            	pw.println("("+ curr.data + ", NULL)");
                return;
            }else{
            	pw.print("(" + curr.data + "," + curr.next.data + ")-->");
            }
            curr = curr.next;
		}
	}

	
	public static void main(String[] args){
		
	linkedList ls = new linkedList("dummy");
		try {
		File myFileR = new File(args[0]);
		FileReader fr = new FileReader(myFileR);
	     
	    FileWriter fw = new FileWriter(args[1]);
	    PrintWriter pw = new PrintWriter(fw);

		Scanner myScan = new Scanner(fr);
		int icount = 0;
		
		while(myScan.hasNext() && icount < 15) {
			String ele = myScan.next();		
			ls.listInsert(ele);
			System.out.println(ele);
			ls.printList(ele, pw);		
			icount++;
		}
		
		fr.close();
		myScan.close();
		pw.close();
		}catch(Exception e) {}
		
	}

}