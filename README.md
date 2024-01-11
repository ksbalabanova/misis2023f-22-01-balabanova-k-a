# misis2023f-22-01-balabanova-k-a

Название задачи: Написание пользовательского интерфейса приложения Color Cube

Ссылка на репозиторий проекта: https://github.com/ksbalabanova/colcube

Краткое описание задачи: Написание пользовательского интерфейса приложения Color Cube, поддержающего "горячие клавиши".

Используемые библиотеки: OpenGL, Dear Imgui, Glfw, OpenCV, JsonCpp, VTK.

Подробное описание задачи:

Основной функционал ![IMG_0635](https://github.com/ksbalabanova/misis2023f-22-01-balabanova-k-a/assets/114703175/42681656-0499-43f8-a27f-45e656eb4b9c)


Кнопка 1️⃣ "Открыть" - пользователь прописывает путь к нужному ему файлу, это изображение выводится в отдельном окне.

Кнопка 2️⃣ "Проекция" Позволяет в новом окне получить проекцию цветового распределения. Обязательна проекция на плоскость перпендикулярную главной диагонали. Остальные определит Ушакова А.

Кнопка 3️⃣ "Сохранить" - 1)изображение кубика, 2) проекции или 3) текстового файла с параметрами проекции. После ее нажатия всплывает форма для написания полного пути, названия и расширения файла

Оси координат 4️⃣ для осуществления вращения кубика

Кнопка 5️⃣ По умолчанию кубик визуализирует цветовое распределение в пространстве RGB, эта кнопка позволяет получить распределение в других цветовых координатах. В каких именно зависит от Шармадини Е.

Кнопки 6️⃣ Позволяют масштабировать RGB куб.

Примерный вид главного меню в развернутом виде:![IMG_2DA6BF4FCC4D-1](https://github.com/ksbalabanova/misis2023f-22-01-balabanova-k-a/assets/114703175/5e4a72e7-80d8-4e43-bde5-8df09f8bb3ec)

Задачи:

1) Оформить графически

2) Прописать функции, не зависящие от товарищей

3) Добавить "горячие клавиши"

4) Прописать функции, зависящие от товарищей
   
Выполнено:

1) Написан каркас главного меню

2) Прописан функционал, не зависящих от товарищей:

3) Прописаны горячие клавиши

4) Написаны функции для сохранения параметров запуска (в проект еще не интегрированы)

Инструкция по тестированию (для написанного функционала):

При открытии приложения появляется главное меню

<img width="503" alt="Снимок экрана 2024-01-11 в 18 09 53" src="https://github.com/ksbalabanova/misis2023f-22-01-balabanova-k-a/assets/114703175/5e5984ea-a147-4bf4-a2bf-d576457fce14">

Сначала необходимо выбрать изображение путем ввода полного пути к нему

<img width="463" alt="Снимок экрана 2024-01-11 в 18 10 59" src="https://github.com/ksbalabanova/misis2023f-22-01-balabanova-k-a/assets/114703175/cf043ceb-9c6f-4d54-8492-4c44b1c47763">

Кнопка “OK” выводит изображение на экран в окне “Your Image” и очищает строку “Image path” для дальнейшей смены изображения, поддерживает горячие клавиши.

Пример использования:

<img width="1229" alt="Снимок экрана 2024-01-11 в 18 12 30" src="https://github.com/ksbalabanova/misis2023f-22-01-balabanova-k-a/assets/114703175/305f5967-573a-40e6-8788-60d8449dcc1a">

Кнопка “Text”: ввод полного пути и названия файла для отписывания параметров визуализации (угол поворота кубика и масштаб).

<img width="504" alt="Снимок экрана 2024-01-11 в 18 13 17" src="https://github.com/ksbalabanova/misis2023f-22-01-balabanova-k-a/assets/114703175/35d872e8-7325-483d-8536-d239e00a1734">

Для кнопок увеличения и уменьшения масштаба прописаны горячие клавиши.
