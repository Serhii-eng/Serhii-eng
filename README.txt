У папці projects знаходяться проєкти, які були створені для тренування на мові програмування C.

1. Determinant
Програма для обчислення детермінанту квадратної матриці за методом Гауса.
Інструкція: Для отримання результату детермінанту - введіть розміз матриці, та заповніть її поелементно.

2. Hex File Viewer
Програма, що виводить файл на консоль у шістнадцятковому форматі та з розшифруванням по ASCII.
Інструкція: Задайте шлях до файлу, початкову/кінцеву адреси читання файлу в шіснадцятковому виді.

3. Calendar
Календар, який використовує власні написані функції для відображення.
Функціонал: Календар приймає аргументи:
рік;
кількість місяців по горизонталі;
рамка (так/ні);
запис у файл (так/ні).

4. Gun_Tank
Гра, де гравець стріляє з гармати по статичному танку. Можна налаштувати швидкість і кут пострілу, сама куля летить по параболі.
Функціонал: Гравець задає параметри пострілу. При попаданні зникають символи, з яких складається танк.

5. Mario
Гра, подібна до класичної гри на консолі Денді. Наразі додано дві фічі:
Стовп вогню, що обертається;
Швидкість пересування ворогів.
Інструкція: Гравець керує персонажем та взаємодіє з перешкодами.


У папці tasks знаходяться розв'язані задачі на мові програмування С.

Для тренування використовувався підручник з задачами автора М.Э.Абрамян.
Сам підручник містить 1000 задач, знаходиться також в папці tasks, наразі вирішано приблизно 700 задач.
В данний момент працюю над темою "Текстові файли".


У папці projects_STM32 знаходяться проекти та бібліотеки, написані під STM32 на мові С.

1.ATH10, HTU21D - бібліотеки для підключення підключення датчиків температури та вологості.

2. Button_Handler - бібліотека для обробки кнопок.
Функціонал:
Данна бібліотека може обробляти декілька кнопок одночасно.
Кожна окрема кнопка може налаштовуватись для одноразового спрацювання по фронту, спаду та миттеве багаторазове спрацюваня при натисканні.  
Також кожній окремій кнопці можна задати часовий проміжок спрацювання - 100мс., 500мс., 3000мс.

3.Data_transfes_by_UART - в цьомі міні проекті відбувається передача данних від одного контроллера до іншого по UART.
До першої плати підключений потенціометр який обробляє величину напруги через ADC мікроконтроллера, також підключено дві кнопки.
Налаштовуємо потенціометр, та натискаємо одну з двох кнопок.
На другому кінці інша плата з двома світлодіодами приймає сигнал через UART.
Перший байт сигналу містить номер кнопки яка була натиснута, остальні два байти містять данні зчитані з ADC.
Після отримання сигналу значення ADC конвертується в значення ШІМу,який в свою чергу виставляється на відповідний світлодіод, 
в залежності від натиснутої кнопки на першій платі.


Папка G030F6P6_LEDS_AND_KEYS містить проект міні грою.
До плати підключено 5 кнопок які обробляються вище зазначеною бібліотекою, 5 світлодіодів різних кольорів, та бузер.
Функціонал:
Світлодіоди з певною послідовністю по черзі видають рамдомну комбінацію загорання, 5 разів.
Потім гра чекає поки гравець правильно повторить данну комбінацію світлодіодів.
Гра має 7 рівнів, при переході на наступний рівень, збільшується швидкість відтворення послідовної комбінації світлодіодів. 
Якщо ввести хочь одну комбінацію не вірно, то гра починається з першого рівня.
При натисканні декількох кнопок одночасно, виникає попередження, загорання всих разом світлодіодів яке супроводжується звуком бузера.


Папка F401CC_ST7789 містить в собі міні проект керування температурою та вологістю в кімнаті.
До плати підключений кольровий дисплей ST7789 240x240 з підсвіткою, енкодер ардуїно, датчик температури та вологості ATH10.
Функціонал:
Дисплей відображує верхній та нижній поріг температури та вологості, також можна зайти в меню та виставити -
Верхній та нижній поріг температури та вологості.
Мову інтерфейсу.
Яскравість підсвітки.

 

  
   
