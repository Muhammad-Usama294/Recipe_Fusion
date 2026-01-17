# 🍳 Recipe_Fusion - Recipe Management System

[![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Data Structures](https://img.shields.io/badge/Data_Structures-Graph-orange?style=for-the-badge)](https://github.com/Muhammad-Usama294/Recipe_Fusion)
[![Console Application](https://img.shields.io/badge/Console-Application-green?style=for-the-badge)](https://github.com/Muhammad-Usama294/Recipe_Fusion)

A comprehensive **C++ console-based Recipe Management System** that leverages **Graph data structures** for efficient recipe and ingredient management. This project is part of a Data Structures and Algorithms (DSA) course, demonstrating practical applications of graph algorithms in real-world scenarios.

---

## 📋 Table of Contents

- [Features](#-features)
- [Data Structures](#-data-structures)
- [Technologies Used](#-technologies-used)
- [File Structure](#-file-structure)
- [How to Build and Run](#-how-to-build-and-run)
- [Usage Guide](#-usage-guide)
- [Data File Format](#-data-file-format)
- [Graph Algorithm Features](#-graph-algorithm-features)
- [Future Enhancements](#-future-enhancements)
- [Authors](#-authors)
- [License](#-license)

---

## ✨ Features

### 👨‍💼 Admin System

The admin system provides comprehensive management capabilities for the Recipe_Fusion platform:

- **🔐 Admin Authentication**: Secure login system for administrators
- **➕ Add New Recipes**: Create recipes with multiple ingredients and detailed cooking steps
- **🗑️ Delete Recipes**: Remove recipes from the system
- **👀 View All Recipes**: Browse complete recipe catalog with details
- **👤 Admin Management**: Manager can add/remove additional admins
- **📝 Transaction Logging**: All admin actions are logged in `AdminsTransactions.txt` for audit purposes
- **🔧 Ingredient Management**: 
  - Add new ingredients to the database
  - Edit ingredient information
  - Delete ingredients
  - Search for specific ingredients

### 👥 User System

Users can explore and discover recipes through various features:

- **📖 Browse Recipes**: View complete list of available recipes
- **🔍 Search by Ingredients**: Find recipes based on available ingredients
- **📄 View Recipe Details**: See complete recipe information including ingredients and cooking steps
- **🥗 Find Common Ingredients**: Discover recipes that share ingredients
- **👤 User Profile Management**: Edit user information
- **📊 Search History**: Track recipe searches for better recommendations

### 🕸️ Graph-Based Architecture

The system uses graph data structures to model relationships:

- **📍 Recipes as Nodes**: Each recipe represents a node in the graph
- **🔗 Ingredients as Edges**: Shared ingredients create connections between recipes
- **⚡ Efficient Relationship Tracking**: Quick lookup of related recipes
- **🎯 Recipe Recommendations**: Suggest similar recipes based on ingredient overlap

---

## 🗂️ Data Structures

### Graph Structure

Recipe_Fusion implements a **graph-based approach** to manage recipes and ingredients:

- **Graph Representation**: The system conceptually models recipes and ingredients as a graph where:
  - **Vertices (Nodes)**: Represent individual recipes
  - **Edges (Connections)**: Represent shared ingredients between recipes
  - **Weight**: Can be determined by the number of common ingredients

- **Adjacency Relationships**: 
  - Recipes with common ingredients are considered adjacent in the graph
  - This enables efficient discovery of similar recipes
  - Supports ingredient-based search and recommendations

- **Data Storage**:
  - Uses **vector-based storage** for recipes and ingredients
  - File I/O operations for persistent data storage
  - Transaction logs maintain system integrity

### Additional Data Structures

- **Vectors**: Used for storing collections of recipes, ingredients, and cooking steps
- **Classes and Objects**: OOP principles with inheritance (Person → Admin/User)
- **File Handling**: Binary and text file operations for data persistence

---

## 🛠️ Technologies Used

- **Language**: C++ (Standard C++11 and above)
- **Data Structure**: Graph-based architecture with Adjacency concepts
- **File I/O**: Binary and text file operations for data persistence
- **Console Interface**: Windows console API for enhanced UI (`<windows.h>`, `<conio.h>`)
- **Standard Libraries**:
  - `<iostream>` - Input/Output operations
  - `<vector>` - Dynamic array management
  - `<fstream>` - File handling
  - `<sstream>` - String stream operations
  - `<iomanip>` - Output formatting

---

## 📁 File Structure

```
Recipe_Fusion/
│
├── Final Recipie Generator dev.cpp    # Main source code file
├── Final Recipie Generator dev.exe    # Compiled executable
│
├── Admins.txt                         # Admin credentials database
├── Users.txt                          # User credentials database
├── Recipes.txt                        # Recipe data storage
├── Ingredients.txt                    # Ingredient database
├── AdminsTransactions.txt             # Admin action logs
│
└── README.md                          # Project documentation
```

### File Descriptions

- **Final Recipie Generator dev.cpp**: Contains all classes, functions, and main program logic
- **Admins.txt**: Stores admin credentials (ID, name, password)
- **Users.txt**: Stores user credentials
- **Recipes.txt**: Stores recipe information including ingredients and cooking steps
- **Ingredients.txt**: Database of all available ingredients with categories and nutritional info
- **AdminsTransactions.txt**: Logs all admin operations for tracking and auditing

---

## 🚀 How to Build and Run

### Prerequisites

- C++ compiler (GCC, MinGW, or MSVC)
- Windows operating system (for Windows-specific console functions)

### Compilation

Using **g++** (MinGW or GCC):

```bash
g++ "Final Recipie Generator dev.cpp" -o RecipeFusion
```

Using **MSVC** (Visual Studio):

```bash
cl "Final Recipie Generator dev.cpp" /Fe:RecipeFusion.exe
```

### Running the Application

```bash
./RecipeFusion
```

Or on Windows:

```bash
RecipeFusion.exe
```

### First Run

On the first run, the system will prompt you to create a **Manager Admin** account. This account has special privileges to add/remove other admins.

---

## 📖 Usage Guide

### 🔑 Getting Started

1. **Launch the Application**: Run the executable file
2. **Choose User Type**: 
   - Select `1` for Admin Login
   - Select `2` for User Login/Registration
   - Select `3` to Exit

### 👨‍💼 Admin Features

**Login as Admin:**
1. Enter Admin ID
2. Enter Password
3. Access Admin Dashboard

**Admin Menu Options:**

1. **Ingredients Management**
   - View ingredients list
   - Search for ingredients
   - Add new ingredients (name, category, nutritional info)
   - Delete ingredients
   - Edit ingredient information

2. **Recipe Management**
   - View all recipes
   - Search recipes by name
   - Add new recipe with ingredients and cooking steps
   - Delete existing recipes

3. **Edit Profile**: Update admin information
4. **Add New Admin**: Manager can add more administrators
5. **Remove Admin**: Manager can remove administrators
6. **Logout**: Exit admin session

**Adding a Recipe:**
1. Enter recipe name
2. Add ingredients one by one with quantities
3. Add cooking steps sequentially
4. Recipe is saved and logged in transactions

### 👥 User Features

**Register/Login as User:**
1. Choose "Login as User"
2. Enter User ID and Password (or register new account)
3. Access User Dashboard

**User Menu Options:**

1. **Search Recipe by Ingredients**
   - Enter available ingredients
   - System finds matching recipes
   - View recipes that can be made with your ingredients

2. **Search Recipe by Name**
   - Search for a specific recipe
   - View complete recipe details
   - See ingredients and cooking steps

3. **Edit Profile**: Update user information
4. **Logout**: Exit user session

---

## 📊 Data File Format

### Recipes.txt Format

The recipe file stores data in the following sequence:
```
[Number of Ingredients]
[Ingredient Name],[Quantity]
...
[Number of Cooking Steps]
[Step 1]
[Step 2]
...
```

**Example:**
```
Chicken Biryani
9
Chicken,500g pieces
Basmati Rice,2 cups, soaked
Yogurt,1/2 cup
...
7
Heat ghee/oil in a pan, add sliced onions...
Add garlic, ginger, green chilies...
...
```

### Ingredients.txt Format

Binary storage of ingredient objects containing:
- Ingredient Name (40 characters)
- Category (20 characters)
- Nutritional Information (60 characters)

### AdminsTransactions.txt Format

Text-based log format:
```
Admin : [Name] ID : [ID] added Recipe of [RecipeName]
```

---

## 🧮 Graph Algorithm Features

The Recipe_Fusion system leverages graph concepts for enhanced functionality:

### 🔍 Finding Recipes with Common Ingredients

- **Algorithm**: Graph traversal to identify recipes sharing ingredients
- **Use Case**: Discover related recipes based on ingredient overlap
- **Benefit**: Users can explore similar dishes

### 🎯 Recipe Recommendation

- **Concept**: Recipes connected by shared ingredients form a recommendation graph
- **Implementation**: When a user searches for ingredients, the system finds recipes with the most matches
- **Graph Property**: Higher edge weight (more common ingredients) = stronger recommendation

### 🗺️ Recipe Discovery

- **Traversal**: Browse through recipe networks based on ingredient relationships
- **Exploration**: Find new recipes by exploring neighboring nodes (recipes with similar ingredients)

### 💡 Conceptual Graph Model

```
[Recipe A] ---(Chicken)--- [Recipe B]
     |                          |
  (Rice)                    (Tomatoes)
     |                          |
[Recipe C] --(Rice+Tomatoes)-- [Recipe D]
```

This graph structure enables:
- Quick ingredient-based searches
- Recipe similarity calculations
- Efficient relationship queries
- Scalable recipe database management

---

## 🚀 Future Enhancements

### Planned Features

- 🥗 **Nutritional Information Integration**: Automatic calculation of total nutrition per recipe
- ⭐ **Recipe Rating System**: Allow users to rate and review recipes
- ⏱️ **Cooking Time Optimization**: Add preparation and cooking time estimates
- 🔄 **Ingredient Substitution**: Suggest alternative ingredients for dietary restrictions
- 📱 **Mobile/Web Interface**: Develop a GUI version with cross-platform support
- 🌐 **Online Sync**: Cloud-based recipe sharing and synchronization
- 🎨 **Advanced Search Filters**: Filter by cuisine, difficulty, cooking time, dietary preferences
- 📸 **Recipe Images**: Add image support for visual recipe display
- 🗣️ **Multi-language Support**: Internationalization for global users
- 🤖 **AI Recommendations**: Machine learning-based recipe suggestions

### Technical Improvements

- 🔐 **Enhanced Security**: Password encryption and secure authentication
- 💾 **Database Integration**: Migration to SQL database for better scalability
- 🎯 **Optimized Graph Algorithms**: Implement advanced graph algorithms (Dijkstra's, DFS, BFS)
- 📊 **Analytics Dashboard**: Admin analytics for popular recipes and user behavior
- 🧪 **Unit Testing**: Comprehensive test suite for reliability

---

## 👨‍🍳 Authors

**Muhammad Usama**  
Roll No: SP23_BCS_021  
Data Structures & Algorithms Project

---

## 📄 License

This project is licensed under the **MIT License** - see the [LICENSE](#license-details) section below for details.

### License Details

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

## 🤝 Contributing

Contributions, issues, and feature requests are welcome! Feel free to check the [issues page](https://github.com/Muhammad-Usama294/Recipe_Fusion/issues).

---

## 📞 Contact

For any queries or suggestions, please feel free to reach out:

- **GitHub**: [@Muhammad-Usama294](https://github.com/Muhammad-Usama294)
- **Project Link**: [Recipe_Fusion](https://github.com/Muhammad-Usama294/Recipe_Fusion)

---

<div align="center">

### ⭐ Star this repository if you find it helpful!

**Made with ❤️ and C++**

</div>
