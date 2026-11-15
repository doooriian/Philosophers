<div align="center">

<a href="https://42.fr/"><img src="https://raw.githubusercontent.com/doooriian/42-Badges/main/badges/philosophersm.png" alt="Philosophers 42 badge" width="125" /></a>

# Philosophers

**42 School project · Threads and synchronization**

<img src="https://img.shields.io/badge/42_Project-C%20%7C%20Concurrency-D97706?style=flat-square" alt="Philosophers technology" />
<img src="https://img.shields.io/badge/Documentation-Project_Overview-334155?style=flat-square" alt="Project documentation" />

</div>

## 🔎 Overview

A concurrency simulation based on the dining philosophers problem, illustrating synchronization and shared resource management.

## ✨ Features

- Represent philosophers as concurrent worker threads
- Protect shared forks and state with mutexes
- Monitor philosopher state and timeouts
- Configure the simulation from command-line timing parameters

## 🧩 Technical approach

The routine and monitor logic are separated. Timing and synchronization are important because incorrect access to shared state can cause races or deadlocks.

> **Tech stack** · C · POSIX threads · Mutexes · Make.

## 🚀 Build and usage

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

## 🧪 Verification

Build in the documented environment, exercise normal scenarios and edge cases, and compare actual behaviour with the expected output. No automated CI test suite is included in this repository.

## ⚠️ Notes and limitations

Timing-based simulations are sensitive to system scheduling. Stress testing and a race detector are useful, but no automated CI suite is included here.

---

<div align="center">

<sub>Part of the <a href="https://42.fr/">42 curriculum</a> · <a href="https://github.com/doooriian">Back to my GitHub profile</a></sub>

</div>
