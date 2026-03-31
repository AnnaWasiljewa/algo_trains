### Обход

Выведите все элементы полученного дерева в порядке возрастания.

__Формат ввода__  
Вводится последовательность целых чисел, оканчивающаяся нулем. Сам ноль в последовательность не входит. 
По данной последовательности требуется построить дерево.

```py
class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
        
class BinarySearchTree:
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
    
    def inorder_traversal(self):
        result = []
        self._inorder_recursive(self.root, result)
        return result
        
    def _inorder_recursive(self, node, result):
        if node:
            self._inorder_recursive(node.left, result)
            result.append(node.value)
            self._inorder_recursive(node.right, result)
            
def main():
    numbers = list(map(int, input().split()))
    numbers = numbers[:-1]
    bst = BinarySearchTree()
    for num in numbers:
        bst.insert(num)
        
    output = bst.inorder_traversal()
    
    for num in output:
        print(num, end='\n')
        
if __name__ == '__main__':
    main()
```
