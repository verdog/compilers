package astv3;

public class CountVisitor implements Visitor {
	private String id;
	private int count = 0;
	
	public CountVisitor(String id) {
		this.id = id;
	}
	@Override
	public void visit(AddNode n) {
		n.getLeft().accept(this);
		n.getRight().accept(this);
	}

	@Override
	public void visit(SubNode n) {
		n.getLeft().accept(this);
		n.getRight().accept(this);
	}

	@Override
	public void visit(DivNode n) {
		n.getLeft().accept(this);
		n.getRight().accept(this);
	}

	@Override
	public void visit(MulNode n) {
		n.getLeft().accept(this);
		n.getRight().accept(this);
	}

	@Override
	public void visit(IdNode n) {
		if (n.getName().equals(id))
			count++;
	}

}
