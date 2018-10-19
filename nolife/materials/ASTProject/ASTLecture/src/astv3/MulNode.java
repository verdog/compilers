package astv3;

public class MulNode extends BinaryNode {

	@Override
	public void accept(Visitor v) {
		v.visit(this);
	}

}
