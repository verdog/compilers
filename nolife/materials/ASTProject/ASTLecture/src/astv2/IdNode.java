package astv2;

public class IdNode extends ASTNode {
	private String name;
	
	public IdNode(String name) {
		super();
		this.name = name;
	}

	@Override
	public String visit() {
		return name;	
	}

}
