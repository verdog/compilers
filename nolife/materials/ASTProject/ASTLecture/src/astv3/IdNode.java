package astv3;

public class IdNode extends ASTNode {
	private String name;
	
	public IdNode() {
	}

	@Override
	public void accept(Visitor v) {
		v.visit(this);
	}

	public String getName() {
		return name;
	}

	public void setName(String n) {
		name = n;
	}

	@Override
	public ASTNode addChild(ASTNode c) {
		return this;
	}

	@Override
	public ASTNode addLabel(String label) {
		name = label;
		return this;
	}
}
