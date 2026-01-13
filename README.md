# 🍳 Recipe_Fusion - Recipe Management System

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Data Structure](https://img.shields.io/badge/Data_Structure-Graph-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Active-success?style=for-the-badge)

A powerful **Recipe Management System** built with C++ that enables efficient recipe organization, discovery, and management through advanced graph data structures. This application supports both administrative and user functionalities with a focus on ingredient-based recipe recommendations.

---

## 📖 Table of Contents
- [Features](#-features)
- [Data Structures](#-data-structures)
- [Technologies Used](#-technologies-used)
- [File Structure](#-file-structure)
- [System Architecture](#-system-architecture)
- [How to Build and Run](#-how-to-build-and-run)
- [Usage Guide](#-usage-guide)
- [Data File Format](#-data-file-format)
- [Example Usage](#-example-usage)
- [Future Enhancements](#-future-enhancements)
- [Contributing](#-contributing)
- [Authors](#-authors)
- [License](#-license)

---

## ✨ Features

### 👨‍💼 Admin Features
- **Recipe Management**
  - ➕ Add new recipes with ingredients and cooking steps
  - 🗑️ Delete existing recipes from the database
  - 📋 View all recipes in the system
  - ✏️ Manage recipe ingredients and cooking instructions

- **Ingredient Database**
  - 🥗 Add, edit, and delete ingredients
  - 🔍 Search ingredients by name
  - 📊 View complete ingredients list
  - 📝 Manage nutritional information and categories

- **Administrative Controls**
  - 👥 Add and remove admin accounts
  - 🔐 Edit admin profiles
  - 📄 Transaction logging (AdminsTransactions.txt)
  - 🛡️ Secure authentication system

### 👤 User Features
- **Recipe Discovery**
  - 🔎 Browse all available recipes
  - 🍽️ View detailed recipe information (ingredients, quantities, steps)
  - 🥘 Search recipes by name
  - 🎯 **Smart Ingredient-Based Search** - Find recipes based on available ingredients

- **User Management**
  - 📝 User registration and authentication
  - 👤 Profile management
  - 🔒 Secure login system

---

## 🗂️ Data Structures

### Recipe Graph Implementation
The Recipe_Fusion system utilizes **graph-based data structures** to efficiently manage and relate recipes:

- **Nodes**: Each node represents a recipe with its complete information (name, ingredients, cooking steps)
- **Edges**: Connections between recipes based on:
  - Similar ingredients
  - Cuisine type relationships
  - Cooking method similarities
  
This graph structure enables:
- ⚡ Fast recipe discovery and search
- 🎯 Intelligent recipe recommendations
- 🔗 Efficient ingredient-based recipe matching
- 📊 Optimized data traversal and retrieval

**Key Data Structures Used:**
- `vector<Recipe>` - Dynamic recipe storage
- `vector<IngredientUsage>` - Ingredient composition per recipe
- `vector<string>` - Cooking steps storage
- Graph algorithms for recipe relationship mapping

---

## 💻 Technologies Used

- **Language**: C++ (Standard C++11 or higher)
- **Core Data Structures**: 
  - Graph (for recipe relationships)
  - Vectors (dynamic arrays)
  - Classes and OOP principles
- **File I/O**: Text file-based data persistence
- **Libraries**:
  - `<iostream>` - Input/output operations
  - `<fstream>` - File handling
  - `<vector>` - Dynamic arrays
  - `<sstream>` - String stream processing
  - `<windows.h>` - Console operations (Windows-specific)
  - `<conio.h>` - Console input/output

---

## 📁 File Structure

```
Recipe_Fusion/
├── Final Recipie Generator dev.cpp    # Main application source code
├── Final Recipie Generator dev.exe    # Compiled executable
├── Admins.txt                         # Admin credentials storage
├── Users.txt                          # User credentials storage
├── Recipes.txt                        # Recipe database
├── Ingredients.txt                    # Ingredients database
├── AdminsTransactions.txt             # Admin activity logs
└── README.md                          # Project documentation
```

### File Descriptions:
- **`Final Recipie Generator dev.cpp`** - Complete source code with all classes and functions
- **`Admins.txt`** - Stores admin account information (ID, name, password)
- **`Users.txt`** - Stores user account information (ID, name, password)
- **`Recipes.txt`** - Persistent storage for all recipes with ingredients and steps
- **`Ingredients.txt`** - Database of available ingredients with nutritional info
- **`AdminsTransactions.txt`** - Logs all administrative actions for audit trail

---

## 🏗️ System Architecture

```
Recipe_Fusion System
│
├── 👨‍💼 Admin Module
│   ├── Recipe Management
│   │   ├── Add Recipe
│   │   ├── Delete Recipe
│   │   └── View Recipes
│   ├── Ingredient Management
│   │   ├── Add Ingredient
│   │   ├── Edit Ingredient
│   │   ├── Delete Ingredient
│   │   └── Search Ingredient
│   ├── Admin Management
│   │   ├── Add Admin
│   │   ├── Remove Admin
│   │   └── Edit Profile
│   └── Transaction Logging
│       └── AdminsTransactions.txt
│
├── 👤 User Module
│   ├── Browse Recipes
│   ├── Search by Name
│   ├── Search by Ingredients (Main Feature)
│   ├── View Recipe Details
│   └── User Authentication
│
└── 💾 Data Layer
    ├── Recipe Storage (Recipes.txt)
    ├── Ingredient Storage (Ingredients.txt)
    ├── User Management (Users.txt)
    ├── Admin Management (Admins.txt)
    └── File Persistence System
```

### Core Classes:
- **`Person`** - Base class for users and admins
- **`Admin`** - Admin functionality and authentication
- **`User`** - User functionality and authentication
- **`Recipe`** - Recipe data structure with ingredients and steps
- **`Ingredient`** - Ingredient with nutritional information
- **`IngredientUsage`** - Links ingredients to recipes with quantities
- **`IngredientsDatabase`** - Manages ingredient operations
- **`RecipeGenerator`** - Main system controller and recipe manager

---

## 🚀 How to Build and Run

### Prerequisites
- C++ compiler (g++, MinGW, or Visual Studio)
- Windows OS (for `windows.h` and `conio.h` dependencies)

### Compilation

#### Using g++ (MinGW):
```bash
# Navigate to the project directory
cd Recipe_Fusion

# Compile the source code
g++ "Final Recipie Generator dev.cpp" -o RecipeFusion

# Run the executable
./RecipeFusion
```

#### Using Visual Studio:
```bash
# Open Visual Studio
# Create a new C++ project
# Add "Final Recipie Generator dev.cpp" to the project
# Build (Ctrl+Shift+B)
# Run (F5)
```

#### Using MinGW-w64:
```bash
g++ -std=c++11 "Final Recipie Generator dev.cpp" -o RecipeFusion.exe
RecipeFusion.exe
```

### First Run
On the first run, the system will prompt you to create a **Manager Admin** account. This is the master admin who can add/remove other admins.

---

## 📘 Usage Guide

### 1️⃣ Starting the Application
Run the executable and you'll see the main menu:
```
1. Enter as Admin
2. Enter as User
3. Exit
```

### 2️⃣ Admin Mode

#### Login as Admin
1. Select option `1` from the main menu
2. Enter your Admin ID and password
3. Access the Admin Menu

#### Adding a Recipe
1. Navigate to **Recipes Menu** → **Add Recipe**
2. Enter recipe name
3. Add ingredients with quantities (e.g., "Rice, 1kg")
4. Add cooking steps
5. Recipe is automatically saved to `Recipes.txt`
6. Transaction logged in `AdminsTransactions.txt`

#### Managing Ingredients
1. Navigate to **Ingredients Menu**
2. Add ingredients with nutritional information
3. Edit or delete existing ingredients
4. Search for specific ingredients

### 3️⃣ User Mode

#### User Registration
1. Select option `2` from the main menu
2. If first-time user, create an account
3. Enter username and password

#### Browsing Recipes
1. After login, access the User Menu
2. Select **View All Recipes** to browse
3. Select a recipe to view full details (ingredients and cooking steps)

#### Searching by Ingredients (🌟 Main Feature)
1. Select **Search Recipe by Ingredients**
2. Enter available ingredients (comma-separated)
3. System uses graph algorithms to find matching recipes
4. View recommended recipes based on your ingredients

#### Searching by Name
1. Select **Search Recipe by Name**
2. Enter recipe name (partial match supported)
3. View matching recipes

---

## 📄 Data File Format

### Recipes.txt Format
```
<Number of Recipes>
<Recipe Name>
<Number of Ingredients>
<Ingredient1>,<Quantity>
<Ingredient2>,<Quantity>
...
<Number of Steps>
<Step 1>
<Step 2>
...
```

**Example:**
```
16
Biryani
2
Rice,1kg
Chicken,1kg
1
cook and serve
```

### Ingredients.txt Format
```
<Ingredient Name>    <Category>    <Nutritional Information>
```

**Example:**
```
Test 1                Test                Null
```

### AdminsTransactions.txt Format
```
Admin : <Name> ID : <ID> added Recipe of <Recipe Name>
```

**Example:**
```
Admin : Usama ID : 100 added Recipe of Test
```

### Admins.txt / Users.txt Format
Binary file format storing:
- ID (integer)
- Name (char array, 40 bytes)
- Password (char array, 20 bytes)

---

## 🎯 Example Usage

### Sample Admin Transaction:
```
Admin : Usama ID : 100 added Recipe of Biryani
```

### Sample Recipe Entry:
```
Recipe: Chicken Biryani
Ingredients:
  - Rice: 1kg
  - Chicken: 1kg
  - Salt: 1tbsp
  - Red Chilli: 10g
Cooking Steps:
  1. Marinate chicken with spices
  2. Cook rice separately
  3. Layer rice and chicken
  4. Cook on low heat for 20 minutes
```

### Sample Ingredient Search:
```
User Input: Rice, Chicken
Recommended Recipes:
  1. Biryani
  2. Chicken Fried Rice
  3. Chicken Pulao
```

---

## 🔮 Future Enhancements

- [ ] **Graph-Based Recommendations** - Enhanced recipe suggestions based on ingredient similarity
- [ ] **Nutritional Calculator** - Automatic calculation of total calories and nutrients
- [ ] **Recipe Rating System** - Allow users to rate and review recipes
- [ ] **Image Support** - Add photos for recipes
- [ ] **Export Functionality** - Export recipes to PDF or text files
- [ ] **Web Interface** - Create a web-based GUI for easier access
- [ ] **Mobile App** - Develop mobile applications for iOS and Android
- [ ] **Advanced Search Filters** - Filter by cuisine, cooking time, difficulty level
- [ ] **Shopping List Generator** - Auto-generate shopping lists from recipes
- [ ] **Meal Planning** - Weekly meal planning feature
- [ ] **Cross-Platform Support** - Port to Linux and macOS
- [ ] **Database Integration** - Replace text files with SQL database
- [ ] **Recipe Sharing** - Import/export recipes between users
- [ ] **Voice Commands** - Hands-free cooking assistance
- [ ] **Ingredient Substitutions** - Suggest alternative ingredients

---

## 🤝 Contributing

We welcome contributions to the Recipe_Fusion project! Here's how you can help:

### How to Contribute
1. **Fork** the repository
2. **Clone** your fork locally
   ```bash
   git clone https://github.com/your-username/Recipe_Fusion.git
   ```
3. **Create a branch** for your feature
   ```bash
   git checkout -b feature/YourFeatureName
   ```
4. **Make your changes** and test thoroughly
5. **Commit** your changes
   ```bash
   git commit -m "Add: Your feature description"
   ```
6. **Push** to your fork
   ```bash
   git push origin feature/YourFeatureName
   ```
7. **Create a Pull Request** from your fork to the main repository

### Contribution Guidelines
- Follow the existing code style and conventions
- Add comments for complex logic
- Test your changes before submitting
- Update documentation if needed
- Write clear commit messages

### Areas for Contribution
- 🐛 Bug fixes
- ✨ New features
- 📝 Documentation improvements
- 🎨 UI/UX enhancements
- ⚡ Performance optimizations
- 🧪 Test coverage

---

## 👨‍🍳 Authors

**Muhammad Usama**
- Student ID: SP23_BCS_021
- Role: Lead Developer
- GitHub: [@Muhammad-Usama294](https://github.com/Muhammad-Usama294)

---

## 📄 License

This project is licensed under the **MIT License** - see below for details.

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

---

## 🙏 Acknowledgments

- Thanks to all contributors and users of Recipe_Fusion
- Special thanks to the C++ community for excellent resources
- Inspiration from various recipe management systems

---

<div align="center">

**Made with ❤️ and C++**

⭐ Star this repository if you find it helpful!

[Report Bug](https://github.com/Muhammad-Usama294/Recipe_Fusion/issues) · [Request Feature](https://github.com/Muhammad-Usama294/Recipe_Fusion/issues)

</div>
