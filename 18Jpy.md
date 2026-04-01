### Родословная: подсчёт уровней

В генеалогическом древе у каждого человека, кроме родоначальника, есть ровно один родитель. Каждому элементу 
дерева сопоставляется целое неотрицательное число, называемое высотой. У родоначальника высота равна 0, 
у любого другого элемента высота на 1 больше, чем у его родителя. Вам дано генеалогическое древо, определите высоту всех его элементов.

__Формат ввода__  
Программа получает на вход число элементов в генеалогическом древе _N_. Далее следует _N_ − 1 строка, задающие родителя 
для каждого элемента древа, кроме родоначальника. Каждая строка имеет вид имя_потомка имя_родителя.

__Формат вывода__  
Программа должна вывести список всех элементов древа в лексикографическом порядке. После вывода имени каждого элемента 
необходимо вывести его высоту.

```py
import sys

def get_height(person, parent_map, heights):
    if person in heights:
        return heights[person]
        
    if person not in parent_map:
        heights[person] = 0
        return 0
        
    parent = parent_map[person]
    heights[person] = get_height(parent, parent_map, heights) + 1
    return heights[person]
    
def main():
    input_data = sys.stdin.read().strip().splitlines()
    n = int(input_data[0])
    
    parent_map = {}
    all_people = set()
    
    for line in input_data[1:n]:
        child, parent = line.split()
        parent_map[child] = parent
        all_people.add(child)
        all_people.add(parent)
    
    heights = {}
    
    for person in all_people:
        get_height(person, parent_map, heights)
        
    for name in sorted(all_people):
        print(f"{name} {heights[name]}")
        
if __name__ == "__main__":
    main()
```
