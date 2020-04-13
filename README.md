# 1C_exam
Enter task for 1C courses

## Задача А001
 Для решения данной задачи можно использовать структуру данных бор. Будем для каждой вершины хранить
сколько слов в ней заканчивается и по какому ребру надо перейти, чтобы достигнуть максимума в поддереве.<br/>
 Таким образом, при дописывании мы будем спускаться вниз по бору, для того, чтобы сформировать
подсказку можно честно спускаться вниз по дереву, так как ассимптотически для этого нужно потратить
не больше времени, чем на то, чтобы вывести ответ. Так, ассимптотика решения составляет O(n) на запрос, где n - длина самой популярной строки.

-----------------------
## Протокол взаимодействия
Сначала введите количество запросов, далее вводите  их по одному с новой строки.<br/>
Запросы выглядят так: <query_type> <query_string>, где <br/>
query_type - это тип запроса (1 - добавить новое слово, 2 - задать новый запрос, 
 3 - добавить символы к предыдущему запросу) <br/>
query_string - строка запроса <br/>
Если для данной строки нет подсказки, выведется ошибка: "No words have been found by this clue".
