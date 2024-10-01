# Лабораторна робота №1: ООП

# Студента групи КІ2С-23-1 Рудичука Дмитра 
# Варіант завдання №11

## Повний звіт до лабораторної роботи знаходиться в директорії "documents"

## Опис
Ця лабораторна робота присвячена освоєнню основ об'єктно-орієнтованого програмування (ООП) у мові C++. В рамках роботи було реалізовано програму для обробки даних студентів та потягів, яка включає запис і читання даних у файли.

## Мета
- Ознайомитися з основними принципами ООП.
- Реалізувати структури для представлення студентів і потягів.
- Розробити функції для запису та зчитування даних у файли.
- Впровадити фільтрацію даних при читанні з файлів.

## Структура програми
Програма складається з таких основних компонентів:

1. **Структури даних**
   - `Student`: структура для зберігання інформації про студентів.
   - `Train`: структура для зберігання інформації про потяги.

2. **Функції**
   - `RW_students`: записує дані студентів у файл.
   - `RD_students`: читає дані студентів з файлу та виводить на консоль.
   - `RW_trains`: записує дані потягів у файл.
   - `RD_trains`: читає дані потягів з файлу та виводить потяги, що відправляються до 18:00.

## Виконання програми
1. Клонувати репозиторій:
   ```bash
   git clone https://github.com/RudychukDmytro/OOP_Labs_1
2. Перейти відкрити в термінальному вікні робочий каталог
3. Виконати компіляцію:
   ```bash
   g++ main.cpp students.cpp trains.cpp -o program
4. Запустити скомпільований файл:
   ```bash
   ./program

Приклад для запуску програми наведено для операційної системи Ubuntu або їй подібним.

