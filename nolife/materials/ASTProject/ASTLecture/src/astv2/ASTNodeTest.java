package astv2;

import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.equalTo;

import org.junit.Before;
import org.junit.Test;

public class ASTNodeTest {

	@Before
	public void setUp() throws Exception {
	}

	@Test
	public void test() {
		ASTNode node = new IdNode("x");
		assertThat(node.visit(), equalTo("x"));
		node = new AddNode(new IdNode("x"),
					new IdNode("y"));
		assertThat(node.visit(), equalTo("x + y"));
		node = new SubNode(new IdNode("x"),
				new IdNode("y"));
		assertThat(node.visit(), equalTo("x - y"));
	}

}
