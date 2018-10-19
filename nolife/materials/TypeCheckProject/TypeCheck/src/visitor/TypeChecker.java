/**
 * 
 */
package visitor;

import java.util.HashMap;

import astv3.ASTNode;
import astv3.AddNode;
import astv3.AssignNode;
import astv3.BinaryNode;
import astv3.DeclNode;
import astv3.DivNode;
import astv3.FloatTypeNode;
import astv3.IdDeclNode;
import astv3.IdDefNode;
import astv3.IdRefNode;
import astv3.IntTypeNode;
import astv3.MulNode;
import astv3.ProgramNode;
import astv3.SubNode;
import astv3.VarDeclsNode;

/**
 * @author carr
 *
 */
public class TypeChecker implements Visitor {

	private final int INTEGER = 0;
	private final int FLOAT = 1;
	private final int NOTYPE = 2;
	private int declType;
	private int exprType;
	private String id;
	private HashMap<String,Integer> symtab = new HashMap<String,Integer>();
	/**
	 * 
	 */
	public TypeChecker() {
	}
	
	private void typeCheck(BinaryNode n) {
		n.getLeft().accept(this);
		int leftType = exprType;
		n.getRight().accept(this);
		int rightType = exprType;
		
		if (leftType == rightType)
			exprType = leftType;
		else if (leftType == NOTYPE || rightType == NOTYPE)
			exprType = NOTYPE;
		else {
			System.err.println("Type error");
			exprType = NOTYPE;
		}		
	}

	/* (non-Javadoc)
	 * @see visitor.Visitor#visit(astv3.AddNode)
	 */
	@Override
	public void visit(AddNode n) {
		typeCheck(n);
	}

	/* (non-Javadoc)
	 * @see visitor.Visitor#visit(astv3.SubNode)
	 */
	@Override
	public void visit(SubNode n) {
		typeCheck(n);
	}

	/* (non-Javadoc)
	 * @see visitor.Visitor#visit(astv3.DivNode)
	 */
	@Override
	public void visit(DivNode n) {
		typeCheck(n);
	}

	/* (non-Javadoc)
	 * @see visitor.Visitor#visit(astv3.MulNode)
	 */
	@Override
	public void visit(MulNode n) {
		typeCheck(n);
	}

	/* (non-Javadoc)
	 * @see visitor.Visitor#visit(astv3.IdNode)
	 */
	@Override
	public void visit(IdRefNode n) {
		if (symtab.containsKey(n.getLabel()))
			exprType = symtab.get(n.getLabel());
		else {
			System.err.println("Undeclared variable: "+n.getLabel());
			exprType = NOTYPE;
		}
	}

	/* (non-Javadoc)
	 * @see visitor.Visitor#visit(astv3.DeclNode)
	 */
	@Override
	public void visit(DeclNode declNode) {
		for (ASTNode n : declNode.getChildren())
			n.accept(this);
	}

	/* (non-Javadoc)
	 * @see visitor.Visitor#visit(astv3.ProgramNode)
	 */
	@Override
	public void visit(ProgramNode programNode) {
		for (ASTNode n : programNode.getChildren())
			n.accept(this);
	}

	/* (non-Javadoc)
	 * @see visitor.Visitor#visit(astv3.VarDeclsNode)
	 */
	@Override
	public void visit(VarDeclsNode varDeclsNode) {
		for (ASTNode n : varDeclsNode.getChildren())
			n.accept(this);
	}

	/* (non-Javadoc)
	 * @see visitor.Visitor#visit(astv3.IntTypeNode)
	 */
	@Override
	public void visit(IntTypeNode intTypeNode) {
		declType = INTEGER;
	}

	/* (non-Javadoc)
	 * @see visitor.Visitor#visit(astv3.FloatTypeNode)
	 */
	@Override
	public void visit(FloatTypeNode floatTypeNode) {
		declType = FLOAT;
	}

	/* (non-Javadoc)
	 * @see visitor.Visitor#visit(astv3.AssignNode)
	 */
	@Override
	public void visit(AssignNode assignNode) {
		assignNode.getLHS().accept(this);
		int lhsType = exprType;
		assignNode.getRHS().accept(this);
		int rhsType = exprType;
		
		if (lhsType != rhsType)
			System.err.println("Assignment type conflict");
	}

	@Override
	public void visit(IdDeclNode idDeclNode) {
		id = idDeclNode.getLabel();
		symtab.put(id, declType);
	}

	@Override
	public void visit(IdDefNode n) {
		if (symtab.containsKey(n.getLabel()))
			exprType = symtab.get(n.getLabel());
		else {
			System.err.println("Undeclared variable: "+n.getLabel());
			exprType = NOTYPE;
		}
	}

}
