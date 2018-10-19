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
		else if (nodeType == "IdDefNode")
			return new IdDefNode();
		else if (nodeType == "IdDeclNode")
			return new IdDeclNode();
		else if (nodeType == "IdRefNode")
			return new IdRefNode();
		else if (nodeType == "DeclNode")
			return new DeclNode();
		else if (nodeType == "VarDeclsNode")
			return new VarDeclsNode();
		else if (nodeType == "IntTypeNode")
			return new IntTypeNode();
		else if (nodeType == "FloatTypeNode")
			return new FloatTypeNode();
		else if (nodeType == "ProgramNode")
			return new ProgramNode();
		else if (nodeType == "AssignNode")
			return new AssignNode();
		else
			return null;
	}
}
