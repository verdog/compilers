package astv3;

public abstract class ASTNode {
	public abstract void accept(Visitor v);
	public abstract ASTNode addChild(ASTNode c);
	public abstract ASTNode addLabel(String label);
}
