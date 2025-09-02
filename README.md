# Inverted-Search
A Data Structures project in C that builds an inverted index from multiple text files, allowing efficient word-based search.
---
# 📌 Overview

This project implements an Inverted Search Engine in C using Hash Table and Linked List data structures.
Inverted search, also known as inverted indexing, is a technique used in information retrieval systems, such as search engines, to efficiently retrieve documents or records that contain specific keywords or phrases.
Inverted search, on the other hand, uses an inverted index data structure to store the relationships between keywords or phrases and the documents or records that contain them.
---
# 🔧 Features

- Build an inverted index from multiple text files.
- Store word occurrences with file name, word count, and position.
- Search any word and get details of which files contain it.
- Supports update, display, save, and load of the index.
- Uses hashing + linked lists for efficient storage.
---
# 📂 Data Structures Used

- Hash Table → for fast access to words.
- Linked List → to store word occurrences in multiple files.
- File Handling → to read, build, and save index.
---
# ▶️ How it Works

1. User provides multiple text files as input.
2. Each file is parsed word by word.
3. Words are stored in a hash table bucket (based on hash value).
4. Each word node contains:
- Word
- File name(s) where it occurs
- Frequency count
5. User can:
  - Search → check where a word exists.
  - Update → add new files to index.
  - Display → print the complete index.
  - Save → store index in a file for later use.
 ---
# 🖥️ Sample Run and Output
```bash
./inverted_search file1.txt file2.txt....
```
NFO: List created for file1.txt
INFO: List created for file2.txt
INFO: List created for file3.txt
1. Create database
2. Display database
3. Search database
4. Save database
5. Update database
6. Exit
Enter your choice: 
