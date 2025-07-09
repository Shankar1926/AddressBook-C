# 📒 Address Book in C

> A terminal-based address book application built using the C programming language. This project features full contact management, input validation, and file-based data persistence, following clean modular design principles.

---

## 🔧 Features

- ✅ Add new contacts (Name, Phone, Email)
- 🔍 Search contacts by:
  - Name
  - Phone Number
  - Email ID
- ✏️ Edit existing contact details
- ❌ Delete contacts with confirmation
- 📄 Save/load contacts automatically using `contact.csv`
- 🔒 Input validation for:
  - 10-digit phone numbers
  - Properly formatted `.com` email addresses
- 💡 Modular `.c` and `.h` file structure

---

## 🧠 Concepts Practiced

- `struct` usage for storing complex data
- File handling using `fopen()`, `fscanf()`, `fprintf()`
- String and character array manipulation
- Modular programming (`.h` + `.c` separation)
- Error handling and safe user input
- Menu-driven program design

---

## 📁 Project Structure

```
addressbook/
├── main.c                     // Main menu driver
├── contact.c / contact.h      // Core contact operations
├── file.c / file.h            // Save/load contacts to file
├── validate.c / validate.h    // Phone and email validation
├── edit_contact.c / .h        // Edit contact logic
├── search_contact.c / .h      // Search functionality
├── delete_contact.c / .h      // Delete contact logic
├── contact.csv                // Data file (auto-created)
└── README.md                  // Project documentation
```

---

## ⚙️ Compilation Instructions

Use the following `gcc` command to compile:

```bash
gcc main.c contact.c file.c validate.c edit_contact.c search_contact.c delete_contact.c -o addressbook
```

To run the program:

```bash
./addressbook
```

---

## 📸 Sample Terminal UI

```
Address Book Menu:
1. Create contact
2. Search contact
3. Edit contact
4. Delete contact
5. List all contacts
6. Exit

Enter your choice:
```

---

## 📦 Future Improvements (Ideas)

- Add contact grouping (by tags or categories)
- Export contacts to PDF or JSON
- GUI-based version using C++
- Search with partial keyword matching
- Undo feature for deletions

---

## 👨‍💻 About the Developer

**👤 Shankar K**   
📧 shankarkumar98941@gmail.com  
🔗 [LinkedIn] : https://www.linkedin.com/in/shankar-kumar26/
---

## 📎 License

This project is licensed for educational and open-source use. Feel free to fork or contribute.

---

## 🙌 Feedback

Have suggestions or improvements?  
Open an issue or pull request — collaboration is welcome!
