#include<iostream>
#include<vector>
#include <sstream> 
#include <windows.h>
#include<fstream>
#include<conio.h>
#include<limits>
#include<iomanip>

using namespace std;

const int INFORMATION_SIZE = 60;
const int NAME_SIZE = 40;
const int STRINGS_SIZE = 20;
const string ADMIN_FILE = "Admins.txt";
const string USERS_FILE = "Users.txt";
const string INGREDIENTS_FILE = "Ingredients.txt";
const string RECIPES_FILE = "Recipes.txt"; 
const string ADMINS_TRANSACTIONS_FILE = "AdminsTransactions.txt"; 
const string USERS_TRANSACTIONS_FILE = "UsersTransactions.txt"; 

//--------------------------------------------------------------------------------------------------
//							Prototypes of Frequently Used Basic Functions
	void displayTitle();
	void clearScreen();
	void pressKey();
	void displayInterface();
	bool invalidIntegerInputCheck(int);
	char* invalidCharCheck(char* s);

//--------------------------------------------------------------------------------------------------
//								Classes
//--------------------------------------------------------------------------------------------------						

//								Parent Class person

class Person
{
	protected:
	    char name[NAME_SIZE];
	    char password[STRINGS_SIZE];
	    int ID;
	
	public:
		Person()	{}
		//constructor
		Person(int id,const char* nm,const char* pw) 
		{
			ID=id;
			
			strncpy(name, nm, NAME_SIZE - 1);
			name [NAME_SIZE - 1] = '\0';
			
			strncpy(password, pw, STRINGS_SIZE - 1);
			password [STRINGS_SIZE - 1] = '\0';
		}
		
		//getter & setter
		
		virtual void setID (int id)		{ID=id;}
		virtual int getID ()	const 		{return ID;}
		
		virtual	void setName(const char* nm)
		{
			strncpy(name, nm, NAME_SIZE - 1);
			name [NAME_SIZE - 1] = '\0';
		}
		virtual const char* getName()	const 		{return name;}
		
		virtual	void setPassword(const char* pw)
		{
			strncpy(password, pw, STRINGS_SIZE - 1);
			name [STRINGS_SIZE - 1] = '\0';
		}
		virtual const char* getPassword()	const 		{return password;}
		
		//pure virtual function
		
		virtual void displayInfo() = 0 ;		
		~Person() {	}
	
};
//--------------------------------------------------------------------------------------------------
//								Child class user

class User : public Person
{
	//string name; ->inherit from person
    //string password; ->inherit from person
	public:
		User() {}
		//constructor
		User(int id, char* nm, char* pw): Person(id,nm, pw) {}
		
		//getter & setter
		
		void setID(int id)	{Person::setID(id);}
		int getID()			{return Person::getID();}
		
		void setName(char* nm)		{Person::setName(nm);}
		const char* getName()			{return Person::getName();}
		
		void setPassword(char* pw)		{Person::setPassword(pw);}
		const char* getPassword()	        {return Person::getPassword();}
		
		void displayInfo()
		{
			cout << name <<"\t\t\t" << "ID: " << ID;
		}
		
		~User(){}
		
		 
};
//--------------------------------------------------------------------------------------------------
//								Child class Admin

class Admin : public Person
{
	//string name; ->inherit from person
    //string password; ->inherit from person
    public:
    	Admin()	{}
    	//constructor
		Admin(int id, char* nm, char* pw): Person(id,nm, pw) {}
    	
        //getter & setter
        
        void setID(int id)	override	{Person::setID(id);}
		int getID()	const 	override		{return Person::getID();}
		
        void setName(const char* nm)	override		{Person::setName(nm);}
	    const char* getName() const 		override		{return Person::getName();}
		
	    void setPassword(const char* pw)	override		{Person::setPassword(pw);}
	    const char* getPassword()	 const 	override       {return Person::getPassword();}
	    
	    void displayInfo()
		{
			cout<<name<<"\t\t\t" << "ID: " <<ID;
		}
	    
	    ~Admin() {}
	    
    
};

//--------------------------------------------------------------------------------------------------
//								Class Ingredient

class Ingredient
{
	private:
	   char name[NAME_SIZE] ;
	   char category[STRINGS_SIZE] ;
	   char nutritonalInformation[INFORMATION_SIZE] ;
	
	public:
		//constructor
		Ingredient(const char* nm, const char* ctg, const char* ni)
		{
			strncpy(name, nm, NAME_SIZE - 1);
			name [sizeof(name) - 1] = '\0';
			
			strncpy(category, ctg, STRINGS_SIZE - 1);
			category [sizeof(category) - 1] = '\0';
			
			strncpy(nutritonalInformation, ni, INFORMATION_SIZE - 1);
			nutritonalInformation [sizeof(nutritonalInformation) - 1] = '\0';
		} 
		
		//default constructor
		Ingredient()  {}
		
		//getter & setter
		void setName(const char* nm)
		{
			strncpy(name, nm, NAME_SIZE - 1);
			name [sizeof(name) - 1] = '\0';
		}
		const char* getName() const			{return name;}
		
		void setCategory(const char* ctg)	
		{
			strncpy(category, ctg, STRINGS_SIZE - 1);
			name [sizeof(category) - 1] = '\0';
		}
		const char* getCategory() const				{return category;}
		
		void setNutriotnalInformation(const char* ni)
		{
			strncpy(nutritonalInformation, ni, INFORMATION_SIZE - 1);
			name [sizeof(nutritonalInformation) - 1] = '\0';
		}
		const char* getNutritionalInformation()	const			{return nutritonalInformation;}
		
		~Ingredient() {}
		
};

//--------------------------------------------------------------------------------------------------
//				Class Ingredient Usage to implelment an ingredient's usage in Recipe

class IngredientUsage
{
	private:
		Ingredient* ingredient;  // Pointer to the ingredient object
  		char quantity[NAME_SIZE];          // Quantity used in that recipe
  	public:
  		//constructor
  		IngredientUsage(Ingredient* ingr , const char* q) : ingredient(ingr)
  		{
			strncpy(quantity, q, NAME_SIZE - 1);
			quantity[sizeof(quantity) - 1] = '\0';
			
		}
  		
  		//default constructor
  		IngredientUsage() {}
  		
  		//getter & setter
  		void setQuantity(const char* q)
  		{
  			strncpy(quantity, q, NAME_SIZE - 1);
			quantity[sizeof(quantity) - 1] = '\0';
		}
		const char* getQuantity()	const		{return quantity;}
		
		void setIngredient(Ingredient* ingr) { ingredient = ingr; }
    	Ingredient* getIngredient() const  { return ingredient; }
    	
    	~IngredientUsage(){}
};

//--------------------------------------------------------------------------------------------------
//								Class Recipe

class Recipe
{
	private:
	    char name[NAME_SIZE] ;
	    vector <IngredientUsage> recipeIngredients;
	    vector <string> cookingSteps;
	
	public:
		//default constructor
		Recipe() {}
		//constructor
		Recipe(char* nm )
		{
			strncpy(name, nm, NAME_SIZE - 1);
			name [sizeof(name) - 1] = '\0';
		}
		//	getter/setters
		void setName(const char* nm)
		{
			strncpy(name, nm, NAME_SIZE - 1);
			name [sizeof(name) - 1] = '\0';
		}
		const char* getName() const			{return name;}
		
		void addIngredientUsage(IngredientUsage usage)
        {
            recipeIngredients.push_back(usage);
        }
        //getter of ingredients
        vector<IngredientUsage> getIngredients() const {return recipeIngredients;}
        //getter of cookingsteps
        vector<string> getCookingSteps() const {return cookingSteps;}
        
        void addCookingStep(string step)
        {
            cookingSteps.push_back(step);
        }
        
        ~Recipe() {}
		
};

//--------------------------------------------------------------------------------------------------
//				Classes Ingredients Database... has a vector of ingredient and contain all
//				ingredeints realated functionality (add ,del, modify)

class IngredientsDatabase
{
	private:
		
	    vector <Ingredient> ingredients;
	    
	public:
		
		vector <Ingredient> getIngredients()	{ return ingredients;}
		
//			----------------------------------------------------------------------------------
//						Declaration of functions of Ingredient Datbase Class
		
//		Function to add Ingredient
		void addIngredient();
		
//		Function to  Delete Ingredeint 
		void deleteIngredient();
		
//		Function to edit an ingredient
		void editIngredient();
		
//		Function to Search an Ingredient
		void searchIngredient();
		
//		Functions to Dipaly Ingredients list
		void printIngredientsList();
		
		void displayIngredientsList()
		{
			printIngredientsList();
			pressKey(); clearScreen();
		}
		
//		Function to find and return if ingredient is already in Database
		Ingredient* findIngredient(char* name);
		
		
//     	     ------------------------------------------------------------------------------------
//						Declaration of file Handling functions of Ingredient Datbase Class	

	
		void writeIngredientToFile(Ingredient &tmpIngredient);
		
		void readIngredientsFromFile();
		
		~IngredientsDatabase() {}
};

//--------------------------------------------------------------------------------------------------
//						Definition of functions of Ingredient Datbase Class

void IngredientsDatabase:: addIngredient() 
{
	int nameCheck = 0 ;
	char name[NAME_SIZE];
	char category[STRINGS_SIZE];
	char nutritionalInfo[INFORMATION_SIZE];
	cout<<"\nEnter Name of the Ingredient : ";
	cin.getline(name,NAME_SIZE); 
	invalidCharCheck(name);
	for(Ingredient & ing : ingredients)
	{
		if(strcmp(ing.getName(), name)==0)	nameCheck++;
	}
	if(nameCheck==0)
	{
		cout<<"\nEnter Category of the Ingredient (e.g meats, vegetables) : ";
		cin.getline(category,STRINGS_SIZE);
		invalidCharCheck(category);
		cout<<"\nEnter Nutritional Information of the Ingredient : ";
		cin.getline(nutritionalInfo,INFORMATION_SIZE);
		Ingredient ingredient(name, category, nutritionalInfo);
		writeIngredientToFile(ingredient);
		ingredients.push_back(ingredient);
		cout<<"\nIngredient Added Sucessfully";
		pressKey(); clearScreen();
	}
	else{cout<<"\nIngredient has already been added in the database\n"; pressKey(); clearScreen();}
}

void IngredientsDatabase:: deleteIngredient()
{
	if(ingredients.size() == 0)
	{
		cout<<"\nNo Ingredients in Database";
		pressKey();clearScreen();
		return;
	}
	printIngredientsList();
	int namechk=0;
	char name[NAME_SIZE];
	cout<<"\nEnter name of the ingredient You want to delete : ";
	cin.getline(name, NAME_SIZE);
	invalidCharCheck(name);
	for(int i=0; i<ingredients.size(); i++)
	{
		if(strcmp(ingredients[i].getName(),name)==0)
		{
			ingredients.erase(ingredients.begin()+i);
			cout<<"\nIngredient Deleted ";
			namechk++;
			pressKey(); clearScreen();
			break;
		}
	}
	if(namechk==0) {cout<<"\nThere's no ingredient named "<<name; pressKey(); clearScreen();}
	else
	{
		fstream ingredientFileHandler(INGREDIENTS_FILE, ios::in |ios::out |ios::binary|ios::trunc);
		ingredientFileHandler.write(reinterpret_cast<char*>(ingredients.data()),ingredients.size()* sizeof(Ingredient));
		ingredientFileHandler.close();
	}
}

void IngredientsDatabase:: editIngredient()
{
	if(ingredients.size() == 0)
	{
		cout<<"\nNo Ingredients in Database";
		pressKey();clearScreen();
		return;
	}
	fstream ingredientFileHandler(INGREDIENTS_FILE, ios::in |ios::out |ios::binary);
	printIngredientsList();
	int namechk=0;
	char name[NAME_SIZE];
	cout<<"\nEnter name of the ingredient You want to edit : ";
	cin.getline(name, NAME_SIZE);
	invalidCharCheck(name);
	while(!ingredientFileHandler.eof())
	{
		Ingredient ingredient; 
		ingredientFileHandler.read(reinterpret_cast<char*>(&ingredient), sizeof(Ingredient));
		if(strcmp(ingredient.getName(),name)==0)
		{
			char category[STRINGS_SIZE];
			char nutritionalInfo[INFORMATION_SIZE];
			cout<<"\nEnter New Name : ";
			cin.getline(name, NAME_SIZE);
			invalidCharCheck(name);
			ingredient.setName(name);
			cout<<"\nEnter New Category : ";
			cin.getline(category,STRINGS_SIZE);
			invalidCharCheck(category);
			ingredient.setCategory(category);
			cout<<"\nEnter New Nutritional Information : ";
			cin.getline(nutritionalInfo,INFORMATION_SIZE);
			ingredient.setNutriotnalInformation(nutritionalInfo);
			ingredientFileHandler.seekp(-sizeof(Ingredient), ios::cur);
			ingredientFileHandler.write(reinterpret_cast<char*>(&ingredient), sizeof(Ingredient));
			ingredientFileHandler.close();
			namechk++;
			pressKey(); clearScreen();
			ingredients.clear();
			readIngredientsFromFile();
			cout<<"\nIngredient Updated Successfully ";
			break;
		}
	}
	if(namechk==0) {cout<<"\nThere's no ingredient named "<<name; pressKey(); clearScreen();}
}

void IngredientsDatabase:: searchIngredient()
{
	if(ingredients.size() == 0)
	{
		cout<<"\nNo Ingredients in Database";
		pressKey();clearScreen();
		return;
	}
	int chkName= 0;
	char ingName[NAME_SIZE];
	cout<<"\nEnter the Name of the Ingredient you want to Search : ";
	cin.getline(ingName, NAME_SIZE);
	invalidCharCheck(ingName);
	for(Ingredient & ing : ingredients)
	{
		if(strcmp(ingName, ing.getName())==0)
		{
			chkName++;
			cout<<"\t"<<left<<setw(30)<<"Name"<<setw(30)<<"Category"<<setw(40)<<"Nutritional Information (Per 100g)"<<endl;
			cout<<"\t"<<left<<setw(30)<<"----"<<setw(30)<<"--------"<<setw(40)<<"----------------------------------"<<endl;
			cout<<"\t"<<left<<setw(30)<<ing.getName()<<setw(30)<<ing.getCategory()
			 <<setw(40)<<ing.getNutritionalInformation()<<endl;
			break;
		}
	}
	if(chkName==0) {cout<<"\nThere's no Ingredient Name"<< ingName; pressKey(); clearScreen();}
	pressKey(); clearScreen();
}

void IngredientsDatabase:: printIngredientsList()
{
	if(ingredients.size() == 0)
	{
		cout<<"\nNo Ingredients in Database";
		return;
	}
	clearScreen();
	cout<<"\t"<<left<<setw(30)<<"Name"<<setw(30)<<"Category"<<setw(40)<<"Nutritional Information (Per 100g)"<<endl;
	cout<<"\t"<<left<<setw(30)<<"----"<<setw(30)<<"--------"<<setw(40)<<"----------------------------------"<<endl;

	for(int i=0; i<ingredients.size(); i++)
	{
		cout<<"\t"<<left<<setw(30)<<ingredients[i].getName()<<setw(30)<<ingredients[i].getCategory()
		<<setw(40)<<ingredients[i].getNutritionalInformation()<<endl;
	}
}

Ingredient* IngredientsDatabase:: findIngredient(char* name)
{
	readIngredientsFromFile();
    for (int i=0; i<ingredients.size(); i++)
    {
        if (strncmp(ingredients[i].getName(), name, NAME_SIZE) == 0)
        {
            return &ingredients[i];
			break;		 // Return existing ingredient if found
        }
    }
    return nullptr;
}

//--------------------------------------------------------------------------------------------------
//						Definition of file Handling functions of Ingredient Datbase Class

void IngredientsDatabase:: writeIngredientToFile(Ingredient &tmpIngredient)
{
	fstream ingredientFileHandler(INGREDIENTS_FILE, ios::in |ios::app |ios::binary);
	if(!ingredientFileHandler.is_open())
	{
		cout<<"\nIngredient file wasn't opened";
		return;
	}
	ingredientFileHandler.write(reinterpret_cast<char*>(&tmpIngredient),sizeof(Ingredient));
	ingredientFileHandler.close();
}

void IngredientsDatabase:: readIngredientsFromFile()
{
	fstream ingredientFileHandler(INGREDIENTS_FILE, ios::out |ios::in |ios::binary);
	if(!ingredientFileHandler.is_open())
	{
		cout<<"\nIngredients file wasn't opened";
		return;
	}
	ingredients.clear();
	while(!ingredientFileHandler.eof())
	{
		Ingredient ingredient; 
		ingredientFileHandler.read(reinterpret_cast<char*>(&ingredient), sizeof(Ingredient));
		ingredients.push_back(ingredient);
	}
	ingredients.pop_back();
	ingredientFileHandler.close();
}


//--------------------------------------------------------------------------------------------------
//				Main Class Recipe Generator...... 
//--------------------------------------------------------------------------------------------------


class RecipeGenerator
{
	vector <User> users;
	vector <Recipe> recipes;
	vector <Admin> admins;
	IngredientsDatabase myIG;
	
	public:
		
//		       --------------------------------------------------------------------------
//								Declaration of Admin related Functions
//		       --------------------------------------------------------------------------

//		Functions to add Admin
		void addAdmin();

//		Functions to remove Admin
		void deleteAdmin();
		
//		Function to edit Admin profile
		void editAdminProfile();
		
//		Function for admin to login
		bool adminLogin();
//		Function to Disaply Admin logout screen
		void adminLogout();
		
//		Function to check if admin ID already Exist.... used while adding new Admin
		bool checkDuplicateAdminID(int id);

		
//				---------------------------------------------------------------------
//							Declaration of User Related Functions
//				---------------------------------------------------------------------


//		Function to add User
		void addUser();
		
//		Function to Edit User Profile
		void editUserProfile();
		
//		Function for User to verify and login
		bool userLogin();
		
//		Function to Display Logout Screen
		void userLogout();
		
//		Function to check if User ID already Exist.... used while Signing up new Admin
		bool checkDuplicateUserID(int id);
		
		int mID;
		char mName[NAME_SIZE];



//				---------------------------------------------------------------------
//							Declaration of Recipe Related Functions
//				---------------------------------------------------------------------
//		Function to add Recipe
		void addRecipe();
		
//		function to delelete Recipe
		void deleteRecipe();
		
//		Function to print the list of Recipes Names
		void printRecipesList();
		
//		Function to print a Recipe
		void printRecipe(Recipe & recipe);
		
//		Function to Search Recipe By Entering Ingredients (main module)
		void searchRecipeByIngredients();
		
//		Function To Search Recipe By Name
		void searchRecipeByName();
		
//		Function to Dsplay the Result of main Module
		void printSearchByIngredientsResult(vector <Recipe>& tmpRec);
		
//		Function to Display login screen
		void loginScreen();

//				---------------------------------------------------------------------
//							Declaration of File Handling Functions
//				---------------------------------------------------------------------

		
//		Function to add admins to file
		void writeAdminToFile(Admin &tmpAdmin);
		
//		Function to read admins from file
		void readAdminFromFile();
		
//		Function to add users to file
		void writeUserToFile(User &tmpUser);
		
//		Function to read users from file
		void readUsersFromFile();
		
//		Function to add Recipe to file
		void writeRecipeToFile(Recipe& newRecipe);
		
//		Function to read Recipe from file
		void readRecipeFromFile();
		
		void writeAdminsTransactions(char* recName)
		{
			fstream	fileHandler(ADMINS_TRANSACTIONS_FILE, ios::in| ios::out| ios:: app);
			fileHandler << "Admin : "<< mName <<" ID : "<< mID << " added Recipe of "<< recName<<endl; 
			fileHandler.close();
		}
		
		void writeUsersTransactions(vector <Recipe>& tmpRec, vector <string>& tmpIng)
		{
			fstream fileHandler(USERS_TRANSACTIONS_FILE, ios::in| ios::out| ios::binary| ios::app);
			fileHandler << "User : "<< mName <<" ID : "<< mID << " Entered Ingredients ";
			for(string st : tmpIng)
			{
				fileHandler << st << ", ";
			}
			fileHandler << "and was recommended ";
			for(Recipe & rec : tmpRec)
			{
				fileHandler << rec.getName() << ", ";
			}
			fileHandler<<endl;
		}
		
//					Function to check if a file has already been created

		bool checkFileExist(string fileName)
		{
			ifstream infile(fileName);
			return infile.good();
		}
	~RecipeGenerator() {}
};  

//		       --------------------------------------------------------------------------
//								Definitton of Admin related Functions
//		       --------------------------------------------------------------------------

void RecipeGenerator:: addAdmin()
{
	bool check=true;
	int ID;
	char name[NAME_SIZE];
	char password[STRINGS_SIZE];
	ifstream infile(ADMIN_FILE);
	if(infile.good()==false)
	{	
		cout<<"\n\n\t\t\tFor the first time Run\n\t\t\tEnter Data of your Manager (only he can add or remove more Admins)\n\n\n";
	}
	else
	{
		if(admins[0].getID()!=mID)
		{
			cout<<"\nYou are not Manager ";
			pressKey();
			clearScreen();
			return;
		}
		else
		cout<<"\nEnter Data of the admin\n"	;
	}
	
	while(check==true)
	{
		cout<<"\nEnter ID of the admin (Numbers only) : ";
		cin>>ID;
		cin.ignore();
		if(invalidIntegerInputCheck(ID)==true)
		{
			if(checkDuplicateAdminID(ID)==true)
			{
				int label;
				cout<<"\nEnter Name: ";
				cin.getline(name,NAME_SIZE);
				invalidCharCheck(name);
				cout<<"\nEnter Password: ";
				cin.getline(password,STRINGS_SIZE);
			    Admin admin(ID,name, password);
			    if(infile.good()==false)
				{	
					cout<<"\nAdministrator Registered Succesfully....You're Welcome to the program\n";
					writeAdminToFile(admin);
				}
	    		else
	    		{
	    			cout<<"\nAdmin Registered Succesfully....\n";
	    			admins.push_back(admin);
	    			writeAdminToFile(admin);
				}
				check=false;
				pressKey();
				clearScreen();
			}
			else	{cout<<"\nAdmin Id already Exists... Enter a unique ID";pressKey();clearScreen();check=false;}
		}
	}
}

//		           ------------------------------------------------------------------------------
//								Definition of Function to delete admin profile
void RecipeGenerator:: deleteAdmin()
{
	if(admins[0].getID()!=mID)
	{
		cout<<"\nYou are not Manager ";
		pressKey();
		clearScreen();
		return;
	}
	if(admins.size()==1)
	{
		cout<<"\nManger hasn't added any admins yet";
		pressKey(); clearScreen();
		return;
	}
	else
	{
		int checkID=0, ID;
		cout<<"\n\n"<<" ID\t Name\n ---\t ----\n ";
		for(int i=1; i<admins.size(); i++)
		{
			cout<<admins[i].getID()<<"\t"<<admins[i].getName()<<"\n ";
		}
		cout<<"\nEnter ID of the admin you want to delete : ";
		cin>>ID;
		cin.ignore();
		if(invalidIntegerInputCheck(ID)==true)
		{
			if(ID==admins[0].getID())
			{
				cout<<"\nManager cannot be deleted";
				pressKey(); clearScreen();
				return;
			}
			else
			{
				for(int i=0;i<admins.size();i++)
				{
					if(admins[i].getID()==ID)
					{
						admins.erase(admins.begin()+i);
						cout<<"\nAdmin Removed";
						pressKey(); clearScreen();
						checkID++;
						break;
					}
				}
				if (checkID==0){cout<<"\nThere's no Admin ID "<<ID; pressKey();clearScreen();
				}
				else
				{
					fstream adminFileHandler(ADMIN_FILE, ios::in |ios::out |ios::binary|ios::trunc);
					adminFileHandler.write(reinterpret_cast<char*>(admins.data()),admins.size()* sizeof(Admin));
					adminFileHandler.close();
				}
			}
		}
	}
}

//		           -------------------------------------------------------------------------
//								Definition of Function to edit admin profile
void RecipeGenerator:: editAdminProfile()
{
	fstream adminFileHandler(ADMIN_FILE, ios::in |ios::out |ios::binary);
	int passcheck=0, ID;
	char name[NAME_SIZE];
	char password[STRINGS_SIZE];
	while(!adminFileHandler.eof())
	{
		Admin admin;
		adminFileHandler.read(reinterpret_cast<char*>(&admin), sizeof(Admin));
		if(admin.getID()==mID)
		{
			cout<<"\nEnter your Current password : ";
			cin.getline(password,STRINGS_SIZE);
			if(strcmp(admin.getPassword(),password)==0)
			{
    			cout<<"\nEnter New Name : ";
				cin.getline(name,NAME_SIZE); 
				invalidCharCheck(name);
				cout<<"\nEnter New Password : ";
				cin.getline(password,STRINGS_SIZE);
				admin.setName(name);
				admin.setPassword(password);
				cout<<"\nProfile Updated Successfully";
				adminFileHandler.seekp(-(sizeof(Admin)), ios::cur);
				adminFileHandler.write(reinterpret_cast<char*>(&admin), sizeof(Admin));
				adminFileHandler.close();
				pressKey();
				clearScreen();
				passcheck++;
				admins.clear();
				readAdminFromFile();
				break;
			}
			else
				break;
		}
	}
	if (passcheck ==0 )	{	cout<<"\nInvalid password "; pressKey();clearScreen();}
}

//				Definiton of Admin Login function
bool RecipeGenerator:: adminLogin()
{
	readAdminFromFile();
	int chkID=0,chkpass=0;
	bool check=true;
	int ID;
	char password[STRINGS_SIZE];
	cout<<"\n\nEnter your ID : ";
	cin>>ID;
	cin.ignore();
	if(invalidIntegerInputCheck(ID)==true)
	{
		mID=ID;
		cout<<"\nEnter Your Password : ";
		cin.getline(password,STRINGS_SIZE );
		for( Admin& ad : admins)
		{
			if(ad.getID()==ID)
			{
				chkID++;
				if(strcmp(ad.getPassword(), password)==0)
				{
					clearScreen();
					cout<<"\n\n\n\t\t\t\t\tWelcome : ";ad.displayInfo();
					strcpy(mName, ad.getName());
					return true;
					break;
				}
				else
				{
					chkpass++;
				}
			}
		}
		if(chkID==0)	{cout<<"\nThere's no ID "<<ID;}
		if(chkpass!=0)	{cout<<"\nincorrect password ";}
		pressKey();
		clearScreen();
		return false;
	}
	return false;
}
//				definiton of Admin Logout function
void RecipeGenerator:: adminLogout()
{
	cout << "\n\n\n\t\t\t\t\t| Loging Out |\n\t\t\t\t\t";
    for (int a = 1; a < 6; a++) {
        Sleep(200);
        cout << "...";
    }
    admins.clear();
    recipes.clear();
}

//			defintition of function to check duplicate Admin ID
bool RecipeGenerator:: checkDuplicateAdminID(int id)
{
	if(checkFileExist(ADMIN_FILE)==false)
	{
		return true;
	}
	else{
		for(int i=0; i<admins.size();i++)
		{
			if(admins[i].getID()==id)
			{
				return false;
			}
		}
	}
	return true;
}		
//		       --------------------------------------------------------------------------
//								Definition of Users related Functions
//		       --------------------------------------------------------------------------

void RecipeGenerator:: addUser()
{
	cout<<"\nEnter Data of the User \n";
	int ID;
	char name[NAME_SIZE];
	char password[STRINGS_SIZE];
	cout<<"\nEnter Id  : ";
	cin>>ID;
	cin.ignore();
	if(invalidIntegerInputCheck(ID)==true)
	{
		if(checkDuplicateUserID(ID)==false)
		{
			cout<<"\nEnter Name: ";
			cin.getline(name,NAME_SIZE);
			invalidCharCheck(name);
			cout<<"\nEnter Password: ";
			cin.getline(password,STRINGS_SIZE);
		    User user(ID,name, password);
		    cout<<"\nAccount Created Successfully";
		    writeUserToFile(user);
			clearScreen();
		}
		else {cout<<"\nUser Id "<<ID << " Already Exist.... Enter a unique one";pressKey(); clearScreen();}
	}
}

//					--------------------------------------------------------------
//							definiton of Function to edit user profile
void RecipeGenerator:: editUserProfile()
{
	fstream userFileHandler(USERS_FILE, ios::in |ios::out |ios::binary);
	int passcheck=0, ID;
	char name[NAME_SIZE];
	char password[STRINGS_SIZE];
	while(!userFileHandler.eof())
	{
		User user;
		userFileHandler.read(reinterpret_cast<char*>(&user), sizeof(User));
		if(user.getID()==mID)
		{
			cout<<"\nEnter your Current password : ";
			cin.getline(password,STRINGS_SIZE);
			if(strcmp(user.getPassword(),password)==0)
			{
    			cout<<"\nEnter New Name : ";
				cin.getline(name,NAME_SIZE);
				invalidCharCheck(name); 
				cout<<"\nEnter New Password : ";
				cin.getline(password,STRINGS_SIZE);
				user.setName(name);
				user.setPassword(password);
				cout<<"\nProfile Updated Successfully";
				userFileHandler.seekp(-(sizeof(User)), ios::cur);
				userFileHandler.write(reinterpret_cast<char*>(&user), sizeof(User));
				userFileHandler.close();
				pressKey();
				clearScreen();
				passcheck++;
				users.clear();
				readUsersFromFile();
				break;
			}
			break;
		}
	}
	if (passcheck ==0 )	{	cout<<"\nInvalid password "; pressKey();clearScreen();}
}
//					Defintion of User Login function		
bool RecipeGenerator:: userLogin()
{
	readUsersFromFile();
	int ID, chkID = 0, chkpass = 0;
	char password[STRINGS_SIZE];
	if(users.size()==0)
	{
		cout<<"\nThere is no current User Account\n";
		pressKey();
		return false;
	}
	else
	{
		cout<<"\n\nEnter Your ID : ";
		cin>>ID;
		cin.ignore();
		if(invalidIntegerInputCheck(ID)==true)
		{
			mID=ID;
			cout<<"\nEnter Your Password : ";
			cin>>password;
			for(User & us :users)
			{
				if(us.getID() == ID)
				{
					chkID++;
					if(strcmp(us.getPassword(), password) == 0)
					{
						clearScreen();
						cout<<"\nWelcome : "; us.displayInfo(); pressKey();
						strcpy(mName, us.getName());
						users.clear();
						return true;
						break;
					}
					else
					{
						chkpass++;
					}
				}
			}
			if(chkID==0)	{cout<<"\nThere's no  User ID "<< ID;}
			if(chkpass!=0)		{cout<<"\nincorrect password "<<endl;}
			pressKey();
			clearScreen();
			return false;
		}
		return false;
	}
}
void RecipeGenerator:: userLogout()
{
	cout << "\n\n\n\t\t\t\t\t| Loging Out |\n\t\t\t\t\t";
    for (int a = 1; a < 6; a++) {
        Sleep(200);
        cout << "...";
    }
    users.clear();
    recipes.clear();
}
bool RecipeGenerator:: checkDuplicateUserID(int id)
{
	for(int i=0; i<users.size(); i++)
	{
		if(users[i].getID()==id)
		{
			return true;
		}
	}
	return false;
}

//		       --------------------------------------------------------------------------
//								Definition of Recipe related Functions
//		       --------------------------------------------------------------------------
void RecipeGenerator:: addRecipe()
{
	int i=0;
	string choice;
	char name[NAME_SIZE] ;
	char category[STRINGS_SIZE];
	vector <IngredientUsage*> recipeIngredients;
	vector <string> cookingSteps;
	cout<<"\nEnter Name of the Recipe : ";
	cin.getline(name, NAME_SIZE);
	invalidCharCheck(name);
	
	Recipe newRecipe(name);
	
	cout<<"\nEnter All the ingredients of Recipe.... Enter \"END\" when you're done\n";
	while(choice!="END"&&choice!="end")
	{
		cout << "\n\t\t\tEnter Ingredient " << (i + 1) << "\n\n";	
		char ingredientName[NAME_SIZE];
        
        char quantity[10];
        char state[STRINGS_SIZE];
        
		cout<<"\nEnter Ingredient Name : ";
		cin.getline(ingredientName, NAME_SIZE);
		invalidCharCheck(ingredientName);
		
		Ingredient* recIngredient = myIG.findIngredient(ingredientName);
		if (recIngredient==nullptr)
		{
			char ingredientCategory[STRINGS_SIZE];
        	char nutritionalInformation[INFORMATION_SIZE];
			cout<<"\nEnter Category of the Ingredient (e.g meats, vegetables) : ";
			cin.getline(ingredientCategory, STRINGS_SIZE);
			invalidCharCheck(ingredientCategory);
			cout<<"\nEnter Nutritional Information of the Ingredient : ";
			cin.getline(nutritionalInformation, INFORMATION_SIZE);
			Ingredient newIngredient(ingredientName, ingredientCategory, nutritionalInformation);
			myIG.writeIngredientToFile(newIngredient);
			recIngredient = myIG.findIngredient(ingredientName);
		}
		cout<<"\nEnter Quantity (e.g 50g, 1kg) : ";
		cin.getline(quantity, NAME_SIZE);
		IngredientUsage usage(recIngredient, quantity);
		newRecipe.addIngredientUsage(usage);
		cout<<"\n\nIngredient added.. Enter \"END\" to end or \"add\" to add more : ";
		cin>>choice;
		cin.ignore();
		i++;
	}
	choice = "add";
	i = 0;
	cout<<"\n\nEnter Cooking steps of Recipe.... Enter \"END\" when you're done\n\n";
	
	while(choice!="END"&&choice!="end")
	{
		string step;
        cout << "\nEnter step " << (i + 1) << " : ";
        getline(cin, step);
        newRecipe.addCookingStep(step);
        i++;
        cout<<"\nStep added.. Enter \"END\" or add : ";
        cin>>choice;
        cin.ignore();
	}
	cout<<"\n Recipe added "; pressKey(); clearScreen();
	recipes.push_back(newRecipe);
	writeRecipeToFile(newRecipe);
	writeAdminsTransactions(name);
}

//			Definition of function to delete Recipe
void RecipeGenerator:: deleteRecipe()
{
	if(recipes.size() == 0)
	{
		cout<<"\nNo Recipes in Database";
		pressKey();clearScreen();
		return;
	}
	printRecipesList();
	int checkName=0;
	char recName[NAME_SIZE];
	cout<<"\nEnter Name of the recipe You want to delete : ";
	cin.getline(recName, NAME_SIZE);
	invalidCharCheck(recName);
	
	for(int i =0 ; i < recipes.size(); i++)
	{
		if(strcmp(recName, recipes[i].getName())==0)
		{
			recipes.erase(recipes.begin()+i);
			cout<<"\nRecipe Deleted";
			pressKey(); clearScreen();
			checkName++;
			break;
		}
	}
	if(checkName==0) {cout<<"\nThere is no Recipe named "<<recName; pressKey(); clearScreen();}
	else
	{
		remove(RECIPES_FILE.c_str());
        for (Recipe &rec : recipes)
        {
            writeRecipeToFile(rec);
        }
	}
}
//		Definiton of Function to Print Recipe list
void RecipeGenerator:: printRecipesList()
{
	if(recipes.size() == 0)
	{
		cout<<"\nNo Recipes in Database";
		pressKey();clearScreen();
		return;
	}
	clearScreen();
	int i=1;
	cout<<"\nHere's the list of current Recipes in the Database\n\n";
	for(Recipe & rec : recipes)
	{
		cout<< i <<". "<<rec.getName() << endl;
		i++;
	}
	pressKey(); clearScreen();
}

void RecipeGenerator:: printRecipe(Recipe & recipe)
{
		cout << "Recipe Name: " << recipe.getName() << endl;

	    // Print the ingredients
	    cout << "Ingredients:" << endl;
	    const vector<IngredientUsage>& ingredients = recipe.getIngredients();
	    int i=0;
	    for (auto & ing : ingredients)
	    {
//			        const IngredientUsage& usage = ingredients[i];
	        cout << "\t" << (i + 1) << ". " << ing.getIngredient()->getName()
	             << " (" << ing.getQuantity() << ") " << endl;
	             i++;
	    }
	i=0;
	    // Print the cooking steps
	    cout << "Cooking Steps:" << endl;
	    const vector<string>& steps = recipe.getCookingSteps();
	    for (auto & step : steps)
	    {
	        cout << "\t" << (i + 1) << ". " << steps[i] << endl;
	        i++;
	    }
	     
    pressKey(); clearScreen();
}

//			Definitoin of Fucntion to search Recipe By Ingredients		
void RecipeGenerator:: searchRecipeByIngredients()
{
	if(recipes.size() == 0)
	{
		cout<<"\nNo Recipes in Database";
		pressKey();clearScreen();
		return;
	}
	int choice=2 , i = 1;
	vector <string> userIngredients;
	vector <Recipe> selectedRecipes;
	
	cout<<"\nEnter the Ingrediets You've got (atleast 3) ";
	while(choice != 0)
	{
		char name[NAME_SIZE];
		label :
		cout<<"Enter Ingredient "<< i <<" : ";
		cin.getline(name, NAME_SIZE);
		if(invalidCharCheck(name)==0)	goto label;
		
		bool chkName = false;
		if(userIngredients.size() > 0)
		{
			for(string & ing : userIngredients)
			{
				if(name == ing)
				{
					chkName = true;
					break;
				}
			}
			if(chkName==true){cout<<"\nAlready Entered.... Enter a different ingredient\n";goto label;}
		}
		userIngredients.push_back(name);
		
		if(i>=3){cout<<"Enter 1 to add more and 0 to search : "; cin>>choice; cin.ignore();}
		
		i++;
	}
	
	for(int i=0; i<recipes.size(); i++)
	{
		int leastMatch = 0;
	    const vector<IngredientUsage>& ingredients = recipes[i].getIngredients();
		
		for(int j=0; j<userIngredients.size(); j++)
		{
			for(int k=0; k<ingredients.size(); k++)
			{
				if(strcmp(ingredients[k].getIngredient()->getName(), userIngredients[j].c_str())==0)
				{
					leastMatch++;
					break;
				}
			}
			if (leastMatch >= 3)
			{
				selectedRecipes.push_back(recipes[i]);
				break;
			}
		}
			 
	}
	printSearchByIngredientsResult(selectedRecipes);
	writeUsersTransactions(selectedRecipes, userIngredients);
}
		
//			Definitoin of Fucntion to search Recipe By Name		
void RecipeGenerator:: searchRecipeByName()
{
	if(recipes.size() == 0)
	{
		cout<<"\nNo Recipes in Database";
		pressKey();clearScreen();
		return;
	}
	char name[NAME_SIZE];
	int chkName = 0;
	cout<<"\nEnter the name of Recipe : ";
	cin.getline(name, NAME_SIZE);
	invalidCharCheck(name);
	for(Recipe & rec : recipes)
	{
		if(strcmp(name, rec.getName())==0)
		{
			chkName++;
			printRecipe(rec);
			break;
		}
	}
	if(chkName == 0) {cout<<"\nNo Recipe of "<<name<<" in the DataBase"; pressKey(); clearScreen();}
}

//			Definitoin of Fucntion to print search Recipe By Ingredients Result		
void RecipeGenerator:: printSearchByIngredientsResult(vector <Recipe>& tmpRec)
{
	if(tmpRec.size()==0)
	{
		cout<<"\nNo Recipe in the Database matches the ingredients you entered";
		pressKey(); clearScreen();
	}
	else if(tmpRec.size()==1)
	{
		cout<<"\nWith These ingredients, You can make this Recipe\n\n";
		printRecipe(tmpRec[0]);
	}
	else
	{
		int choice = 100;
		while(choice!=0)
		{
			char name[NAME_SIZE];
			cout<<"\nWith These ingredients, You can make:\n\n";
			int i=1;	
			for(Recipe & rec : tmpRec)
			{
				cout<< i <<". " <<rec.getName()<<endl;
				i++;
			}
			cout<<"\nEnter the Number of Recipe you want to see details of or 0 to Exit: ";
			cin>>choice;
			cin.ignore();
			if(invalidIntegerInputCheck(choice)==true)
			{
				for(int i=0; i< tmpRec.size(); i++)
				{
					if(choice==i+1)
					{
						printRecipe(tmpRec[i]);
					}
				}
			}
			if(choice>tmpRec.size()){cout<<"Enter Correct Number"; pressKey(); clearScreen();}
		}
		pressKey(); clearScreen();
	}
}

//		       --------------------------------------------------------------------------
//								Definition of file Handling Functions
//		       --------------------------------------------------------------------------
		
void RecipeGenerator:: writeAdminToFile(Admin &tmpAdmin)
{
	fstream adminFileHandler(ADMIN_FILE, ios::in |ios::app |ios::binary);
	if(!adminFileHandler.is_open())
	{
		cout<<"Admin file wasn't opened";
		return;
	}
	adminFileHandler.write(reinterpret_cast<char*>(&tmpAdmin),sizeof(Admin));
	adminFileHandler.close();
}

void RecipeGenerator:: readAdminFromFile()
{
	fstream adminFileHandler(ADMIN_FILE, ios::out |ios::in |ios::binary);
	if(!adminFileHandler.is_open())
	{
		cout<<"Admin file wasn't opened";
		return;
	}
	while(!adminFileHandler.eof())
	{
		Admin admin; 
		adminFileHandler.read(reinterpret_cast<char*>(&admin), sizeof(Admin));
		admins.push_back(admin);
	}
	admins.pop_back();
	adminFileHandler.close();
}
		
		
//			Definiotn of Function to add users to file

void RecipeGenerator:: writeUserToFile(User &tmpUser)
{
	fstream userFileHandler(USERS_FILE, ios::in |ios::app |ios::binary);
	if(!userFileHandler.is_open())
	{
		cout<<"\nUsers file wasn't opened";
		return;
	}
	userFileHandler.write(reinterpret_cast<char*>(&tmpUser),sizeof(User));
	userFileHandler.close();
}
		
//				Defintion of Function to read Users from file

void RecipeGenerator:: readUsersFromFile()
{
	fstream userFileHandler(USERS_FILE, ios::out |ios::in |ios::binary);
	if(!userFileHandler.is_open())
	{
		cout<<"\nUsers file wasn't opened";
		return;
	}
	while(!userFileHandler.eof())
	{
		User user;
		userFileHandler.read(reinterpret_cast<char*>(&user), sizeof(User));
		users.push_back(user);
	}
	users.pop_back();
	userFileHandler.close();
}
		
//			definiton of Function to add Recipe to file
		
void RecipeGenerator:: writeRecipeToFile(Recipe& newRecipe)
{
	if(!checkFileExist(RECIPES_FILE))
	{
	    fstream recipeFileHandler(RECIPES_FILE, ios::in | ios::out | ios::app );
	    if (!recipeFileHandler.is_open()) {
	        cerr << "\nUnable to open Recipes file" << endl;
    	}
    	recipeFileHandler << 0 << endl;
    	recipeFileHandler.close();
    }
    fstream recipeFileHandler(RECIPES_FILE, ios::in | ios::out );
	if (!recipeFileHandler.is_open()) {
	    cerr << "\nUnable to open Recipes file" << endl;
    }
	int totalRecipes;
    recipeFileHandler.seekp(0, ios::beg);
    recipeFileHandler>>totalRecipes;
    recipeFileHandler.ignore();
    ++totalRecipes;
    recipeFileHandler.seekp(0, ios::beg);
    recipeFileHandler << totalRecipes << endl;
    recipeFileHandler.seekp(0, ios::end);
   
    recipeFileHandler << newRecipe.getName() << endl;

    const auto& ingredients = newRecipe.getIngredients();
    recipeFileHandler << ingredients.size() << endl;
    for (const auto& usage : ingredients) {
        recipeFileHandler << usage.getIngredient()->getName() << ","
                << usage.getQuantity() << endl;
    }

    const auto& steps = newRecipe.getCookingSteps();
    recipeFileHandler << steps.size() << endl;
    for (const auto& step : steps) {
        recipeFileHandler << step << endl;
    }
    
    recipeFileHandler.close();
}
		
void RecipeGenerator:: readRecipeFromFile()
{
	fstream recipeFileHandler(RECIPES_FILE, ios::in);
	if (!recipeFileHandler.is_open())
	{
	    cout << "\nUnable to open Recipe File" << endl;
	    return;
	}
	int totalRecipes;
    recipeFileHandler>>totalRecipes;
    recipeFileHandler.ignore();
    for(int x=0; x<totalRecipes; x++)
	{
		Recipe recipe;
		string line;
		int totalIngredients, totalSteps;
		getline(recipeFileHandler, line);
		recipe.setName(line.c_str());
		recipeFileHandler >> totalIngredients;
		recipeFileHandler.ignore();
		
		for(int i=0; i<totalIngredients; i++)
		{
			getline(recipeFileHandler, line);
			stringstream ss(line);
			
			string ingredientName;
			string quantity;
			getline(ss,ingredientName, ',' );
			getline(ss,quantity );
			
			Ingredient* ingredient = new Ingredient();
		    ingredient->setName(ingredientName.c_str());
		
		    IngredientUsage usage;
		    usage.setIngredient(ingredient);
		    usage.setQuantity(quantity.c_str());
		
		    recipe.addIngredientUsage(usage);
		    
		}
		recipeFileHandler >> totalSteps;
		recipeFileHandler.ignore();
		for(int i=0 ; i< totalSteps; i++)
		{
			getline(recipeFileHandler, line);
			recipe.addCookingStep(line);
		}
		recipes.push_back(recipe);
	}
	recipeFileHandler.close();
}

void RecipeGenerator:: loginScreen()
{
	char a = 177, b = 219;
	cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t     | Loging In |\n\n\t\t\t\t\t\t";
	for (int x = 1; x < 26; x++) {
        cout << a;
    }
    cout<<"\r\t\t\t\t\t\t";
    for (int x = 1; x < 26; x++) {
        Sleep(150);
        cout << b;
    }
    clearScreen();
}

//		       --------------------------------------------------------------------------
//											main()........
//		       --------------------------------------------------------------------------

int main()
{
	
	IngredientsDatabase myIngredientDatabase;
	RecipeGenerator myRecipeGenerator;
	
	displayInterface();
//		Administrator
	if(myRecipeGenerator.checkFileExist(ADMIN_FILE)==false) myRecipeGenerator.addAdmin();
	int choice;
	bool check = true;
	while(true)
	{
		cout<<"\n\t\t\t\t1. Enter as Admin\n";
		cout<<"\t\t\t\t2. Enter as User\n";
		cout<<"\t\t\t\t3. Exit\n";
		cout<<"Enter your choice : ";
		cin>>choice;
		cin.ignore();
//		check = invalidIntegerInputCheck(choice);
		if(invalidIntegerInputCheck(choice)==true)
		{
			switch(choice)
			{
				//main case 1................. Admin
				case 1:
					{
						check = myRecipeGenerator.adminLogin();
						if(check == true)
						{
							if(myRecipeGenerator.checkFileExist(INGREDIENTS_FILE)==true)
								myIngredientDatabase.readIngredientsFromFile();
							if(myRecipeGenerator.checkFileExist(RECIPES_FILE)==true)	
								myRecipeGenerator.readRecipeFromFile();
							myRecipeGenerator.loginScreen();
							int choice;
							while(check==true)
							{
								cout<<"\n\t\t\t\t      ***** Admin Menu *****\n\n";
								cout<<"\n\t\t\t\t1. Ingredients Menu\n";
								cout<<"\t\t\t\t2. Recipes Menu\n";
								cout<<"\t\t\t\t3. Edit Profile\n";
								cout<<"\t\t\t\t4. Add a New admin\n";
								cout<<"\t\t\t\t5. Remove admin\n";
								cout<<"\t\t\t\t6. Logout\n";
								cout<<"Enter Your Choice : ";
								cin>>choice;
								cin.ignore();
								if(invalidIntegerInputCheck(choice)==true)
								{
									switch (choice)
									{
										case 1:
											{
												bool loopBreak= true;
												while(loopBreak)
												{
													clearScreen();
													cout<<"\n\t\t\t\t      ***** Ingredients Menu *****\n\n";
													cout<<"\n\t\t\t\t1. See Ingredients list\n";
													cout<<"\t\t\t\t2. Search Ingrdient\n";
													cout<<"\t\t\t\t3. Add Ingredient\n";
													cout<<"\t\t\t\t4. Delete Ingrdeint\n";
													cout<<"\t\t\t\t5. Edit Ingredient\n";
													cout<<"\t\t\t\t6. Return Back\n";
													cout<<"Enter Your Choice : ";
													cin>>choice;
													cin.ignore();
													if(invalidIntegerInputCheck(choice)==true)
													{
														switch (choice)
														{
															case 1:
																{
																	myIngredientDatabase.displayIngredientsList();
																	break;
																}
															case 2:
																{
																	myIngredientDatabase.searchIngredient();
																	break;
																}
															case 3:
																{
																	myIngredientDatabase.addIngredient();
																	break;
																}
															case 4:
																{
																	myIngredientDatabase.deleteIngredient();
																	break;
																}
															case 5:
																{
																	myIngredientDatabase.editIngredient();
																	break;
																}
															case 6:
																{
																	loopBreak= false;
																	clearScreen();
																	break;
																}
															default:
																{
																	cout<<"Invalid input:";
																	pressKey();
																	clearScreen();
																	break;
																}
														}
													}
												}
												break;
											}
										case 2:
											{
												bool loopBreak= true;
												while(loopBreak)
												{
													clearScreen();
													cout<<"\n\t\t\t\t      ***** Recipes Menu *****\n\n";
													cout<<"\n\t\t\t\t1. See Current Recipes List\n";
													cout<<"\t\t\t\t2. Search Recipe\n";
													cout<<"\t\t\t\t3. Add Recipe\n";
													cout<<"\t\t\t\t4. Delete Recipe\n";
													cout<<"\t\t\t\t5. Return Back\n";
													cout<<"Enter Your Choice : ";
													cin>>choice;
													cin.ignore();
													if(invalidIntegerInputCheck(choice)==true)
													{
														switch (choice)
														{
															case 1:
																{
																	myRecipeGenerator.printRecipesList();
																	break;
																}
															case 2:
																{
																	myRecipeGenerator.searchRecipeByName();
																	break;
																}
															case 3:
																{
																	myRecipeGenerator.addRecipe();
																	break;
																}
															case 4:
																{
																	myRecipeGenerator.deleteRecipe();
																	break;
																}
															case 5:
																{
																	loopBreak = false;
																	clearScreen();
																	break;
																}
															default:
																{
																	cout<<"Invalid input:";
																	pressKey();
																	clearScreen();
																	break;
																}
														}
													}
												}
												break;
											}
										case 3:
											{
												myRecipeGenerator.editAdminProfile();
												break;
											}
										case 4:
											{
												myRecipeGenerator.addAdmin();
												break;
											}
										case 5:
											{
												myRecipeGenerator.deleteAdmin();
												break;
											}
										case 6:
											{
												myRecipeGenerator.adminLogout();
												clearScreen();
												check=false;
												break;
											}
										default:
										{
											cout<<"Invalid input:";
											pressKey();
											clearScreen();
											break;
										}
									}
								}
							}
						}
						break;
					}
				//main case 2................. User
				case 2:
					{
						bool loopBreak = true;
						while(loopBreak == true)
						{
							clearScreen();
							cout<<"\n\t\t\t\t1. Login\n";
							cout<<"\t\t\t\t2. SignUp\n";
							cout<<"\t\t\t\t3. Return back\n";
							cout<<"Enter your choice : ";
							cin>>choice;
							cin.ignore();
							if(invalidIntegerInputCheck(choice)==true)
							{
								switch(choice)
								{
									case 1:
										{
											check = myRecipeGenerator.userLogin();
											if (check == true)
											{
												if(myRecipeGenerator.checkFileExist(RECIPES_FILE)==true)
													myRecipeGenerator.readRecipeFromFile();
												bool loopBreak = true;
												while (loopBreak == true)
												{
													clearScreen();
													cout<<"\n\t\t\t\t      ***** User Menu *****\n\n";
													cout<<"\n\t\t\t\t1. Search Recipe By Ingrdients\n";
													cout<<"\t\t\t\t2.     Search Recipe By Name\n";
													cout<<"\t\t\t\t3.         Edit profile\n";
													cout<<"\t\t\t\t4.            Logout\n";
													cout<<"Enter your choice : ";
													cin>> choice;
													cin.ignore();
													if(invalidIntegerInputCheck(choice)==true)
													{
														switch(choice)
														{
															case 1:
															   {
															   		myRecipeGenerator.searchRecipeByIngredients();
															   		break;
															   }
															case 2:
															   {
															   		myRecipeGenerator.searchRecipeByName();
															   		break;
															   }
															case 3:
															   {
															   		myRecipeGenerator.editUserProfile();
																	break;
															   }
															case 4:
															   {
															   	myRecipeGenerator.userLogout();
															   	loopBreak = false;
															   	break;
															   }
															default:
																{
																	cout<<"Invalid input:";
																	pressKey();
																	clearScreen();
																	break;
																}
														}
													}
												}
											}
											break;
										}
									case 2:
										{
											clearScreen();
											myRecipeGenerator.addUser();
											break;
										}
									case 3:
										{
											clearScreen();
											loopBreak = false;
											break;
										}
									default:
										{
											cout<<"Invalid input:";
											pressKey();
											clearScreen();
											break;
										}
								}
							}
						}
						break;
					}
				//main case 3................. exit
				case 3:
					{
						exit(0);
					}
				default:
					{
						cout<<"Invalid input:";
						pressKey();
						clearScreen();
						break;
					}
			}
		}
	}
}
//--------------------------------------------------------------------------------------------------
//						Definition of Frequently Used Basic Functions
//--------------------------------------------------------------------------------------------------						


void displayTitle(){
	cout << "\t\t\t<<<<<<<<<<<---------------Recipe Generator--------------->>>>>>>>>>>>\n\n";
}

void clearScreen()
{
	system("CLS");
	displayTitle();
}

void pressKey() {
	cout << "\n\nPress any key to continue.....";
	getch();
}
// Function to Display First Interafce
void displayInterface()
{
	displayTitle();
	cout<<"Developed By \n\nMuhammad Usama \tSP23_BCS_021 \n\n";
	pressKey();
	clearScreen();
}

bool invalidIntegerInputCheck(int a)
{
	if(cin.fail())
	{
		cout<<"Invalid input:"<<endl;
		clearScreen();
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return false;	
	}
	return true;
}

		// Function to check if Names are empty or null then cpitalize the first letter of everyword
		// and lower all other words
		
char* invalidCharCheck(char* s)
{
	if (s[0]=='\0')
	{
		cout<<"Enter a Name Please\n";
		return 0;
	}

    for(int i=0; s[i] != '\0'; i++)
    {
    	char c = s[i];
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' '))
        {
        	cout<<"Please Enter a Valid Name\n";
            return 0;
        }
    }
    for(int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z') s[i] ^= 32;
	}
	
	s[0] ^= 32;
	for(int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ') s[i+1] ^= 32;
	}
	return s;
}