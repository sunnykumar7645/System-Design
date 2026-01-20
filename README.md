# System-Design
System Design notes in c++
🔥 FAANG C++ INTERVIEW QUESTIONS (COMPLETE GUIDE)
🟢 1. C++ BASICS (Warm-up Round)

These filter non-C++ candidates.

Difference between struct and class

What is const correctness?

What is mutable keyword?

What is nullptr vs NULL?

What happens if you don’t initialize a variable?

Difference between #define and const

Why is main() return type int?

What is inline?

Explain static keyword (local, global, class)

Why is sizeof(char) == 1?

🟡 2. MEMORY MANAGEMENT (VERY IMPORTANT)

Asked heavily by Google & Amazon.

Stack vs Heap

What is memory leak?

Dangling pointer

Wild pointer

new vs malloc

Why delete vs free

What happens if destructor is not virtual?

Who frees memory in smart pointers?

What is RAII?

What is placement new?

👉 Expect follow-ups & code tracing

🟡 3. OOPS (CORE FAANG AREA)
🔹 Constructors & Destructors

Copy constructor vs move constructor

When is copy constructor called?

Why copy constructor takes const&

Rule of 3 / Rule of 5

Defaulted vs deleted constructors

🔹 Polymorphism

What is virtual function?

Virtual table (vtable) explanation

What happens if destructor is not virtual?

Can constructor be virtual? ❌ Why?

Function overriding vs overloading

🔹 Inheritance

Diamond problem

Virtual inheritance

Access specifiers effect

Object slicing

final keyword

🟡 4. POINTERS & REFERENCES (FAANG FAVORITE)

Pointer vs reference

Double pointer use cases

Pointer arithmetic

const int* p vs int* const p

Can reference be NULL?

Smart pointer types:

unique_ptr

shared_ptr

weak_ptr

When to use weak_ptr

Cyclic dependency problem

🟡 5. STL (MOST IMPORTANT FOR FAANG)
🔹 Containers

vector vs list

map vs unordered_map

Why unordered_map is faster?

When unordered_map becomes slow?

Collision handling

Iterators invalidation

🔹 Algorithms

How sort() works internally

stable_sort vs sort

Time complexity of STL operations

Why comparator must be strict weak ordering?

🔹 Custom Comparator

Write comparator for:

sort

set

priority_queue

🔴 6. ADVANCED C++ (GOOGLE / META LEVEL)
🔹 Move Semantics

What is move constructor?

Why std::move doesn’t move?

Rvalue vs lvalue

Universal reference

Perfect forwarding

🔹 Templates

Function templates

Class templates

Template specialization

typename vs class

SFINAE (basic idea)

🔹 Lambda Expressions

Capture list [=] [&]

Mutable lambda

Lambda vs function pointer

🔴 7. MULTITHREADING & CONCURRENCY (VERY IMPORTANT)
Asked heavily by Google, Meta

Process vs thread

Race condition

Deadlock (conditions)

Mutex vs semaphore

Spinlock

Atomic variables

Thread safety

Producer-Consumer problem

Reader-Writer problem

How to avoid deadlock?

🔴 8. SYSTEM DESIGN + C++ (GOOGLE / NETFLIX)

Design thread-safe cache

Design LRU cache (C++)

Memory-efficient string storage

Design rate limiter

Design logger system

Object pool design

Singleton design pattern (thread-safe)

🔥 9. CODE-BASED INTERVIEW QUESTIONS
Very common FAANG prompts:

Implement your own shared_ptr

Implement memcpy

Implement strlen

Reverse linked list

Detect memory leak

Implement thread-safe singleton

Custom allocator

Overload new and delete

🔥 10. TRICK / EDGE QUESTIONS (FAANG STYLE)

What happens if exception is thrown in destructor?

Can delete this be called?

Can we overload . operator?

Why vector grows exponentially?

Why destructor should not throw?

Can static function be virtual?

Can template be virtual?

🧠 HOW FAANG INTERVIEWS EVALUATE YOU

They check:

Memory safety

Performance

STL mastery

Edge cases

Clear explanation

❌ Not syntax
✅ Reasoning

📌 FINAL INTERVIEW TIP (VERY IMPORTANT)

If you can clearly explain:

Copy vs move

Smart pointers

STL internals

Thread safety

Object lifetime

👉 You are FAANG-ready in C++

🚀 Next Steps (Tell me what you want)

I can:

Simulate Google C++ mock interview

Give company-wise questions (Google vs Amazon vs Meta)

Provide C++ cheat sheet PDF

Give coding + explanation problems