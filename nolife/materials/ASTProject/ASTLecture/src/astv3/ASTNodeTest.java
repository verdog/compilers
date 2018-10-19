package astv3;

import static org.hamcrest.CoreMatchers.equalTo;
import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

public class ASTNodeTest {

	@Before
	public void setUp() throws Exception {
	}

	@Test
	public void test() {
		
		/* test x */
		
		ASTNodeFactory factory = new ASTNodeFactory();
		ASTNode node = factory.makeASTNode("IdNode")
				.addLabel("x");
		SourceVisitor v = new SourceVisitor();
		node.accept(v);
		assertThat(v.getSrc(), equalTo("x"));
		
		/* test x + y */
		
		node = factory.makeASTNode("AddNode")
				.addChild(factory.makeASTNode("IdNode")
						.addLabel("x"))
				.addChild(factory.makeASTNode("IdNode")
						.addLabel("y"));
		v = new SourceVisitor();
		node.accept(v);
		assertThat(v.getSrc(), equalTo("x + y"));
		
		/* test x - y */
		
		node = factory.makeASTNode("SubNode")
				.addChild(factory.makeASTNode("IdNode")
						.addLabel("x"))
				.addChild(factory.makeASTNode("IdNode")
						.addLabel("y"));
		v = new SourceVisitor();
		node.accept(v);
		assertThat(v.getSrc(), equalTo("x - y"));
	}

}
