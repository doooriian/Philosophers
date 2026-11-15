# Philosophers

> **42 School project** · C · Pthreads · Concurrency

A concurrency simulation based on the dining philosophers problem, illustrating synchronization and shared resource management.

## Overview

A concurrency simulation based on the dining philosophers problem, illustrating synchronization and shared resource management.

## Features

- Represent philosophers as concurrent worker threads
- Protect shared forks and state with mutexes
- Monitor philosopher state and timeouts
- Configure the simulation from command-line timing parameters

## Technical approach

The routine and monitor logic are separated. Timing and synchronization are important because incorrect access to shared state can cause races or deadlocks.

**Stack:** C · POSIX threads · Mutexes · Make.

## Build and usage

```bash
git clone https://github.com/doooriian/Philosophers.git
cd Philosophers
make
./philo 5 800 200 200
```

An optional fifth argument sets the required number of meals per philosopher:

```bash
./philo 5 800 200 200 7
```

## Verification

Build in the documented environment, exercise normal scenarios and edge cases, and compare actual behaviour with the expected output. No automated CI test suite is included in this repository.

## Notes and limitations

Timing-based simulations are sensitive to system scheduling. Stress testing and a race detector are useful, but no automated CI suite is included here.

---

Part of the [42 curriculum](https://42.fr/). Explore the other projects on [my GitHub profile](https://github.com/doooriian).
