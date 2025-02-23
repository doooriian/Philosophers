<br />
<p align="center">
  <a href="https://github.com/othneildrew/Best-README-Template">
    <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/8d/42_Logo.svg/1200px-42_Logo.svg.png" alt="42 Logo" width="250" height="250">
  </a>

  <h1 align="center">Philosophers</h1>

  <p align="center">
    A synchronization and concurrency challenge from 42 School based on the Dining Philosophers Problem.
    <br /><br />
    <img src="https://github.com/doooriian/42-Badges/blob/main/badges/philosopherse.png" alt="Philosophers Badge" width="150">
  </p>
</p>

<p align="center">
  <img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/doooriian/Philosophers?color=1A237E" />
  <img alt="Code language count" src="https://img.shields.io/github/languages/count/doooriian/Philosophers?color=00BCD4" />
  <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/doooriian/Philosophers?color=7B1FA2" />
  <img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/doooriian/Philosophers?color=D32F2F" />
</p>

---

## ✨ Overview

**Philosophers** is an individual project at 42 School that challenges students to solve the classic Dining Philosophers Problem. The task involves creating a simulation where multiple philosophers, seated at a circular table, alternate between thinking, eating, and sleeping, while sharing limited resources (forks). The main challenge is to ensure proper synchronization and avoid common pitfalls like deadlocks and starvation.

To implement a solution, I adhered to the specifications provided by the 42 project guidelines and used various strategies to coordinate philosopher actions efficiently.

---

## 📑 Key Features

- **Concurrent Simulation**: Each philosopher is modeled as a separate process or thread, demonstrating inter-process communication and synchronization.
- **Deadlock Prevention**: Implements strategies to avoid deadlocks and resource contention.
- **Efficient Resource Management**: Ensures timely access to forks while promoting fair resource distribution among all philosophers.
- **Clear Status Updates**: Logs each philosopher's actions (e.g., picking up forks, eating, sleeping, thinking) to help visualize the simulation progress.

---

## 🛠️ Technologies Used

- **[C](https://devdocs.io/c/)** — Core programming language.
- **[POSIX Threads](https://man7.org/linux/man-pages/man7/pthreads.7.html)** or **Processes** — For creating concurrent simulations.
- **Makefile** — Used for building and automating the project.

---

## 🚀 How to Build and Run

Clone the repository and use the following commands in your terminal:

```bash
# Compile the project
make all

# Remove object files
make clean

# Remove object files and executable
make fclean

# Clean and recompile
make re

```

Run the executable with the required arguments. The program accepts parameters such as the number of philosophers, time to die, time to eat, time to sleep, and optionally the number of times each philosopher must eat.

**Example usage:**

```bash
./philo 5 800 200 200
```

**Example with a meal limit:**
```bash

./philo 5 800 200 200 7
```

## 🧪 Testing

The simulation was tested under multiple scenarios to ensure robustness and correctness:

- Validating with various numbers of philosophers.
- Monitoring behavior under high contention for forks.
- Confirming that no deadlocks or starvation occur during long runs.
- Checking the simulation output for proper chronological status updates of each philosopher.

Additional custom scripts were used to automate the testing and verify the expected results.

## 📚 Resources

- **[Philosophers 42 Guide — "The Dining Philosophers Problem"](https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2)**  
  A comprehensive guide on implementing the solution.
- **[YouTube Video 1](https://youtu.be/VSkvwzqo-Pk?si=SN9AQYndsZkL5mGd)**  
  Detailed explanation and visual breakdown of the problem.
- **[YouTube Playlist](https://youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&si=McfwBXrZSandyjNb)**  
  A series of tutorials covering various aspects of the Dining Philosophers Problem and concurrent programming.

## 📬 Contact

Feel free to reach out or contribute to this project on [GitHub](https://github.com/doooriian)!
