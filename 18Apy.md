### Высота дерева

Реализуйте бинарное дерево поиска для целых чисел. Программа получает на вход последовательность целых чисел и строит 
из них дерево. Элементы в деревья добавляются в соответствии с результатом поиска их места. 
Если элемент уже существует в дереве, добавлять его не надо. Балансировка дерева не производится.

__Формат ввода__  
На вход программа получает последовательность натуральных чисел. Последовательность завершается числом 0, 
которое означает конец ввода, и добавлять его в дерево не надо.

__Формат вывода__  
Выведите единственное число – высоту получившегося дерева.

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
        if value == node.value:
            # Дубликаты не добавляем
            return
        elif value < node.value:
            if node.left is None:
                node.left = TreeNode(value)
            else:
                self._insert_recursive(node.left, value)
        else:  # value > node.value
            if node.right is None:
                node.right = TreeNode(value)
            else:
                self._insert_recursive(node.right, value)

    def get_height(self):
        return self._height_recursive(self.root)

    def _height_recursive(self, node):
        if node is None:
            return 0
        left_height = self._height_recursive(node.left)
        right_height = self._height_recursive(node.right)
        return max(left_height, right_height) + 1

# Основная программа
def main():
    # Считываем всю строку и разбиваем на числа
    numbers = list(map(int, input().split()))
    # Убираем 0 из последовательности (он только для обозначения конца)
    if numbers and numbers[-1] == 0:
        numbers.pop()

    bst = BinarySearchTree()
    for num in numbers:
        bst.insert(num)

    print(bst.get_height())

if __name__ == '__main__':
    main()
```
Время: 367ms. Память: 12.98Mb. 
