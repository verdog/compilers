/**
 * 
 */
package astv21;

/**
 * @author carr
 *
 */
public class AddNode extends BinaryNode {
	
	
	public AddNode(ASTNode left, ASTNode right) {
		super(left,right);
	}

	@Override
	public String getOp() {
		return " + ";
	}
	

}
