### Родословная: число потомков

В генеалогическом древе у каждого человека, кроме родоначальника, есть ровно один родитель.

Для каждого элемента дерева определите число всех его потомков (не считая его самого).

__Формат ввода__  
Программа получает на вход число элементов в генеалогическом древе _N_. Далее следует _N_ − 1 строка, задающие 
родителя для каждого элемента древа, кроме родоначальника. Каждая строка имеет вид имя_потомка имя_родителя.

__Формат вывода__ 
Выведите список всех элементов в лексикографическом порядке, для каждого элемента выводите количество всех его потомков.

```py
import sys
from collections import defaultdict

sys.setrecursionlimit(100000)

def count_descendants(node, children_map, descendants_count):
    if node in descendants_count:
        return descendants_count[node]
        
    total = 0 
    for child in children_map.get(node, []):
        total += count_descendants(child, children_map, descendants_count) + 1
    
    descendants_count[node] = total
    return total
    
def main():
    input_data = sys.stdin.read().strip().splitlines()
    n = int(input_data[0])
    children_map = defaultdict(list)
    all_people = set()
    children = set()
    
    for line in input_data[1:n]:
        child, parent = line.split()
        children_map[parent].append(child)
        all_people.add(child)
        all_people.add(parent)
        children.add(child)
        
    ancestor = (all_people - children).pop()
    
    descendants_count = {}
    
    for person in all_people:
        count_descendants(person, children_map, descendants_count)
        
    for name in sorted(all_people):
        print(f"{name} {descendants_count[name]}")
        
if __name__ == "__main__":
    main()
```
