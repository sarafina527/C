/**
 * DFS核心伪代码
 * 前置条件是visit数组全部设置成false
 * @param n 当前开始搜索的节点
 * @param d 当前到达的深度，也即是路径长度
 * @return 是否有解
 */
bool DFS(Node n, int d){
	if (d == 4){//路径长度为返回true，表示此次搜索有解
		return true;
	}

	for (Node nextNode in n){//遍历跟节点n相邻的节点nextNode，
		if (!visit[nextNode]){//未访问过的节点才能继续搜索

			//例如搜索到V1了，那么V1要设置成已访问
			visit[nextNode] = true;

			//接下来要从V1开始继续访问了，路径长度当然要加

			if (DFS(nextNode, d+1)){//如果搜索出有解
				//例如到了V6，找到解了，你必须一层一层递归的告诉上层已经找到解
				return true;
			}

			//重新设置成未访问，因为它有可能出现在下一次搜索的别的路径中
			visit[nextNode] = false;

		}
		//到这里，发现本次搜索还没找到解，那就要从当前节点的下一个节点开始搜索。
	}
	return false;//本次搜索无解
}