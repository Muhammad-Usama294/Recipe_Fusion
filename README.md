# 🍳 Recipe_Fusion - Recipe Management System

[![C++](https://img.shields.io/badge/C++-11-blue.svg)](https://isocpp.org/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)

A comprehensive C++ console-based **Recipe Management System** featuring role-based access control for administrators and users. Recipe_Fusion provides an intuitive interface for managing recipes, ingredients, and user accounts with file-based data persistence and transaction logging.

## ✨ Features

### 👨‍💼 Admin Functionality
- 🔐 **Secure Admin Login** - Password-protected administrator access
- ➕ **Add New Recipes** - Create recipes with ingredients and step-by-step cooking instructions
- ❌ **Delete Recipes** - Remove outdated or unwanted recipes from the database
- 📋 **View All Recipes** - Browse complete recipe collection
- 🧪 **Ingredient Management** - Add, edit, delete, and search ingredients
- 📝 **Admin Transaction Logging** - Automatic logging of all administrative actions
- 👥 **User Management** - Add and manage user accounts
- 🔄 **Profile Management** - Edit admin profile information

### 👨‍🍳 User Functionality
- 🔓 **User Login** - Secure user authentication system
- 🔍 **Browse Recipes** - View all available recipes in the database
- 🔎 **Search Recipes** - Find recipes by name or ingredients
- 📖 **View Recipe Details** - Access complete recipe information including ingredients and cooking steps
- 👤 **Profile Management** - Update user profile settings
- 🖥️ **User-Friendly Interface** - Intuitive console-based navigation

### 💾 System Features
- **File-Based Data Persistence** - All data stored in text files for easy access and portability
- **Transaction Logging System** - Comprehensive audit trail for administrative activities
- **Input Validation** - Robust error checking and data validation
- **Role-Based Access Control** - Separate admin and user privileges

## 🗂️ Data Structure

Recipe_Fusion utilizes **vector-based data structures** from the C++ Standard Template Library (STL) for efficient data management:

- **Recipe Storage**: Recipes are stored as objects containing:
  - Recipe name
  - Vector of `IngredientUsage` objects (ingredient references with quantities)
  - Vector of cooking steps (string instructions)

- **Ingredient Database**: Maintains a vector of ingredients with:
  - Ingredient name
  - Category (e.g., meats, vegetables)
  - Nutritional information

- **User Management**: Vectors storing admin and user account information with:
  - User ID
  - Name
  - Encrypted password

The system provides efficient search and retrieval operations through STL algorithms, with potential for future enhancement using graph structures for recipe recommendations based on ingredient relationships.

## 🛠️ Technologies Used

- **Language**: C++ (C++11 standard)
- **Data Structures**: Standard Template Library (STL)
  - `vector` for dynamic arrays
  - `string` for text manipulation
  - `fstream` for file operations
- **File I/O**: Binary and text file handling for data persistence
- **Platform**: Windows (uses `windows.h` for console operations)
- **Development Tools**: g++ compiler compatible

## 📁 File Structure

```
Recipe_Fusion/
├── Final Recipie Generator dev.cpp    # Main source code file
├── Admins.txt                         # Admin account data (binary)
├── Users.txt                          # User account data (binary)
├── Recipes.txt                        # Recipe database (text)
├── Ingredients.txt                    # Ingredient database (binary)
├── AdminsTransactions.txt             # Admin activity log (text)
├── Final Recipie Generator dev.exe    # Compiled executable
└── README.md                          # This file
```

## 🚀 How to Build and Run

### Prerequisites
- C++ compiler with C++11 support (g++, MinGW, or Visual Studio)
- Windows operating system (for current implementation)

### Compilation

#### Using g++:
```bash
# Navigate to project directory
cd Recipe_Fusion

# Compile the project
g++ -o RecipeFusion "Final Recipie Generator dev.cpp" -std=c++11

# Run the executable
./RecipeFusion
```

#### Using MinGW on Windows:
```bash
g++ -o RecipeFusion.exe "Final Recipie Generator dev.cpp" -std=c++11
RecipeFusion.exe
```

#### Using Visual Studio:
1. Open Visual Studio
2. Create a new Console Application project
3. Add `Final Recipie Generator dev.cpp` to the project
4. Build and run (F5)

## 📖 Usage Guide

### First Time Setup
On the first run, the system will prompt you to create an administrator account. Follow the on-screen instructions to set up:
- Admin ID
- Admin Name
- Admin Password

### 👨‍💼 Admin Features

1. **Login as Admin**
   - Select option `1` from the main menu
   - Enter your Admin ID
   - Enter your password

2. **Manage Ingredients**
   - Add new ingredients with name, category, and nutritional info
   - Edit existing ingredient details
   - Delete ingredients from the database
   - Search for specific ingredients
   - View all ingredients

3. **Manage Recipes**
   - Add new recipes with:
     - Recipe name
     - Multiple ingredients with quantities
     - Step-by-step cooking instructions
   - Delete recipes
   - View all recipes
   - Search recipes by name or ingredients

4. **User Management**
   - Create new user accounts
   - Manage user access

5. **View Transaction Logs**
   - Review all administrative actions
   - Track recipe additions and deletions

### 👨‍🍳 User Features

1. **Login as User**
   - Select option `2` from the main menu
   - Enter your User ID
   - Enter your password

2. **Browse Recipes**
   - View complete list of available recipes
   - Access recipe details including ingredients and cooking steps

3. **Search Recipes**
   - Search by recipe name
   - Search by ingredient name
   - Filter recipes based on available ingredients

4. **Profile Management**
   - Update your name
   - Change your password

## 📄 File Format

### AdminsTransactions.txt
Transaction log format:
```
Admin : <AdminName> ID : <AdminID> <Action> Recipe of <RecipeName>
```

Example:
```
Admin : Usama ID : 100 added Recipe of Test
```

### Recipes.txt
Recipe storage format:
```
<TotalRecipes>
<RecipeName>
<NumberOfIngredients>
<IngredientName>,<Quantity>
...
<NumberOfSteps>
<Step1>
<Step2>
...
```

Example:
```
16
Chicken Biryani
9
Chicken,500g pieces
Basmati Rice,2 cups, soaked
Yogurt,1/2 cup
...
7
Heat ghee/oil in a pan, add sliced onions and fry until golden brown.
Add garlic, ginger, green chilies, and tomatoes to the pan.
...
```

### Admins.txt and Users.txt
Binary files storing account information (ID, name, password).

### Ingredients.txt
Binary file storing ingredient data (name, category, nutritional information).

## 🔐 Admin Access

The system requires at least one administrator account for initial setup. On the first run:

1. The system detects no admin accounts exist
2. Prompts for admin creation
3. You provide:
   - Unique Admin ID (numeric)
   - Admin Name
   - Secure Password

**Security Note**: Passwords are stored and should be kept confidential. In production environments, consider implementing password hashing.

## 🚀 Future Enhancements

Potential improvements to expand Recipe_Fusion's capabilities:

### Enhanced Features
- ⭐ **Recipe Ratings and Reviews** - Allow users to rate and review recipes
- 🔄 **Ingredient Substitution Suggestions** - Recommend alternative ingredients
- 🥗 **Nutrition Information Integration** - Calculate nutritional values per serving
- 🎯 **Recipe Recommendation Engine** - Graph-based recommendations using ingredient relationships
- 📊 **Recipe Difficulty Levels** - Categorize recipes by complexity
- ⏱️ **Cooking Time Tracking** - Add preparation and cooking duration
- 🏷️ **Recipe Categories** - Organize by cuisine type, meal type, dietary restrictions

### Technical Improvements
- 🌐 **Web Interface** - Develop a web-based frontend
- 📱 **Mobile Application** - Create iOS/Android apps
- 🗄️ **Database Integration** - Migrate to MySQL/PostgreSQL for scalability
- 🖼️ **Image Upload** - Add recipe photos and step-by-step images
- 🛒 **Shopping List Generation** - Auto-generate ingredient shopping lists
- 📈 **Graph Data Structure** - Implement graph for ingredient relationships
- 🔒 **Enhanced Security** - Add password hashing and encryption
- 🔄 **Import/Export** - Support for recipe file formats (JSON, XML)
- 🌍 **Cross-Platform Support** - Port to Linux and macOS

## 📂 Project Structure

```
Recipe_Fusion/
├── src/
│   └── Final Recipie Generator dev.cpp    # Main application source
├── data/
│   ├── AdminsTransactions.txt             # Transaction logs
│   ├── Recipes.txt                        # Recipe database
│   ├── Ingredients.txt                    # Ingredient database
│   ├── Admins.txt                         # Admin accounts
│   └── Users.txt                          # User accounts
├── bin/
│   └── Final Recipie Generator dev.exe    # Compiled executable
└── README.md                              # Documentation

### Class Hierarchy:
- Person (Base Class)
  ├── Admin
  └── User
- Ingredient
- IngredientUsage
- Recipe
- IngredientsDatabase
- RecipeGenerator (Main System Class)
```

## 🤝 Contributing

Contributions are welcome! To contribute to Recipe_Fusion:

1. **Fork the Repository**
   ```bash
   git clone https://github.com/Muhammad-Usama294/Recipe_Fusion.git
   ```

2. **Create a Feature Branch**
   ```bash
   git checkout -b feature/YourFeatureName
   ```

3. **Make Your Changes**
   - Follow the existing code style
   - Add comments for complex logic
   - Test your changes thoroughly

4. **Commit Your Changes**
   ```bash
   git commit -m "Add: Description of your changes"
   ```

5. **Push to Your Branch**
   ```bash
   git push origin feature/YourFeatureName
   ```

6. **Open a Pull Request**
   - Provide a clear description of changes
   - Reference any related issues

### Coding Standards
- Use meaningful variable and function names
- Follow C++ best practices
- Add comments for complex algorithms
- Maintain consistent indentation (spaces/tabs)
- Test all new features before submitting

## 👥 Authors

- **Muhammad Usama** - *Initial Development* - [Muhammad-Usama294](https://github.com/Muhammad-Usama294)

## 📄 License

This project is licensed under the **MIT License** - see below for details:

```
MIT License

Copyright (c) 2024 Muhammad Usama

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

## 🙏 Acknowledgments

- Thanks to all contributors and users of Recipe_Fusion
- Inspired by the need for efficient recipe management systems
- Built with passion for cooking and programming

---

### 📞 Contact & Support

For questions, suggestions, or issues:
- Open an issue on GitHub
- Contact the maintainer through GitHub profile

**Happy Cooking with Recipe_Fusion! 🍳👨‍🍳**
