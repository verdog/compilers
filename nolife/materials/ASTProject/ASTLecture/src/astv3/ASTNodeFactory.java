package astv3;

public class ASTNodeFactory {
	
	public ASTNode makeASTNode(String nodeType) {
		if (nodeType == "AddNode")
			return new AddNode();
		else if (nodeType == "SubNode")
			return new SubNode();
		else if (nodeType == "DivNode")
			return new DivNode();
		else if (nodeType == "MulNode")
			return new MulNode();
		else if (nodeType == "IdNode")
			return new IdNode();
		else
			return null;
	}
}
