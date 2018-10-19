package astv3;

public class DivNode extends BinaryNode {

	@Override
	public void accept(Visitor v) {
		v.visit(this);
	}

}
