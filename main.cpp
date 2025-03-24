#include <iostream>
#include <string>

using namespace std;

// Node class represents a node in the stack to store the text
class node
{
public:
    string text;  // Holds the text data
    node *next;   // Points to the next node in the stack

    // Constructor to initialize a node with a string value
    node(string data)
    {
        text = data;   // Set the text of the node
        next = nullptr; // Initialize the next pointer to nullptr (end of stack)
    }
};

// Stack class to handle stack operations
class stack
{
private:
    node *top;  // Pointer to the top node of the stack
    int size;   // Keeps track of the size of the stack

public:
    // Constructor to initialize stack
    stack() : top(nullptr), size(0) {}

    // Check if the stack is empty
    bool isEmpty()
    {
        return top == nullptr; // Stack is empty if top is nullptr
    }

    // Push a new string onto the stack
    void push(string val)
    {
        node *newNode = new node(val); // Create a new node with the given string
        newNode->next = top;           // Link the new node to the top of the stack
        top = newNode;                 // Update the top to point to the new node
        size++;                        // Increment the size of the stack
    }

    // Get the top value of the stack without removing it
    string Top()
    {
        if (isEmpty())
        {
            cout << "Stack Is Empty! Nothing To Show\n";
            return "nothing";  // Return a placeholder value if stack is empty
        }
        return top->text;  // Return the text stored in the top node
    }

    // Pop the top element from the stack
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Is Empty! Nothing To Pop\n";
            return;  // Do nothing if stack is empty
        }
        node *temp = top;    // Store the top node temporarily
        top = top->next;     // Move the top pointer to the next node
        delete temp;         // Delete the old top node
        size--;              // Decrement the size of the stack
    }

    // Display all elements in the stack
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty! Nothing To Display";
            return; // Do nothing if stack is empty
        }
        node *top = this->top;  // Create a temporary pointer to traverse the stack
        while (top != nullptr)  // Traverse the stack until the end
        {
            cout << top->text << " ";  // Print the text of each node
            top = top->next;           // Move to the next node
        }
        cout << endl;  // Print a newline after displaying all elements
    }

    // Destructor to clean up dynamically allocated memory
    ~stack()
    {
        while (!isEmpty())  // Continue popping until the stack is empty
        {
            pop();
        }
    }
};

// TextEditor class to simulate a simple text editor with undo/redo functionality
class TextEditor
{
private:
    stack undoStack; // Stores past states for undo operation
    stack redoStack; // Stores undone states for redo operation
    string text;     // Current text content of the editor

public:
    // Insert text at the end of the current text
    void insertText(const string &newText)
    {
        undoStack.push(text); // Save the current text state before modification
        while (!redoStack.isEmpty())
            redoStack.pop(); // Clear redo stack because new text operation invalidates redo history
        text += newText;     // Append the new text to the current content
        text += " | ";       // Add a separator (optional) for clarity
    }

    // Delete the last 'count' characters from the current text
    void deleteText(int count) 
    {
        if (text.empty()) // Check if there is any text to delete
        {
            cout << "Nothing to delete!" << endl;
            return; // If no text, do nothing
        }
        undoStack.push(text); // Save the current text state before modification
        while (!redoStack.isEmpty()) redoStack.pop(); // Clear redo stack because new delete operation invalidates redo history
        text.erase(text.length() - min(count, (int)text.length())); // Delete 'count' characters from the end, ensuring we don't go out of bounds
    }

    // Undo the last operation (either insert or delete)
    void undo()
    {
        if (!undoStack.isEmpty())  // Check if there is an operation to undo
        {
            redoStack.push(text);   // Save the current state for redo operation
            text = undoStack.Top(); // Get the previous state of text from the undo stack
            undoStack.pop();        // Pop the undo stack to remove the last operation
        }
        else
        {
            cout << "Nothing to undo!" << endl;  // Display an error message if no operations to undo
        }
    }

    // Redo the last undone operation
    void redo()
    {
        if (!redoStack.isEmpty())  // Check if there is an undone operation to redo
        {
            undoStack.push(text);   // Save the current state for undo operation
            text = redoStack.Top(); // Get the redone state of text from the redo stack
            redoStack.pop();        // Pop the redo stack to remove the last undone operation
        }
        else
        {
            cout << "Nothing to redo!" << endl;  // Display an error message if no operations to redo
        }
    }

    // Display the current text in the editor
    void displayText() const
    {
        if (text.empty()) // Check if the text is empty
        {
            cout << "\nNothing Written !!!" << endl;
            return; // Print message if no text has been written
        }
        cout << "Current Text: " << text << endl;  // Print the current text
    }
};

// Main function to run the text editor simulation
int main()
{
    TextEditor editor;  // Create an instance of the TextEditor class
    int choice;         // Variable to store user choice
    string input;       // Variable to store input text
    int count;          // Variable to store the number of characters to delete

    // Run an infinite loop to keep the program running
    while (true)
    {
        // Show the menu options to the user
        cout << "\n1. Insert Text\n2. Delete Text\n3. Undo\n4. Redo\n5. Display Text\n6. Exit\nEnter choice: ";
        cin >> choice;   // Read user choice
        cin.ignore();    // Ignore the newline character left by cin

        // Handle the user's choice
        switch (choice)
        {
        case 1:  // Insert text option
            cout << "Enter text to insert: ";
            getline(cin, input);  // Read the text input from the user
            editor.insertText(input);  // Call insertText function to add the text
            break;
        case 2:  // Delete text option
            cout << "Enter number of characters to delete: ";
            cin >> count;  // Read the number of characters to delete
            editor.deleteText(count);  // Call deleteText function to delete the text
            break;
        case 3:  // Undo option
            editor.undo();  // Call the undo function to revert the last operation
            break;
        case 4:  // Redo option
            editor.redo();  // Call the redo function to redo the last undone operation
            break;
        case 5:  // Display text option
            editor.displayText();  // Call displayText function to show the current text
            break;
        case 6:  // Exit option
            return 0;  // Exit the program
        default:  // Invalid choice
            cout << "Invalid choice! Try again." << endl;  // Display error message for invalid choice
        }
    }
}
