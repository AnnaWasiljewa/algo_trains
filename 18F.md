### Вывод развилок

Для полученного дерева выведите список всех вершин, имеющих по два ребёнка, в порядке возрастания.

__Формат ввода__  
Вводится последовательность целых чисел, оканчивающаяся нулем. Сам ноль в последовательность не входит. 
Постройте по этой последовательности дерево.

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
                
    def get_forks(self):
        forks = []
        self._collect_forks(self.root, forks)
        return sorted(forks)
        
    def _collect_forks(self, node, forks):
        if node is not None:
            if node.left is not None and node.right is not None:
                forks.append(node.value)
            self._collect_forks(node.left, forks)
            self._collect_forks(node.right, forks)
            
def main():
    numbers = list(map(int, input().split()))
    numbers = numbers[:-1]
    bst = BST()
    
    for num in numbers:
        bst.insert(num)
        
    forks = bst.get_forks()
    
    for fork in forks:
        print(fork, end='\n')
        
if __name__ == '__main__':
    main()
```
