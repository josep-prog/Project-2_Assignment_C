# 

| Name  | Link |
| :---- | :---- |
| **Github Repository** | **[Project 2\_Assignment](https://github.com/josep-prog/Project-2_Assignment_C.git)**  |
| **Project 1: Dynamic Student Record Engine** | **[StudentRecord\_Engine.c](https://github.com/josep-prog/Project-2_Assignment_C/blob/main/StudentRecord_Engine.c)**  |
| **Project 2: Adaptive Text Intelligence Tool** | **[TextIntelligence.c](https://github.com/josep-prog/Project-2_Assignment_C/blob/main/TextIntelligence.c)**  |
| **Project 3: Callback-Based Device Monitoring Simulator** | **[MonitoringSimulator.c](https://github.com/josep-prog/Project-2_Assignment_C/blob/main/MonitoringSimulator.c)**  |

# 

# **1\. Dynamic Student Record Engine ([StudentRecord\_Engine.c](https://github.com/josep-prog/Project-2_Assignment_C/blob/main/StudentRecord_Engine.c))**

I used a Student structure to keep all the details of each student. I allocated memory dynamically with malloc so that the system can easily handle any number of students the user wants to add.

A menu allows the user to choose what they want to do. To make it more flexible, I used function pointers to call different operations like adding students, displaying them, sorting them, and classifying their grades

Sorting works by comparing grades and swapping records when needed. The program also calculates the class average and finds the top student by going through the array with pointers, which felt more like I was really controlling the data myself.

## **Critical Challenge Faced**

One challenge I faced was handling **user input for student names** correctly. When using scanf before reading names with fgets, the newline character remained in the input buffer and caused the program to skip name input.

## **Solution**

To solve this problem, getchar() was used after scanf to clear the input buffer before calling fgets. This ensured that the name input was read correctly without skipping.

# **2\. Adaptive Text Intelligence Tool ([TextIntelligence.c](https://github.com/josep-prog/Project-2_Assignment_C/blob/main/TextIntelligence.c) )**

Dynamically allocated memory to store both the input text and the word statistics so the system could handle different paragraph sizes easily. I created a structure called WordStat to keep each word and how many times it appears.

I wrote the logic to go through the text **character by character using pointers**, which made me feel like I was really controlling how the text is read. Alphabetic characters are grouped to build words, and non-alphabetic characters signal the end of a word.

When a word already exists in the list, I increase its count using strcmp; if it’s new, I copy it into the array with strcpy. 

**Challenge Faced**

One challenge was **detecting words correctly while reading the text**. Special characters, punctuation, and uppercase letters could affect the accuracy of word detection.

## **Solution**

To solve this, the program checks whether a character is alphabetic before adding it to a word. Uppercase letters are converted to lowercase to ensure consistent comparison. This improves the accuracy of word counting and frequency detection.

# **3\. Callback-Based Device Monitoring Simulator ([MonitoringSimulator.c](https://github.com/josep-prog/Project-2_Assignment_C/blob/main/MonitoringSimulator.c))** 

I used a structure called Device to represent each sensor. It stores the device name, type, and a union for the reading. The union was especially interesting because it lets different types of measurements like temperature, pressure, or battery voltage share the same memory space, which feels very efficient.

I allocated memory dynamically with malloc to handle multiple devices, so the system can easily scale if more sensors are added. To make the simulation more realistic, I generated 10 random readings for the devices using the rand() function, which made the whole process feel like a live monitoring system.

## **Challenge I Faced**

The main challenge was understanding how **unions work**. Since all union members share the same memory location, storing one value overwrites the previous value.

## **Solution**

## I created a function called demo\_union(). It shows how storing different values in the union overwrites the previous ones, giving a clear picture of how unions share memory. This also helped me verify that everything was working as expected and gave a more hands-on feel to learning how unions operate.