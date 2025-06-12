# 42 Philosophers Development Guide

## Implementation Guide

### Core Philosophy Loop
Each philosopher should run in an infinite loop with these states:
- **Thinking** - philosopher is contemplating (can be a short delay)
- **Hungry** - philosopher wants to eat and tries to acquire forks  
- **Eating** - philosopher has both forks and is eating
- **Sleeping** - philosopher is resting after eating

## Implementation Checklist

### 1. Fork Management
**Overview:** Each philosopher needs 2 forks (left and right). Forks are shared resources that need mutex protection. Only one philosopher can hold a specific fork at a time. Must avoid deadlock when acquiring forks.

**Key Considerations:**
- Use mutexes for forks and shared data
- Protect access to last_meal_time and meal_count  
- Consider using a mutex for printing to avoid garbled output

- [x] **Basic mutex locking/unlocking**
- [x] **Deadlock prevention (odd/even ordering)**
- [x] **Proper fork acquisition sequence**
- [x] **State management updates**
- [x] **Fork status tracking and validation**

### 2. Death Detection System

**Implementation Plan:**
1. Update `last_meal_ms` when philosopher starts eating
2. Create monitor thread that checks all philosophers periodically  
3. Calculate `current_time - last_meal_ms > time_to_die`
4. Set global flag to stop simulation when death detected
5. Print death message and terminate cleanly

**Key Questions:**
1. When should you initialize `last_meal_ms`? (At simulation start)
2. What happens if philosopher is still trying to get forks? (They can still die)
3. How do you prevent race conditions on `dinner_ended`? (It's read-only for most threads)

- [x] **Timestamp tracking for last meal**
- [x] **Death monitoring thread creation**
- [x] **Death condition checking (time_to_die)**
- [x] **Simulation termination on death**
- [x] **Death message formatting**

### 3. Meal Counting System
- [ ] **Track number_of_meals per philosopher**
- [ ] **Optional meal limit checking**
- [ ] **Simulation termination when all philosophers eat enough**
- [ ] **Meal completion validation**

### 4. Timing System
- [ ] **Precise timestamp functions (get_current_time_ms)**
- [ ] **Accurate timing for eating/sleeping**
- [ ] **Thinking time calculation**
- [ ] **Time conversion utilities (ms to μs)**

### 5. Output Management
- [x] **Thread-safe printing with mutex**
- [ ] **Standardized message format**
- [ ] **Timestamp in output messages**
- [ ] **Clean program termination output**

### 6. Error Handling & Cleanup
- [ ] **Thread cleanup on errors**
- [ ] **Mutex destruction**
- [ ] **Memory cleanup**
- [ ] **Graceful program termination**

### 7. Edge Cases & Optimization
- [ ] **Single philosopher case**
- [ ] **Zero meal count case**
- [ ] **Large philosopher count testing**
- [ ] **Performance optimization**

---

## Study Topics

### Threading and Printf Issues

**1. Missing Newline**
- Problem: Without `\n`, output might stay in buffer
- Solution: Always add `\n` to printf statements

**2. Buffer Flushing**
- What happens: `printf` uses buffered output - text might not appear immediately
- Why: Operating system optimizes by collecting output before writing to terminal
- Solution: Force immediate display with `fflush(stdout)`

**3. Thread Race Conditions in Output**
- Problem: Multiple threads printing simultaneously can cause garbled output
- Example: "Philo Philo id: 1id: 2" instead of separate lines
- Solution: Use mutex to protect printf calls

**4. Quick Thread Exit**
- Problem: Functions that return immediately after printf
- Result: Thread dies instantly, might not see all output
- Timing issue: Main program might finish before all threads complete

**5. Build/Compilation Issues**
- Problem: Changes not reflected if not properly rebuilt
- Solution: Always run `make clean && make` after code changes

**6. pthread_create Behavior**
- pthread_create does NOT immediately execute the routine in calling thread
- It creates a new thread that runs asynchronously/in parallel
- Main thread continues immediately to next line
- New thread starts running the routine independently

### Mutex as Queue System

**How Mutex Queue Works:**
When multiple threads call `pthread_mutex_lock()` on the same mutex:

1. **First thread:** Gets the lock immediately, continues execution
2. **Other threads:** Get **blocked** (put to sleep) in a queue
3. **When unlocked:** Operating system wakes up **one** waiting thread
4. **That thread:** Gets the lock and continues
5. **Process repeats:** Until all threads get their turn

**Example with 5 Philosophers:**
```
Fork 0 mutex queue:
- Philosopher 0: [LOCKED] ← currently eating
- Philosopher 1: [WAITING] ← blocked, sleeping
- Philosopher 4: [WAITING] ← blocked, sleeping

When Philosopher 0 unlocks:
- Philosopher 1: [LOCKED] ← gets the fork
- Philosopher 4: [WAITING] ← still waiting
```

**Key Points:**
- **Blocking behavior:** `pthread_mutex_lock()` makes thread sleep until available
- **No "checking":** You don't check if free - you just wait for your turn
- **Automatic queueing:** OS handles the waiting line
- **Fair scheduling:** Each thread eventually gets the resource
- **Perfect for forks:** Philosophers automatically wait in line for their turn to eat

### Deadlock Prevention Strategy

**The Deadlock Problem:**
```
5 philosophers all execute simultaneously:
- Philo 0: locks fork 0 (left) → waits for fork 1 (right)
- Philo 1: locks fork 1 (left) → waits for fork 2 (right)  
- Philo 2: locks fork 2 (left) → waits for fork 3 (right)
- Philo 3: locks fork 3 (left) → waits for fork 4 (right)
- Philo 4: locks fork 4 (left) → waits for fork 0 (right) ← DEADLOCK!
```
**Result:** Everyone waits forever - circular dependency!

**Solution: Odd/Even Fork Ordering**
Break the circular pattern by changing fork acquisition order:

```c
if (philo->id % 2 == 0) {
    // Even philosophers: left fork first
    pthread_mutex_lock(&philo->left_fork->mutex);
    pthread_mutex_lock(&philo->right_fork->mutex);
} else {
    // Odd philosophers: right fork first  
    pthread_mutex_lock(&philo->right_fork->mutex);
    pthread_mutex_lock(&philo->left_fork->mutex);
}

// Always unlock in reverse order
pthread_mutex_unlock(&philo->right_fork->mutex);
pthread_mutex_unlock(&philo->left_fork->mutex);
```

**Why this works:**
- At least one philosopher (odd) will wait for a different fork first
- Breaks the circular waiting pattern
- Guarantees someone can always make progress

**Alternative:** Always acquire lower-numbered fork first, then higher-numbered fork.

### Pointers vs Values in Mutex Operations

**What `pthread_mutex_lock()` expects:**
`pthread_mutex_lock()` needs a **pointer to the mutex** (memory address), not the mutex itself.

**In your code:**
```c
void lock_fork(t_fork *fork, int philo_id)
```
- `fork` is a **pointer to a t_fork struct**
- `fork->mutex` is the **actual mutex inside that struct** (a value)
- `&fork->mutex` is the **address of that mutex** (a pointer)

**Visual explanation:**
```c
t_fork my_fork;              // A fork struct
                            
// Memory layout:
// my_fork = { id: 1, status: 0, mutex: [mutex_data], owner_id: -1 }
//                                      ↑
//                              this is fork->mutex (the value)
//                                      ↑
//                              &fork->mutex points to this location
```

**Function signatures:**
```c
pthread_mutex_lock(pthread_mutex_t *mutex);  // Wants a POINTER
//                 ↑
//        Notice the * - it wants an address

// So you must pass:
pthread_mutex_lock(&fork->mutex);  // ✅ Address of the mutex
pthread_mutex_lock(fork->mutex);   // ❌ The mutex value itself
```

**Simple rule:**
- `&` = "address of" = gives you a pointer
- Without `&` = gives you the actual value

`pthread_mutex_lock()` needs to modify the mutex, so it needs its memory address!

### Thread-Safe Logging with Mutex

**The Problem:**
Multiple threads using `printf()` simultaneously create garbled output:
```c
// Multiple threads doing this:
printf("Philo %d is now thinking\n", philo->id);
printf("Philo %d is now eating\n", philo->id);

// Results in garbled output:
"Philo Philo 1 is now 2 is now thinking
eating"
```

**How Mutex Locking Works:**
Anything between `pthread_mutex_lock()` and `pthread_mutex_unlock()` is **protected** - only one thread can execute that code section at a time.

```c
pthread_mutex_lock(&dinner->logging_mutex);    // ← START: Block here if another thread is using
printf("Philo %d %s\n", philo_id, message);    // ← ONLY ONE THREAD can be here at a time
pthread_mutex_unlock(&dinner->logging_mutex);  // ← END: Release so next thread can enter
```

**Timeline Example:**
```
Thread 1: [LOCK] → printf("Philo 1 thinking") → [UNLOCK]
Thread 2: [WAITING...........................] → [LOCK] → printf("Philo 2 eating") → [UNLOCK]  
Thread 3: [WAITING...........................] → [WAITING..] → [LOCK] → printf("Philo 3 sleeping") → [UNLOCK]
```

**Without mutex (current problem):**
```
Thread 1: printf("Philo 1 thinking")    ← Starts printing
Thread 2: printf("Philo 2 eating")      ← Interrupts Thread 1  
Thread 1: (continues)                   ← Finishes after Thread 2

Output: "Philo Philo 1 thinking2 eating"  ← GARBLED!
```

**With mutex (safe_log):**
```
Thread 1: [LOCK] → printf("Philo 1 thinking") → [UNLOCK]
Thread 2: [WAITING] → [LOCK] → printf("Philo 2 eating") → [UNLOCK]

Output: 
"Philo 1 thinking"
"Philo 2 eating"    ← CLEAN!
```

**Solution Implementation:**
```c
// 1. Add logging mutex to dinner struct:
typedef struct s_dinner {
    // ... existing fields
    pthread_mutex_t logging_mutex;
} t_dinner;

// 2. Create safe logging function:
void    safe_log(t_dinner *dinner, char *message, int philo_id)
{
    pthread_mutex_lock(&dinner->logging_mutex);
    printf("Philo %d %s\n", philo_id, message);
    pthread_mutex_unlock(&dinner->logging_mutex);
}

// 3. Replace all printf calls:
// Instead of: printf("Philo %d is now thinking\n", philo->id);
// Use: safe_log(philo->dinner, "is now thinking", philo->id);
```

**Think of it like a bathroom door** - only one person can be inside at a time, others wait in line!

### Atomic Access and Race Conditions

**What is Atomic Access?**
Atomic access means an operation that completes fully without interruption from other threads. It's "all-or-nothing" - either the entire operation happens, or none of it does.

**The Problem: Race Conditions**
When multiple threads access the same variable simultaneously without protection:

```c
// Thread 1 (philosopher):        // Thread 2 (monitor):
if (!philo->is_dead) {           if (philo->is_dead) {
    // philosopher continues           dinner->dinner_ended = 1;
    philo->is_dead = 1; // ← Sets death
}
```

**Timeline without mutex:**
```
Time 1: Monitor reads is_dead = 0  ← Thinks philosopher is alive
Time 2: Philosopher sets is_dead = 1  ← Dies
Time 3: Monitor continues with old value ← Missed the death!
```

**Solution: Mutex for Atomic Access**
```c
// In philosopher thread:
pthread_mutex_lock(&philo->death_mutex);
if (is_philosopher_dead(philo)) {
    philo->is_dead = 1;
    pthread_mutex_unlock(&philo->death_mutex);
    return; // exit thread
}
pthread_mutex_unlock(&philo->death_mutex);

// In monitor thread:
pthread_mutex_lock(&philo->death_mutex);
if (philo->is_dead) {
    dinner->dinner_ended = 1;
}
pthread_mutex_unlock(&philo->death_mutex);
```

**Why This Works:**
- Only one thread can access `is_dead` at a time
- Read and write operations are now atomic
- No inconsistent intermediate states
- Guaranteed consistent data

**Key Rule:** Any shared variable accessed by multiple threads needs mutex protection for atomic access.

---

## Testing Parameters

**For observing behavior:**
```bash
./philo 3 5000 1000 1000   # 3 philosophers, slow timing
./philo 2 10000 2000 2000  # 2 philosophers, very slow
```

**For stress testing:**
```bash
./philo 5 800 200 200      # Original parameters, fast pace
./philo 10 400 100 100     # Many philosophers, tight timing
```