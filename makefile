A4.exe: driver.o BinaryTree.o RedBlackTree.o TreeNode.o Node.o
	g++ driver.o BinaryTree.o RedBlackTree.o TreeNode.o Node.o -o A4.exe

driver.o: driver.cpp	
	g++ -c driver.cpp -o driver.o

TreeNode.o: TreeNode.cpp 	
	g++ -c TreeNode.cpp -o TreeNode.o

RedBlackTree.o: RedBlackTree.cpp 	
	g++ -c RedBlackTree.cpp -o RedBlackTree.o
	
BinaryTree.o: BinaryTree.cpp 	
	g++ -c BinaryTree.cpp -o BinaryTree.o

Node.o: Node.cpp 	
	g++ -c Node.cpp -o Node.o

clean:	
	rm -f driver.o BinaryTree.o RedBlackTree.o TreeNode.o Node.o -o A4.exe
