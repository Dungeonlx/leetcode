---
layout: questions
title: 克隆图 第一部分
next_section: longest-palindromic-substring-part-ii
permalink: /home/
---

<div class="note info">
    <p>克隆一个图。输入的是一个Node指针。返回值是被克隆的图的Node指针。</p>

    <p>一个图的结构体定义如下：</p>
    {% highlight cpp linenos %}
    struct Node {
        std::vector neighbors;
    }
    {% endhighlight %}
</div>

<div class="note">
    有两种方法来遍历一个图。你还记得是哪<a href="http://zh.wikipedia.org/zh-cn/%E5%9B%BE%E9%81%8D%E5%8E%86" target="_blank">两种</a>吗？你能判断这个图是<a href="http://zh.wikipedia.org/zh-cn/%E5%9B%BE" target="_blank">有向图还是无向图</a>吗？
</div>

Solution:
There are two main ways to traverse a graph: Breadth-first or Depth-first. Let’s try the Breadth-first approach first, which requires a queue. For the Depth-first approach, please see Clone Graph Part II.

How does the breadth-first traversal works? Easy, as we pop a node off the queue, we copy each of its neighbors, and push them to the queue.

A straight forward breadth-first traversal seemed to work. But some details are still missing. For example, how do we connect the nodes of the cloned graph?

Before we continue, we first need to make sure if the graph is directed or not. If you notice how Node is defined above, it is quite obvious that the graph is a directed graph. Why?

For example, A can have a neighbor called B. Therefore, we may traverse from A to B. An undirected graph implies that B can always traverse back to A. Is it true here? No, because whether B could traverse back to A depends if one of B’s neighbor is A.

The fact that B can traverse back to A implies that the graph may contain a cycle. You must take extra care to handle this case. Imagine that you finished implementing without considering this case, and later being pointed out by your interviewer that your code has an infinite loop, yuck!

Let’s analyze this further by using the below example:

A simple graph
Assume that the starting point of the graph is A. First, you make a copy of node A (A2), and found that A has only one neighbor B. You make a copy of B (B2) and connects A2->B2 by pushing B2 as A2′s neighbor. Next, you find that B has A as neighbor, which you have already made a copy of. Here, we have to be careful not to make a copy of A again, but to connect B2->A2 by pushing A2 as B2′s neighbor. But, how do we know if a node has already been copied?

Easy, we could use a hash table! As we copy a node, we insert it into the table. If we later find that one of a node’s neighbor is already in the table, we do not make a copy of that neighbor, but to push its neighbor’s copy to its copy instead. Therefore, the hash table would need to store a mapping of key-value pairs, where the key is a node in the original graph and its value is the node’s copy.
