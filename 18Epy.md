### Вывод листьев

Для бинарного дерева поиска выведите список всех листьев (вершин, не имеющих потомков) в порядке возрастания.

__Формат ввода__  
Вводится последовательность целых чисел, оканчивающаяся нулем. Сам ноль в последовательность не входит.

```py
class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        
class BST:
    def __init__(self):
        self.root = None
        
    def insert(self, value):
        if self.root is None:
            self.root = TreeNode(value)
        else:
            self._insert_recursive(self.root, value)
            
    def _insert_recursive(self, node, value):
        if value < node.value:
            if node.left is None:
                node.left = TreeNode(value)
            else:
                self._insert_recursive(node.left, value)
        elif value > node.value:
            if node.right is None:
                node.right = TreeNode(value)
            else:
                self._insert_recursive(node.right, value)
                
    def get_leaves(self):
        leaves = []
        self._collect_leaves(self.root, leaves)
        return sorted(leaves)
        
    def _collect_leaves(self, node, leaves):
        if node is not None:
            if node.left is None and node.right is None:
                leaves.append(node.value)
            self._collect_leaves(node.left, leaves)
            self._collect_leaves(node.right, leaves)
            
def main():
    numbers = list(map(int, input().split()))
    numbers = numbers[:-1]
    
    bst = BST()
    
    for num in numbers:
        bst.insert(num)
        
    leaves = bst.get_leaves()
    
    for leaf in leaves:
        print(leaf, end='\n')
        
if __name__ == '__main__':
    main()
```
