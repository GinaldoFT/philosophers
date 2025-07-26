<p align="center">
  <img src="https://raw.githubusercontent.com/GinaldoFT/GinaldoFT/main/42covers/cover-philosophers.png" alt="philosophers cover"/>
</p>

# 🍝 Philosophers

`philosophers` is a concurrency and synchronization project from the 42 curriculum.  
It simulates the classic Dining Philosophers problem using threads and mutexes to handle resource sharing and avoid deadlocks.

<p align="center">
  <img src="https://raw.githubusercontent.com/GinaldoFT/GinaldoFT/main/42Badges/philosopherse.png" width="100" alt="philosophers badge"/>
</p>

---

## 🎯 Project Objective

The goal of `philosophers` is to explore the concepts of **multithreading**, **mutex locking**, and **race conditions** by simulating a group of philosophers who must eat, think, and sleep without starving or causing deadlocks.

You will:

- Manage multiple threads representing philosophers  
- Use **mutexes** to control access to shared forks  
- Implement timing logic to prevent starvation  
- Ensure the simulation follows strict timing rules  

---

## 🔧 Key Concepts

| Concept         | Description |
|----------------:|-------------|
| Thread          | Lightweight process used to simulate each philosopher |
| Mutex           | Locking mechanism to avoid multiple access to a fork |
| Deadlock        | A situation where philosophers are stuck waiting for each other |
| Starvation      | A philosopher never gets a chance to eat |
| Race Condition  | Unexpected behavior due to unsynchronized access |

---

## ⚙️ Project Rules

- No data races or deadlocks allowed  
- Precise timing and output synchronization  
- All philosophers must stop when one dies or when all have eaten the required number of times  
