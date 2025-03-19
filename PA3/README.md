## AVL MAP
*By Lauri Calvert*

**Makefile Usage**
I included a makefile in the project that is ready to be used. The make can either be used with just *make* or *make mainexe* the program can then be ran with the executable *./mainexe*

*I have also included a screenshot of a successful build using this method in the project.*

### Questions
An AVL tree maintains logarithmic complexity due to its ability to keep a BST from becoming degenerate and therefore making it so that the trees height remains logarithmic. Keeping height logarithmic rather than letting it tend towards n makes it so that during searches not every node needs to be visited. The AVL tree is able to do this because of its insertion sorting of the tree where it can perform left or right rotations based on a trees balance to move the tree to a more balanced (and more logarithmic) position.

My implementation uses these ideas by making sure that whenever there is an insertion or deletion the heights and balances of nodes are checked to see if rebalancing is necessary.

There are a few important trade offs to note when working with a std map vs an AVL map. An AVL map is very strict about balance, so this helps to make performance more guaranteed, while a std map which is implemented using Red-Black trees is looser on its balance allowing for less need to constantly check balance. This can be preferable if you know you are going to have a lot of changes being made to the tree as they can be made faster. 