package Linked_List;


/**
 * @author Shubham Gupta
 * @email shankygupta79@gmail.com
 * @date 26-Sept-2018
 */

public class LinkedList 
{
	private class Node
	{
		int data;
		Node next;
	}
	//Now only the Linked List Class can access this Node class
	
	private Node head;
	private Node tail;
	private int size;
	
	//O(n)
	public void display()
	{
		Node temp=this.head;  //Head call
 		
		while(temp!=null) 
		{
			System.out.print(temp.data + " , ");
			temp=temp.next;    
		}
	}
	//O(1)
	public void addLast(int item)
	{
		//Create New Node
		Node nn=new Node();
		nn.data=item;
		nn.next=null;
		
		//Attach
		if(this.size>=1)
		{
			this.tail.next=nn;
		}
		
		if(this.size==0)
		{
			this.head=nn;
			this.tail=nn;
			this.size++;
		}
		else
		{
			this.tail=nn;  
			this.size++;
		}
	}
	//O(1)
	public void AddFirst(int item)
	{
		Node nn=new Node();
		nn.data=item;
		nn.next=null;
		
		if(this.size==0)
		{
			this.head=nn;
			this.tail=nn;
			this.size++;
		}else {
			nn.next=this.head; 
			this.head=nn; 
			this.size++;
		}
	}
	//O(1)
	public int getFirst()
			{
				if(this.size==0)
				{
					System.out.println("Empty List");
				}
				return this.head.data;
			}
	//O(1)
	public int getLast()
	{
		if(this.size==0)
		{
			System.out.println("Empty List");
		}
		return this.tail.data;
	}
	//O(n)
	public void getAt(int index)
	{
		if(this.size==0)
		{
			System.out.println("Empty List");
			return;
		}
		if(index<0 || index>=this.size)
		{
			System.out.println("Invalid Index");
			return;
		}
		Node temp=this.head;
		for(int i=0;i<index;i++)
		{
			temp=temp.next;
		}
		System.out.println(temp.data);
	}
	//O(n)
	private Node getNodeAt(int index)
	{
		if(this.size==0)
		{
			System.out.println("Empty List");
			return null;
		}
		if(index<0 || index>=this.size)
		{
			System.out.println("Invalid Index");
			return null;
		}
		Node temp=this.head;
		for(int i=0;i<index;i++)
		{
			temp=temp.next;
		}
		return temp;
	}
	//O(n)
	public void AddAt(int item,int index)
	{
		if(this.size==0){
			AddFirst(item);return;
		}else if(this.size==index){
			addLast(item);return;
		}
		if(index<0 || index>this.size){
			System.out.println("Invalid Index");
			return ;
		}
		Node nn=new Node();
		Node temp=getNodeAt(index-1);
		nn.data=item;
		nn.next=temp.next;
		temp.next=nn;
		this.size++;
	}
	//O(1)
	public void removeFirst()
	{
		if(this.size==0){
			System.out.println("Empty List");return;
		}else if(this.size==1){
			this.head=null;
			this.tail=null;
			this.size--;return;
		}
		this.head=this.head.next; 
		this.size--;
	}
	//O(n)
	public void removeLast()
	{
		if(this.size==0){
			System.out.println("Empty List");return;
		}else if(this.size==1){
			this.head=null;
			this.tail=null;
			this.size--;return;}
		Node ekPheli=getNodeAt(this.size-2);
		this.tail=ekPheli;
		ekPheli.next=null;
		this.size--;
	}
	//O(n)
	public void removeAt(int index)
	{
		if(index <0 || index >=this.size){
			System.out.println("Invalid Index");return;
		}
		if(index==0){
			removeFirst();return;
			}else if(index==this.size-1) {
				removeLast();return;
			}else {
				Node nn1=getNodeAt(index-1);
				Node nn=getNodeAt(index+1);
				nn1.next=nn;
				this.size--;
			}
	}
	public void reverseData()
	{
		int left=0;
		int right=this.size-1;
		while(left<right)
		{
			Node nleft=getNodeAt(left);
			Node nright=getNodeAt(right);
			int temp =nleft.data;
			nleft.data=nright.data;
			nright.data=temp;
			left++;
			right--;
		}
	}
	//reverse printing poinnters
	public void reversePointers()
	{
		Node prev=this.head;
		Node curr=prev.next;
		while(curr != null)
		{
			Node nXt=curr.next;
			curr.next=prev;
			
			prev=curr;
			curr=nXt;
			
		}
		
		Node temp=this.head;
		this.head=this.tail;
		this.tail=temp;
	}
	
	public int middleNode()
	{
		Node slow=this.head;
		Node fast=this.head;
		
		while(fast.next !=null && fast.next.next!=null)
		{
			slow=slow.next;
			fast=slow.next;
		}
		return slow.data;
	}
}


