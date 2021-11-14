高级数据结构
一、自顶向下伸展树
沿着树向下搜索某一个结点X时候，将搜索路径上的结点及其子树进行移走。创建两个空树左树和右树，没有被移走的结点叫做中树，在伸展操作的过程中：

当前遍历结点X 是树的中树
左树L保留小于X的结点
右树R 保留大于X的结点
二、红黑树
红黑树是一棵二叉搜索树，它在每个节点增加了一个存储位记录节点的颜色，可以是RED,也可以是BLACK；通过任意一条从根到叶子简单路径上颜色的约束，红黑树保证最长路径不超过最短路径的二倍，因而近似平衡。

具体性质如下：

每个节点颜色不是黑色，就是红色

根节点是黑色的

如果一个节点是红色，那么它的两个子节点就是黑色的（没有连续的红节点）

对于每个节点，从该节点到其后代叶节点的简单路径上，均包含相同数目的黑色节点

三、确定性跳跃表
定义:如果至少存在一个指针从一个元素指向另一个元素，称两个元素是链接的。

定义:两个在高度为h链接的元素间的间隙容量等于它们之间高度为 h-1 的元素的个数。

1-2-3确定性跳跃表定义：满足如下性质的跳跃表：每两个高度相同的结点之间的间隙容量不能超过3个。

四、AA树
AA-Tree是RB-Tree的一种变型，是红黑树
“红”结点只能作为结点的右孩子，“黑”结点均可；
结点中的level相当于RBT中的结点的黑高度；
“红”结点的level与其父结点的level相同；
“黑”结点的level比其父结点的level小1；
左孩子的level比父结点小1，右孩子的level比父结点小0或1；
禁止出现的2中情况：

1、出现连续向右的水平方向链，即在RB-Tree中不能出现连续2个红结点；

2、出现向左的水平方向链，这是AA-Tree中规定的；

五、treap树
Treap=Tree+Heap。Treap 本身是一棵二叉搜索树，它的左子树和右子树也分别是一个Treap，和一般的二叉搜索树不同的是，Treap 纪录一个额外的数据，就是优先级。

Treap每个节点的数据域包含2个值，key和weight。

key值，和原来的二叉搜索树一样，满足左子树<根节点<右子树。

weight值，随机产生。在Treap中weight值满足堆的性质，根节点的weight值小于等于(或大于等于)左右儿子节点。

六、配对堆
配对堆采用左儿子和右兄弟的表示方法。存在额外的链，如果节点是最左儿子，则链指向父节点，如果不是，则指向左兄弟。把这个数据成员叫做prev。