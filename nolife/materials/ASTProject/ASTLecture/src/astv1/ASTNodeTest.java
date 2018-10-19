package astv1;

import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.equalTo;

import org.junit.Before;
import org.junit.Test;

import astv1.ASTNode.NodeType;

public class ASTNodeTest {

	@Before
	public void setUp() throws Exception {
	}

	@Test
	public void test() {
		ASTNode node = new ASTNode(NodeType.ID,"x");
		assertThat(node.visit(), equalTo("x"));
		node = new ASTNode(NodeType.PLUS,new ASTNode(NodeType.ID,"x"),
					new ASTNode(NodeType.ID,"y"));
		assertThat(node.visit(), equalTo("x + y"));
		node = new ASTNode(NodeType.MINUS,new ASTNode(NodeType.ID,"x"),
				new ASTNode(NodeType.ID,"y"));
		assertThat(node.visit(), equalTo("x - y"));
	}

}
