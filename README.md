# PolishNotationAndGraph

***На языке программирования Си разработать программу src/graph.c для построения графиков функций, задаваемых произвольными выражениями. Для вычисления значений выражений использовать алгоритм Дейкстры для перевода выражения в польскую нотацию. Сборку программы осуществлять при помощи Makefile. Имя стадии сборки - all. Исполняемый файл должен храниться в корне в папке build с именем graph.***
___
## Условия:
  
Размер поля для вывода графиков - прямоугольник 25 на 80 точек.

Область определения - [0; 4 Пи]

Область значений - [-1; 1]

Ориентация координатной плоскости - ось ординат направлена вниз, ось абсцисс - направо. 

Центр координат - середина левой границы (точка {0, 13}). 

Рисовать оси не нужно.

Ничего кроме графика выводиться не должно.

Значения округляются по правилам математики.
  
График должен быть выведен с помощью знаков Звездочек для линии графика и "." для всего остального пространства экрана.
___
## Пример: 

Входные данные: sin(cos(2*x))

> Использовать можно только `<math.h>`, `<stdio.h>`, `<stdlib.h>`, `<string.h>` 

> Все возможные операции и функции находятся ниже
___
## Примечание

> Возможные операции & функции \
> "+" \
> "-" (унарный и бинарный) \
> "*" \
> "/" \
> "()" \
> sin(x) \
> cos(x) \
> tan(x) \
> ctg(x) \
> sqrt(x) \
> ln(x)