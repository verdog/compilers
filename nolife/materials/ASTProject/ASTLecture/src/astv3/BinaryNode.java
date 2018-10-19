package astv3;

public abstract class BinaryNode extends ASTNode {
	protected ASTNode left, right;
	
	public ASTNode addChild(ASTNode node) {
		if (left == null)
			left = node;
		else if (right == null)
			right = node;
		return this;
	}
	
	public ASTNode addLabel(String label) {
		return this;
	}
	
	public ASTNode getLeft() { return left; }
	public ASTNode getRight() { return right; }
}
