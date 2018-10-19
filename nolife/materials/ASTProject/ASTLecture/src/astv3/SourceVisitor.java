package astv3;

public class SourceVisitor implements Visitor {

	private String src;

	public SourceVisitor() {
		super();
		src = "";
	}
	
	@Override
	public void visit(AddNode n) {
		n.left.accept(this);
		src += " + ";
		n.right.accept(this);
	}

	@Override
	public void visit(SubNode n) {
		n.left.accept(this);
		src += " - ";
		n.right.accept(this);
	}

	@Override
	public void visit(DivNode n) {
		n.left.accept(this);
		src += " / ";
		n.right.accept(this);
	}

	@Override
	public void visit(MulNode n) {
		n.left.accept(this);
		src += " * ";
		n.right.accept(this);
	}
	
	@Override
	public void visit(IdNode n) {
		src += n.getName();
	}

	public String getSrc() {
		return src;
	}

}
