### АВЛ-сбалансированность

Дерево называется АВЛ-сбалансированным, если для любой его вершины высота левого и правого поддерева для этой 
вершины различаются не более чем на 1.

__Формат ввода__  
Вводится последовательность целых чисел, оканчивающаяся нулем. Сам ноль в последовательность не входит. 
Постройте дерево, соответствующее данной последовательности.

__Формат вывода__  
Определите, является ли дерево сбалансированным, выведите слово _YES_ или _NO_.

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
            
        if value > node.value:
            if node.right is None:
                node.right = TreeNode(value)
            else:
                self._insert_recursive(node.right, value)
                
    def is_avl_balanced(self):
        def check_balance(node):
            if not node:
                return True, 0
                
            left_balanced, left_height = check_balance(node.left)
            right_balanced, right_height = check_balance(node.right)
            
            if not left_balanced or not right_balanced:
                return False, 0
                
            if abs(left_height - right_height) > 1:
                return False, 0
                
            current_height = max(left_height, right_height) + 1
            return True, current_height
            
        balanced, _ = check_balance(self.root)
        return balanced
        
def main():
    numbers = list(map(int, input().split()))
    numbers = numbers[:-1]
    bst = BST()
    for num in numbers:
        bst.insert(num)
    if bst.is_avl_balanced():
        print("YES")
    else:
        print("NO")
            
if __name__ == "__main__":
    main()
```
