### Глубина добавляемых элементов

В бинарное дерево поиска добавляются элементы. Выведите глубину для каждого добавленного элемента в том порядке, 
как они добавлялись. Если элемент уже есть в дереве, то ничего добавлять и выводить не нужно. 
Глубиной называется расстояние от корня дерева до элемента включительно.

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
            return 1
        return self._insert_recursive(self.root, value, 1)
        
    def _insert_recursive(self, node, value, depth):
        if value == node.value:
            return None
        elif value < node.value:
            if node.left is None:
                node.left = TreeNode(value)
                return depth + 1
            else:
                return self._insert_recursive(node.left, value, depth + 1)
        else:
            if node.right is None:
                node.right = TreeNode(value)
                return depth + 1
            else:
                return self._insert_recursive(node.right, value, depth + 1)
                
def main():
    numbers = list(map(int, input().split()))
    numbers = numbers[:-1]
    
    bst = BinarySearchTree()
    
    for num in numbers:
        depth = bst.insert(num)
        if depth is not None:
            print(depth, end=' ')
            
if __name__ == "__main__":
    main()
```
