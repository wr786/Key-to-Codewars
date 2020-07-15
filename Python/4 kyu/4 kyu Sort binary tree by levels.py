def tree_by_levels(node):
    ret, queue = [], [node]
    while len(queue):
        curNode, queue = queue[0], queue[1:]
        if curNode: 
            ret.append(curNode.value)
            queue.extend([curNode.left, curNode.right])
    return ret
    