# Inverted-Search
A Data Structures project in C that builds an inverted index from multiple text files, allowing efficient word-based search.
---
# 📌 Overview

Inverted Search Engine in C
This project demonstrates an Inverted Search Engine implemented in C, utilizing Hash Table and Linked List data structures.
Inverted search (or inverted indexing) is a fundamental technique in information retrieval systems, widely used in search engines, to quickly locate documents or records containing specific keywords or phrases.
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
# 🖥️ Sample Run
```bash
./inverted_search file1.txt file2.txt....
```
# Output:
- INFO: List created for file1.txt
- INFO: List created for file2.txt
- INFO: List created for file3.txt
1. Create database
2. Display database
3. Search database
4. Save database
5. Update database
6. Exit
Enter your choice: 
