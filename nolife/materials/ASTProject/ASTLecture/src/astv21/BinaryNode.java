package astv21;

public abstract class BinaryNode extends ASTNode {
	protected ASTNode left, right;
	
	@Override
	public String visit() {
		return left.visit() + getOp() + right.visit();
	}

	public abstract String getOp();

	public BinaryNode(ASTNode left, ASTNode right) {
		super();
		this.left = left;
		this.right = right;
	}
}
