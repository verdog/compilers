package visitor;

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

public interface Visitor {

	public void visit(AddNode n);
	public void visit(SubNode n);
	public void visit(DivNode n);
	public void visit(MulNode n);
	public void visit(IdRefNode n);
	public void visit(DeclNode declNode);
	public void visit(ProgramNode programNode);
	public void visit(VarDeclsNode varDeclsNode);
	public void visit(IntTypeNode intTypeNode);
	public void visit(FloatTypeNode floatTypeNode);
	public void visit(AssignNode assignNode);
	public void visit(IdDeclNode idDeclNode);
	public void visit(IdDefNode idDefNode);
}
