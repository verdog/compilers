/**
 * 
 */
package astv3;

import visitor.Visitor;

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
