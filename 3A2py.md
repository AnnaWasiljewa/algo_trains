### Красивая строка

Красотой строки назовем максимальное число идущих подряд одинаковых букв. (красота строки _abcaabdddettq_ равна 3).
Сделайте данную вам строку как можно более красивой, если вы можете сделать не более _k_ операций замены символа.

__Формат ввода__  
В первой строке записано одно целое число _k_ (0 ≤ _k_ ≤ $10^9$).

Во второй строке дана непустая строчка _S_ (∣S∣ ≤ 2⋅ $10^5$). Строчка _S_ состоит только из маленьких латинских букв.

__Формат вывода__  
Выведите одно число — максимально возможную красоту строчки, которую можно получить.

```py
def max_beauty(k, s):
    n = len(s)
    max_beauty = 0

    for target_char in 'abcdefghijklmnopqrstuvwxyz':
        left = 0  
        replace_count = 0  

        for right in range(n):
            if s[right] != target_char:
                replace_count += 1

            while replace_count > k:
                if s[left] != target_char:
                    replace_count -= 1
                left += 1

            max_beauty = max(max_beauty, right - left + 1)

    return max_beauty

def main():
    k = int(input())
    s = input().strip()

    print(max_beauty(k, s))

if __name__ == "__main__":
    main()
```
