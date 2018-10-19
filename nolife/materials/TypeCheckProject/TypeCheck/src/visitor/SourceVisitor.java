package visitor;

import astv3.ASTNode;
import astv3.AddNode;
import astv3.AssignNode;
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

public class SourceVisitor implements Visitor {

	private String src;

	public SourceVisitor() {
		super();
		src = "";
	}
	
	@Override
	public void visit(AddNode n) {
		n.getLeft().accept(this);
		src += " + ";
		n.getRight().accept(this);
	}

	@Override
	public void visit(SubNode n) {
		n.getLeft().accept(this);
		src += " - ";
		n.getRight().accept(this);
	}

	@Override
	public void visit(DivNode n) {
		n.getLeft().accept(this);
		src += " / ";
		n.getRight().accept(this);
	}

	@Override
	public void visit(MulNode n) {
		n.getLeft().accept(this);
		src += " * ";
		n.getRight().accept(this);
	}
	
	@Override
	public void visit(IdRefNode n) {
		src += n.getLabel();
	}

	public String getSrc() {
		return src;
	}

	@Override
	public void visit(DeclNode declNode) {
		declNode.getChild(0).accept(this);
		for (int i = 1; i < declNode.getChildren().size()-1; i++) {
			declNode.getChild(i).accept(this);
			src += ", ";
		}
		declNode.getChild(declNode.getChildren().size()-1).accept(this);
		src += ";";
	}

	@Override
	public void visit(ProgramNode programNode) {
		for (ASTNode node : programNode.getChildren())
			node.accept(this);
	}

	@Override
	public void visit(VarDeclsNode varDeclsNode) {
		for (ASTNode node : varDeclsNode.getChildren()) {
			node.accept(this);
			src += "\n";
		}
	}

	@Override
	public void visit(IntTypeNode intTypeNode) {
		src += "int ";
	}

	@Override
	public void visit(FloatTypeNode floatTypeNode) {
		src += "float ";
	}

	@Override
	public void visit(AssignNode assignNode) {
		assignNode.getChild(0).accept(this);
		src += " = ";
		assignNode.getChild(1).accept(this);
	}

	@Override
	public void visit(IdDeclNode idDeclNode) {
		src += idDeclNode.getLabel();
	}

	@Override
	public void visit(IdDefNode idDefNode) {
		src += idDefNode.getLabel();
	}

}
