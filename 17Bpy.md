### Точки и отрезки

Дано _n_ отрезков на числовой прямой и _m_ точек на этой же прямой. Для каждой из данных точек определите, 
скольким отрезкам они принадлежат. Точка _x_ считается принадлежащей отрезку с концами _a_ и _b_, если выполняется двойное 
неравенство _min(a, b)_ ≤ _x_ ≤ _max(a, b)_.

__Формат ввода__  
Первая строка содержит два целых числа _n_ (1 ≤ _n_ ≤ $10^5$) – число отрезков и _m_ (1 ≤ m ≤ $10^5$) – число точек. 
В следующих _n_ строках по два целых числа $a_i$ и $b_i$ – координаты концов соответствующего отрезка. 
В последней строке _m_ целых чисел – координаты точек. Все числа по модулю не превосходят $10^9$

__Формат вывода__  
В выходной файл выведите m чисел – для каждой точки количество отрезков, в которых она содержится.
```py
import sys

def main():
    # Считываем все данные
    data = sys.stdin.read().split()
    index = 0
    n = int(data[index])
    m = int(data[index + 1])
    index += 2

    events = []

    # Добавляем события для отрезков
    for _ in range(n):
        a = int(data[index])
        b = int(data[index + 1])
        index += 2
        # Гарантируем, что a <= b
        start, end = min(a, b), max(a, b)
        events.append((start, 'start'))
        events.append((end, 'end'))

    # Координаты точек и их индексы для сохранения порядка вывода
    points = list(map(int, data[index:index + m]))
    for i, x in enumerate(points):
        events.append((x, 'point', i))

    # Сортировка событий:
    # 1. По координате
    # 2. По типу события: start (0) < point (1) < end (2)
    def event_key(event):
        coord, event_type = event[0], event[1]
        if event_type == 'start':
            priority = 0
        elif event_type == 'point':
            priority = 1
        else:  # 'end'
            priority = 2
        return (coord, priority)

    events.sort(key=event_key)

    # Обработка событий
    active_segments = 0  # счётчик активных отрезков
    result = [0] * m  # массив для ответов

    for event in events:
        if event[1] == 'start':
            active_segments += 1
        elif event[1] == 'end':
            active_segments -= 1
        elif event[1] == 'point':
            # Сохраняем ответ для точки с индексом event[2]
            result[event[2]] = active_segments

    # Выводим результаты
    print(' '.join(map(str, result)))

if __name__ == '__main__':
    main()
```
