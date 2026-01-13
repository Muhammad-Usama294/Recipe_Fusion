# 🍳 Recipe_Fusion - Recipe Management System

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Data Structure](https://img.shields.io/badge/Data_Structure-Graph-orange?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Active-success?style=for-the-badge)

## 📖 Overview

**Recipe_Fusion** is a sophisticated C++ application designed for managing recipes with distinct admin and user roles. The system leverages advanced data structures to efficiently store, search, and recommend recipes based on available ingredients. Built with Object-Oriented Programming principles, it provides a robust solution for recipe discovery and management.

The application uses Graph-like data structures where recipes are interconnected through shared ingredients, enabling intelligent recipe recommendations and efficient searches.

## ✨ Features

### 👨‍🍳 Admin Features

- **Add New Recipes**: Create comprehensive recipes with ingredients and cooking steps
- **Delete Existing Recipes**: Remove recipes from the database
- **View All Recipes**: Browse complete recipe collection with details
- **Manage Ingredients**: Add, edit, delete, and search ingredients database
- **Manage Recipe Instructions**: Add step-by-step cooking instructions
- **Transaction Logging**: All admin activities are logged to `AdminsTransactions.txt`
- **Admin Management**: Add or remove other administrators
- **Profile Management**: Edit admin profile information

### 🥗 User Features

- **Browse Recipes**: View available recipes in the database
- **Search by Ingredients**: Find recipes based on ingredients you have (minimum 3 ingredients)
- **Search by Name**: Quickly find specific recipes by their name
- **View Recipe Details**: See complete ingredient lists with quantities and cooking instructions
- **User Authentication**: Secure login system for personalized experience
- **Recipe Recommendations**: Get multiple recipe suggestions matching your ingredients

## 🔧 Data Structures

### Recipe Graph Implementation

The system implements a Graph-like structure for recipe relationships:

- **Nodes (Recipes)**: Each recipe acts as a node in the graph
- **Edges (Ingredient Relationships)**: Recipes are connected through shared ingredients
- **Search Algorithm**: The ingredient-based search traverses the recipe network by matching user ingredients with recipe ingredients
- **Minimum Match Threshold**: Recipes must match at least 3 ingredients to be recommended
- **Efficient Discovery**: The structure enables quick recipe recommendations based on ingredient availability

### Core Data Structures

- **Vectors**: Dynamic arrays for storing recipes, ingredients, users, and admins
- **Object-Oriented Design**: Classes for Person (base), Admin, User, Recipe, Ingredient, and IngredientUsage
- **File I/O**: Persistent storage using binary and text file formats

## 💻 Technologies Used

- **Language**: C++ (C++11 or higher)
- **Data Structure**: Graph-like structure with Adjacency relationships through shared ingredients
- **File I/O**: Binary and text file operations for data persistence
- **OOP Principles**: Inheritance, polymorphism, encapsulation
- **Libraries**: 
  - `<iostream>` - Input/output operations
  - `<vector>` - Dynamic arrays
  - `<fstream>` - File handling
  - `<windows.h>` - Console operations (Windows-specific)
  - `<conio.h>` - Console I/O
  - `<iomanip>` - Output formatting

## 📁 File Structure

```
Recipe_Fusion/
├── Final Recipe Generator dev.cpp     # Main application source code
├── Admins.txt                         # Admin account information (binary)
├── Users.txt                          # User account information (binary)
├── Recipes.txt                        # Recipe database (text format)
├── Ingredients.txt                    # Ingredients database (binary)
├── AdminsTransactions.txt             # Admin activity logs
└── README.md                          # Project documentation
```

### Data Files Description

- **`Final Recipe Generator dev.cpp`**: Main source code containing all classes and functions
- **`AdminsTransactions.txt`**: Logs all admin activities (recipe additions, deletions)
- **`Recipes.txt`**: Stores recipe data including name, ingredients, and cooking steps
- **`Ingredients.txt`**: Database of all ingredients with nutritional information
- **`Admins.txt`**: Encrypted admin credentials and profiles
- **`Users.txt`**: User account information

## 🏗️ System Architecture

```
Recipe_Fusion/
│
├── 👨‍💼 Admin Module
│   ├── Add Recipe
│   ├── Delete Recipe
│   ├── Manage Ingredients
│   │   ├── Add Ingredient
│   │   ├── Edit Ingredient
│   │   ├── Delete Ingredient
│   │   └── Search Ingredient
│   ├── Admin Management
│   │   ├── Add Admin
│   │   └── Remove Admin
│   ├── Profile Management
│   └── Transaction Logging
│
├── 👤 User Module
│   ├── Browse Recipes
│   ├── Search by Ingredients
│   ├── Search by Name
│   ├── View Recipe Details
│   └── User Authentication
│
└── 💾 Data Layer
    ├── Recipe Storage
    ├── Ingredient Database
    ├── User Management
    ├── Admin Management
    └── File Persistence
```

## 🚀 How to Build and Run

### Prerequisites

- C++ compiler (g++, MinGW, MSVC, or similar)
- Windows OS (due to `windows.h` dependency)

### Compilation

#### Using g++ (MinGW on Windows)

```bash
g++ "Final Recipe Generator dev.cpp" -o RecipeFusion
./RecipeFusion
```

#### Using Visual Studio

1. Open Visual Studio
2. Create a new C++ Console Application project
3. Add `Final Recipe Generator dev.cpp` to the project
4. Build and run (F5)

#### Using Code::Blocks

1. Create new Console Application project
2. Add source file
3. Build and Run (F9)

### First Run

On the first run, the system will prompt you to create an administrator account. This is required before you can access any features.

## 📚 Usage Guide

### Admin Login

1. Select option `1` (Enter as Admin) from the main menu
2. Enter your Admin ID and password
3. Access the Admin Menu with the following options:
   - Ingredients Menu
   - Recipes Menu
   - Edit Profile
   - Add/Remove Admin
   - Logout

### Adding a Recipe (Admin)

1. Login as Admin
2. Select `Recipes Menu` → `Add Recipe`
3. Enter recipe name
4. Add ingredients one by one:
   - Enter ingredient name
   - If ingredient doesn't exist, provide category and nutritional info
   - Specify quantity (e.g., "500g", "1kg", "2 cups")
   - Continue adding or type "END" when done
5. Add cooking steps:
   - Enter step-by-step instructions
   - Type "END" when finished
6. Recipe is saved automatically

### User Mode

1. Select option `2` (Enter as User) from the main menu
2. For first-time users, create an account
3. Login with your credentials
4. Access User Menu:
   - View all recipes
   - Search recipe by ingredients
   - Search recipe by name

### Searching Recipes by Ingredients

1. Login as User
2. Select "Search by Ingredients"
3. Enter at least 3 ingredients you have available
4. System will recommend all recipes matching 3+ ingredients
5. View detailed recipe information

## 📄 Data File Format

### AdminsTransactions.txt Format

```
Admin : Usama ID : 100 added Recipe of Chicken Biryani
Admin : Aroona ID : 101 added Recipe of Gajar Ka Halwa
```

### Recipes.txt Format

```
[Recipe Count]
[Recipe Name]
[Ingredient Count]
[Ingredient Name],[Quantity]
...
[Cooking Steps Count]
[Step 1]
[Step 2]
...
```

### Example Recipe Entry

```
Chicken Biryani
9
Chicken,500g pieces
Basmati Rice,2 cups, soaked
Yogurt,1/2 cup
Onions,2 , thinly sliced
Tomatoes,2, chopped
Garlic,4 cloves, minced
Ginger,1 inch, grated
Salt,to taste
Ghee,for cooking
7
Heat ghee/oil in a pan, add sliced onions and fry until golden brown...
Add garlic, ginger, green chilies, and tomatoes to the pan...
...
```

## 💡 Example Usage

### Sample Admin Transaction

```
Admin : Usama ID : 100 added Recipe of Test
```

### Sample Recipe Search

**Input**: Rice, Chicken, Salt

**Output**: 
- Chicken Biryani
- Daal Chawal
- Test Multiple

## 🔮 Future Enhancements

- 🔍 **Advanced Recipe Recommendations**: Implement machine learning for personalized suggestions
- 📊 **Nutritional Information**: Calculate total nutritional values per recipe
- ⭐ **Recipe Ratings and Reviews**: Allow users to rate and review recipes
- 🖼️ **Image Support**: Add photo upload functionality for recipes
- 📑 **PDF Export**: Export recipes to PDF format
- 🌐 **Web Interface**: Develop a web-based frontend
- 📱 **Mobile Application**: Create iOS and Android apps
- 🔗 **Social Sharing**: Share recipes on social media
- 🛒 **Shopping List**: Generate shopping lists from selected recipes
- ⏲️ **Cooking Timer**: Built-in timer for cooking steps
- 🌍 **Multi-language Support**: Internationalization
- ☁️ **Cloud Sync**: Synchronize data across devices

## 🤝 Contributing

Contributions are welcome! Here's how you can help:

1. **Fork the repository**
2. **Create a feature branch**
   ```bash
   git checkout -b feature/AmazingFeature
   ```
3. **Commit your changes**
   ```bash
   git commit -m 'Add some AmazingFeature'
   ```
4. **Push to the branch**
   ```bash
   git push origin feature/AmazingFeature
   ```
5. **Open a Pull Request**

### Contribution Guidelines

- Follow the existing code style
- Add comments for complex logic
- Test your changes thoroughly
- Update documentation as needed
- Write meaningful commit messages

## 👥 Authors

- **Muhammad Usama** - Initial development and implementation
- **Contributors** - See the [contributors](https://github.com/Muhammad-Usama294/Recipe_Fusion/contributors) page for full list

## 📜 License

This project is licensed under the MIT License - see below for details:

```
MIT License

Copyright (c) 2024 Recipe_Fusion Team

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

<div align="center">

**Made with ❤️ by the Recipe_Fusion Team**

⭐ **Star this repository if you find it helpful!** ⭐

[Report Bug](https://github.com/Muhammad-Usama294/Recipe_Fusion/issues) · [Request Feature](https://github.com/Muhammad-Usama294/Recipe_Fusion/issues)

</div>
