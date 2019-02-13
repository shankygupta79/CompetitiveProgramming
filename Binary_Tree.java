package BinaryTree;
import java.util.Scanner;
import java.util.LinkedList;
import java.lang.Math;
public class BinaryTree {
	BinaryTree()
	{
		Scanner s=new Scanner(System.in);
		this.root=takeInput(s,null,false);
	}
	private class Node{
		int data;
		Node left;
		Node right;
		
		Node(int data,Node left,Node right)
		{
			this.data=data;
			this.left=left;
			this.right=right;
		}
	}
		Node root=null;
		int size=0;
		
		private Node takeInput(Scanner s,Node parent,boolean isLeft)
		{
			if(parent==null)
			{
				System.out.println("Enter data of root parent --> ");
			}else {
				if(isLeft){
					System.out.println("Enter data for Left Child of "+parent.data+" --> ");
				}else {
					System.out.println("Enter data for Right Child of "+parent.data+" --> ");
				}	
			}
			int x=s.nextInt();
			Node Node=new Node(x,null,null);
			this.size++;
			
			boolean choice=false;
			System.out.println("You want to enter left child of "+Node.data+"? ");
			choice=s.nextBoolean();
			if(choice==true)
			{
				Node.left=takeInput(s, Node, true);
			}
			
			choice=false;
			System.out.println("You want to enter right of "+Node.data+" child?");
			choice=s.nextBoolean();
			if(choice==true)
			{
				Node.right=takeInput(s, Node, false);
			}
			return Node;
		}
		
		public void Display()
		{
			this.display(this.root);
		}
		private void display(Node Node)
		{
			String str="";
			if (Node.left!=null)
			{
				str=str+Node.left.data+"=>";
			}else{
				str=str+"END=>";
			}
			str=str+Node.data;
			if (Node.right!=null)
			{
				str=str+"<="+Node.right.data;
			}else{
				str=str+"<=END";
			}
			System.out.println(str);
			str=str+Node.data;
			if (Node.left !=null)
			{
				this.display(Node.left);
			}
			if (Node.right !=null)
			{
				this.display(Node.right);
			}
		}
		public void Hieght()
		{
			System.out.println( this.hieght(this.root));
		}
		private int hieght(Node Node)
		{
			
			if(Node==null){
				return -1;
			}
			int lefthieght=this.hieght(Node.left);
			int righthieght=this.hieght(Node.right);
			
			int hieght=Math.max(lefthieght, righthieght)+1;
			return hieght;
		}
		public void PreOrder()
		{
			this.preorder(this.root);
		}
		//Firstly Node is printed then its left is printed then its right is printed!
		private void preorder(Node Node)
		{
			if(Node==null){
				return;
			}
			System.out.print(Node.data+",");
			preorder(Node.left);
			preorder(Node.right);
		}
		public void PostOrder()
		{
			this.postorder(this.root);
		}
		//Firstly Node's left is printed then its right is printed and then Node itself.
		private void postorder(Node Node)
		{
			if(Node==null){
				return;
			}
			postorder(Node.left);
			postorder(Node.right);
			System.out.print(Node.data+",");
		}
		public void INOrder()
		{
			this.inorder(this.root);
		}
		//Firstly Node's left is printed then Node then its right is printed !
		private void inorder(Node Node)
		{
			if(Node==null){
				return;
			}
			inorder(Node.left);
			System.out.print(Node.data+",");
			inorder(Node.right);
		}
		public void levelOrder()
		{
			this.levelOrder(this.root);
		}
		private void levelOrder(Node Node)
		{
			LinkedList<Node> queue=new LinkedList<>();
			queue.add(this.root);
			while(!queue.isEmpty() ){
				Node rv=queue.removeFirst();
				System.out.print(rv.data+", ");
				if(rv.left!=null){
					queue.addLast(rv.left);
				}if(rv.right!=null){
					queue.addLast(rv.right);
				}
			}
		}
}
