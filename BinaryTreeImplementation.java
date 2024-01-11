import java.util.Scanner;
public class BinaryTreeImplementation {

    public BinaryTreeImplementation(){
        //constructor for the binary tree
    }

    public static class Node{
        int value;
        Node left;
        Node right;

        public Node(int value){
            this.value = value;
        }
    }

    private Node root;
    
    public void insert(Scanner sc){
        System.out.println("Enter the data for the root node: ");
        int value = sc.nextInt();
        root = new Node(value);
        populate(root, sc);
    }

    //recursively adds left and right child to the root node as per user inputs.
    private void populate(Node node, Scanner sc){
        System.out.println("Do you want to insert to the left of "+node.value);
        boolean left = sc.nextBoolean();

        if(left){
            //means the user wants to insert the node
            System.out.println("Enter data for the left child of "+node.value);
            int value = sc.nextInt();
            node.left = new Node(value);
            populate(node.left, sc);
        }

        System.out.println("Do you want to insert to the right of "+node.value);
        boolean right = sc.nextBoolean();

        if(right){
            //means the user wants to insert the node
            System.out.println("Enter data for the right child of "+node.value);
            int value = sc.nextInt();
            node.right = new Node(value);
            populate(node.right, sc);
        }
    }

    public void display(){
        display(this.root, "");
    }

    private void display(Node node, String intend){
        if(node==null){
            return;
        }

        System.out.println(intend + node.value);
        display(node.left, intend+"\t");
        display(node.right, intend+"\t");
    }

    public void prettyDisplay() {
        prettyDisplay(root, 0);
      }
    
      private void prettyDisplay(Node node, int level) {
        if (node == null) {
          return;
        }
    
        prettyDisplay(node.right, level + 1);
    
        if (level != 0) {
          for (int i = 0; i < level - 1; i++) {
            System.out.print("|\t\t");
          }
          System.out.println("|------->" + node.value);
        } else {
          System.out.println(node.value);
        }

        prettyDisplay(node.left, level + 1);
      }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BinaryTreeImplementation myTree = new BinaryTreeImplementation();
        myTree.insert(sc);
        myTree.display();
        myTree.prettyDisplay();
    }
}
