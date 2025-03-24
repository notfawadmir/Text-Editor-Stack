# **Text Editor**

A console-based text editor tool that allows users to easily insert text, delete text, and perform undo/redo operations using a stack-based approach. This tool provides a user-friendly interface for managing text, making it ideal for anyone looking to handle basic text editing functionalities in a programmatic way.

## **Features**

### **Text Insertion**
- Insert text at the end of the current text.
  
### **Text Deletion**
- Delete the last specified number of characters from the current text.

### **Undo and Redo**
- Undo the last operation and restore the previous state.
- Redo the last undone operation.

### **Customizable Interface**
- Console-based interactive interface for seamless navigation and operations.

### **Stack-based Operations**
- Uses two stacks for managing undo and redo functionalities.

## **How It Works**

### 1. **Inserting Text**
- Users can insert text at the end of the current content.
- The current state is saved in the undo stack before the modification.

### 2. **Deleting Text**
- Users can delete the last specified number of characters.
- The current state is saved in the undo stack before the deletion.

### 3. **Undo and Redo**
- Undo restores the text to its previous state.
- Redo restores the text to the last undone state.

## **Usage**

### **Installation**

Clone the repository and install the required dependencies (if applicable):

```bash
git clone https://github.com/notfawadmir/text-editor.git
cd text-editor
```

### **Running the Application**

To start the application, use the following command in your terminal:

```bash
python main.py
```

### **Options**
1. **Insert Text:** Insert text into the current document.
2. **Delete Text:** Delete the last specified number of characters from the document.
3. **Undo:** Undo the last operation (insert or delete).
4. **Redo:** Redo the last undone operation.
5. **Display Text:** View the current text in the editor.
6. **Exit:** Exit the program.

## **How to Use**
1. Run the program by executing `python main.py`.
2. Follow the on-screen prompts to insert, delete, undo, or redo operations.
3. View the current text or exit the program as needed.

## **Customization**

- **Headers and Footers:** The current implementation focuses on basic text editing and does not include headers or footers (as these were not part of the initial code).
- **Undo and Redo Stack Size:** You can manage the undo and redo operations with an unlimited history, which will grow dynamically as you continue to perform operations.

## **Dependencies**

The application uses the following common libraries:
- `iostream` (for input/output operations)
- `string` (for handling string operations)

There are no additional external dependencies for this basic functionality.

## **Screenshots**
*Coming Soon!*

## **Contribution**

We welcome contributions! Feel free to:
- Submit a pull request with enhancements or bug fixes.
- Open an issue to suggest new features or improvements.

## **License**

This project is licensed under the **MIT License**.

---

**Happy Editing! 🎉**
