package astv1;

public class ASTNode {
	public static enum NodeType {PLUS,MINUS,TIMES,DIVIDE,ID};
	
	private NodeType type;
	private ASTNode left, right;
	private String name;
	
	public ASTNode(NodeType type,ASTNode left, ASTNode right) {
		this.type = type;
		this.left = left;
		this.right = right;
	}
	
	public ASTNode(NodeType type, ASTNode right) {
		this.type = type;
		this.right = right;
	}
	
	public ASTNode(NodeType type) {
		this.type = type;
	}

	public ASTNode(NodeType type,String name) {
		this.type = type;
		this.name = name;
	}
	
	public void setLeft(ASTNode left) {
		this.left = left;
	}
	
	public void setRight(ASTNode right) {
		this.right = right;
	}
	
	/* print out the source for the expression */
	
	public String visit() {
		String str = "";
		if (type == NodeType.PLUS) {
			if (left != null)
				str += left.visit();
			else
				str += "null";
			str += " + ";
			if (right != null)
				str += right.visit();
			else
				str += "null";
		}
		else if (type == NodeType.MINUS) {
			if (left != null)
				str += left.visit();
			else
				str += "null";
			str += " - ";
			if (right != null)
				str += right.visit();
			else
				str += "null";
		}
		else if (type == NodeType.TIMES) {
			if (left != null)
				str += left.visit();
			else
				str += "null";
			str += " * ";
			if (right != null)
				str += right.visit();
			else
				str += "null";
		}
		else if (type == NodeType.DIVIDE) {
			if (left != null)
				str += left.visit();
			else
				str += "null";
			str += " / ";
			if (right != null)
				str += right.visit();
			else
				str += "null";
		}
		else /* ID */ {
			str += name;
		}
		
		return str;
	}
}
