# Cartesian Trees

[![Build Status](../../actions/workflows/cmake.yml/badge.svg)](../../actions/workflows/cmake.yml)

Декартово дерево - структура данных, объединяющая в себе бинарное
дерево поиска и бинарную кучу (сбалансированное дерево). Широко используется в базах данных,
так как имеет эффективный алгоритм поиска. Операции: добавление, удаление, разбиение, слияние,
очищение, наличие. ****Теоретическая сложность, где используется****_

## MemTeam

Группа: 11-104


| Фамилия Имя      | Вклад (%) |           Прозвище |
|:-----------------|----------:|-------------------:|
| Евстратова Дарья |        28 |             _босс_ |
| Новак Сергей     |        28 |              _сид_ |
| Липперт Марк     |        16 |         _айтишник_ |
| Талова Олеся     |        13 | _ридми специалист_ |
| Шакуров Амир     |        15 |            _шакур_ |

**Девиз команды**
> _У самурая нет цели, только путь..._

## Структура проекта

- [`src`](src) - реализация структуры данных (исходный код и заголовочные файлы);
- [`benchmark`](benchmark) - контрольные тесты производительности структуры данных (операции добавления, удаления,
  поиска и пр.);
- [`tests`](tests) - наборы данных для запуска контрольных тестов и их генерация;

## Требования

Рекомендуемые требования:

1. С++ компилятор c поддержкой стандарта C++17 (например, _GNU GCC 8.1.x_ и выше).
2. Система автоматизации сборки _CMake_ (версия _3.12.x_ и выше).
3. Интерпретатор _Python_ (версия _3.7.x_ и выше).
4. Рекомендуемый объем оперативной памяти - не менее 4 ГБ.
5. Свободное дисковое пространство объемом ~ 1 ГБ (для входного набора данных).

## Сборка и запуск

#### Сборка проекта

Склонируйте проект к себе на устройство через [Git for Windows](https://gitforwindows.org/) (либо используйте
возможности среды разработки):

```shell
git clone --recurse-submodules https://github.com/lippertmark/semester-project-cartesian-trees.git
```
Сборка и запуск проекта осуществляется через среду разработки.

_Инструкция по сборке проекта, генерации тестовых данных, запуска контрольных тестов и примеров работы._

_Постарайтесь написать инструкцию так, чтобы незнакомый с проектом человек смог самостоятельно всё запустить._

_Здесь можно оставить ссылку с видео-инструкцией по сборке и запуску проекта_.

#### Генерация тестовых данных

_Опишите формат хранения (JSON, XML, CSV, YAML и т.д.) и процесс генерации тестовых данных._

_Разрешается использовать собственный формат хранения данных._

Пример. Генерация тестового набора данных

Формат данных: [comma-seperated values (CSV)](https://en.wikipedia.org/wiki/Comma-separated_values).

Инструкции по генерации:
```shell
# переход в папку генерации набора данных
cd dataset

# запуск Python-скрипта
python generate_csv_bench_dataset.py --samples 1000 <output> [args ...]
```

- `--samples` - количество генерируемых элементов;
- `<output>` - выходной файл и т.д.

Тестовые данные представлены в CSV формате (см.
[`dataset/data/dataset-example.csv`](dataset/data/dataset-example.csv)):

```csv
id, full_name
0, "Ramil Safin"
1, "Bulat Abbyasov"
...
```

**Примечание**. Для удобства запуска контрольных тестов рекомендуется организовывать данные в директориях, например:

```shell
dataset/data/
  add/
    01/
      100.csv
      ...
      5000000.csv
    02/ ...
    03/ ...
    ...
    10/ ...
  search/
    01/
      100.csv
      ...
      5000000.csv
    ...
    10/ ...
  ...
```

По названию директории `/dataset/data/add` можно понять, что здесь хранятся наборы данных для контрольных тестов по
**добавлению** элементов в структуру данных. Названия файлов `100.csv`. `5000000.csv` и т.д. хранят информацию о размере набора данных (т.е. количество элементов).

#### Контрольные тесты (benchmarks)

_Опишите, как запустить контрольные тесты, что они из себя представляют, какие метрики замеряют (время работы,
потребление памяти и пр.)._

Пример. Для запуска контрольных тестов необходимо предварительно сгенерировать или скачать готовый набор тестовых данных.

**Примечание**. Во избежание "захламления" репозитория большим объёмом данных рекомендуется указать ссылку на архив с
набором данных, который при необходимости можно скачать по ссылке.

##### Список контрольных тестов

| Название                  | Описание                                | Метрики         |
| :---                      | ---                                     | :---            |
| `search_benchmark`        | поиск элементов                         | _время_         |
| `add_benchmark`           | добавление элементов в структуру данных | _время, память_ |
| ...                       | ...                                     | ...             |

##### Примеры запуска

```shell
./benchmark <input> <output> --trials 50
```

- `<input>` - входной файл с набором данных в формате CSV;
- `<output>` - выходной файл с результатами контрольного теста;
- `--trials` - количество прогонов на наборе данных и т.д.

Добавление 10000 случайных элементов в структуру данных (повторить операцию 50 раз и вычислить среднее время работы и
потребляемую память):

```
./add_benchmark.exe ../dataset/data/add/10000.csv metrics.txt --trials 50
``` 

где `<input> = ../dataset/data/add/10000.csv` и `<output> = metrics.txt`.

## Источники

_Список использованных при реализации структуры данных источников._

_[Википедия](https://neerc.ifmo.ru/wiki/index.php?title=%D0%94%D0%B5%D0%BA%D0%B0%D1%80%D1%82%D0%BE%D0%B2%D0%BE_%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE)_
_[Алгоритмы и структуры данных. Двоичное дерево поиска](https://www.youtube.com/watch?v=ub06cKtebKk)_
_
