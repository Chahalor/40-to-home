# Philo: Test

## 👀 Parsing

```bash
./philo							# should do nothing and not launch the simulation
./philo 1   2  4				# should raise an error and  not launch the simulation
./philo 10  50 7  12 -23		# should not launch the simulation nor raise an error
./philo 10a 50 o  12 10			# should raise an error and not launch the simulation
./philo 10  50 89 12 d			# should raise an error and not launch the simulation
```

## 🧪 Tests de base (fonctionnement minimal)

```bash
./philo 1 800 200 200 5			# 1 philosopher, cannot eat → should die
./philo 2 800 200 200 3			# 2 philosophers eat alternately
./philo 5 800 200 200 5			# Stable test with 5 philosophers
```

## 🔁 Precision Tests (death limit)

```bash
./philo 3 300 150 150 5			# time_to_eat == time_to_die / 2 → critical edge. Philo can die but can also survive
./philo 3 300 149 150 5			# close to the limit: should die if imprecise
./philo 3 300 151 150 5			# stable if last_meal is managed correctly, but philo can also die
```

## 🧱 Stress Tests (concurrency + latency)

```bash
./philo 50  500  100 100 3		# 50 threads → contention test on forks
./philo 100 500  100 100 2		# 100 philosophers, few meals → check if they survive
./philo 200 1000 100 100 1		# 200 philosophers, one meal → verify no deaths
./philo 200 1000 100 100 10		# 200 philosophers, ten meal → verify no deaths
```

## 🧨 Endurance Tests

```bash
./philo 5 2000 100 100 500		# long test, no philosopher shoud die
./philo 10 300 140 60  1000		# precision test over the long term all depend of the CPU
./philo 16 300 150 60  100		# well-known limit to expose bugs
```

## 💣 Intentionally Dangerous Tests

```bash
./philo 3  330 300 0   2		# no sleep → balance test
./philo 10 100 50  50  5		# tight interval → may kill some if imprecise
./philo 10 110 0   100 5		# no eat at all → if last_meal is misplaced → death
```

## 🧮 Edge Cases

```bash
./philo 150 3000 500  500  2	# large group, but very generous timing
./philo 199 310  150  150  3	# max odd number with synchronization at the limit
./philo 128 9999 1000 1000 10	# long stress test with many threads
```

## 🧹 Cleanup / End of Simulation Tests

```bash
./philo 5  1000 100 100 1		# all philosophers eat once, then clean exit
./philo 10 1000 100 100 2		# same with more participants
```

## 💧 Leaks / Data Races Test 🏎️

### 💧 Leaks

```bash
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./philo 1   200 75 75    > /dev/null
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./philo 10  200 75 75 10 > /dev/null
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./philo                  > /dev/null
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./philo 200 200 75 75 10 > /dev/null
```

### 🏎️ Data races

```bash
valgrind --tool=helgrind --track-lockorders=yes --history-level=full ./philo 1   200 75 75    > /dev/null
valgrind --tool=helgrind --track-lockorders=yes --history-level=full ./philo 10  200 75 75 10 > /dev/null
valgrind --tool=helgrind --track-lockorders=yes --history-level=full ./philo 49  200 75 75 10 > /dev/null
valgrind --tool=helgrind --track-lockorders=yes --history-level=full ./philo 200 200 75 75 10 > /dev/null
```