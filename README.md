# Philosophers

> :warning: **This program is implemented under the Mac OS system.**

## Rus

#### Задача:
```
 Создать треды и использовать мьютексы. 
 Для бонусной части: Вынесение тредов в отдельные процессы и применение семафоров.
```
#### Реализовано:
```
1. В программу подается 4 аргумента(5-ый необязательный):
   · количество тредов(по заданию количество философов).
   · время, через которое программа окончится, если вовремя не будет выполненно условие
     (по заданию время до смерти философа, если он не поест).
   · время, в течение которого выполняется условие(по заданию время, которое философ тратит на еду).
   · время, которое тред стоит на паузе(по заданию - время для сна философа).
   · сколько раз тред должен выполнить условие(по заданию - сколько раз философ должен поесть)
     |необязательное условие|.
2. Использование мьютексов, чтобы треды не могли одновременно выполнять условие(по заданию философы
   должны выполнить условие - есть спагетти только тогда, когда имеют две вилки в руках. Изначально
   философы сидят в кругу и у каждого справа находится одна вилка. Получается, философ должен взять
   одну вилку справа и одну вилку слева, а остальные должны дождаться, пока вилки освободятся).
3. Каждое действие треда должно быть выведено на экран в виде сообщения(по заданию - каждое действие
   философа).
4. Время должно считаться в милисекундах - время работы программы.
```
#### Бонусная часть:
```
1. Мьютексы заменяются семафорами.
2. Каждый тред должен являться процессом(по заданию каждый философ должен быть процессом, не считая
   основной процесс программы).
```
#### Кейсы:
```
· 4 410 200 200 - валидный.
· 1 800 200 200 - невалидный.
· 5 800 200 200 7 - валидный, поток останавливается после 7 раз выполнения условия(eating).
· 4 310 200 100 - невалидный.
```
#### Инструкция для запуска:
1. Запустить Makefile в коммандной строке: `make`.
2. Запустить бинарный файл: `./philo ...`

## Eng

#### The Task:
```
 Create threads and use mutexes.
 For the bonus part: Moving threads into separate processes and using semaphores.
```
#### Implemented:
```
1. The program takes 4 arguments(5-th argument is optional):
   · number of threads(number of philosophers by subject).
   · the time after which the program will end if the condition is not met(time until philosopher's
     death if he doesn't eat by subject).
   · the time during which the condition is met(the time a philosopher spends eating by subject).
   · time the thread is paused(philosopher's sleep time by subject).
   · number of times the thread must fulfill the condition(number of times a philosopher should eat
     by subject)|optional condition|.
2. Use mutexes so that threads cannot fulfill a condition at the same time(in subject philosophers
   should eat spaghetti only when they have two forks in their hands. Ihe Philosophers sit in a
   circle and each has one fork on the right. It turns out that the philosopher must take one fork
   on the right and one fork on the left, and the rest must wait until the forks are free).
3. Every action in a thread should be displayed as a message(every action of a philosopher by subject).
4. The time should be counted in milliseconds - the program's running time.
```
#### Bonus part:
```
1. Mutexes are replaced by semaphores.
2. Each thread must be a process (each philosopher must be a process, not counting 
   the main program process).
```
#### Cases:
```
· 4 410 200 200 - valid.
· 1 800 200 200 - not valid.
· 5 800 200 200 7 - valid, the thread stops after 7 times the condition is met(eating).
· 4 310 200 100 - not valid.
```
#### Run instructions:
1. Run the Makefile on the command line: `make`.
2. Run the binary: `./philo ...`
