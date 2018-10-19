/**
 * 
 */
package astv2;

/**
 * @author carr
 *
 */
public class AddNode extends ASTNode {
	
	private ASTNode left, right;
	
	public AddNode(ASTNode left, ASTNode right) {
		this.left = left;
		this.right = right;
	}
	
	@Override
	public String visit() {
		return left.visit() + " + " + right.visit();
	}

}
