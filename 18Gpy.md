### Вывод веток

Для полученного дерева выведите список всех вершин, имеющих только одного ребёнка, в порядке возрастания.

__Формат ввода__  
Вводится последовательность целых чисел,оканчивающаяся нулем. Построить по ней дерево.

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
                
    def get_branches(self):
        branches = []
        self._collect_branches(self.root, branches)
        return sorted(branches)
        
    def _collect_branches(self, node, branches):
        if node is not None:
            if (node.left is None and node.right is not None) or (node.right is None and node.left is not None):
                branches.append(node.value)
            self._collect_branches(node.left, branches)
            self._collect_branches(node.right, branches)
            
def main():
    numbers = list(map(int, input().split()))
    numbers = numbers[:-1]
    bst = BST()
    
    for num in numbers:
        bst.insert(num)
        
    branches = bst.get_branches()
    for branch in branches:
        print(branch, end='\n')
        
if __name__ == '__main__':
    main()
```
