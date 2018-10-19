package astv21;

public class SubNode extends BinaryNode {

	public SubNode(ASTNode left, ASTNode right) {
		super(left, right);
	}

	@Override
	public String getOp() {
		return " - ";
	}

}
