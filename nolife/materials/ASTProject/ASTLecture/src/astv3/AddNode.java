/**
 * 
 */
package astv3;

/**
 * @author carr
 *
 */
public class AddNode extends BinaryNode {
	
	public AddNode() {
		super();
	}

	@Override
	public void accept(Visitor v) {
		v.visit(this);
	}

}
