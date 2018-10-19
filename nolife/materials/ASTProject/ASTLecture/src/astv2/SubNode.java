package astv2;

public class SubNode extends ASTNode {
	private ASTNode left, right;
	
	public SubNode(ASTNode left, ASTNode right) {
		this.left = left;
		this.right = right;
	}
	
	@Override
	public String visit() {
		return left.visit() + " - " + right.visit();
	}

}
